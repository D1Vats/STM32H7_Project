cmake_minimum_required(VERSION 3.20)
project(MyApp LANGUAGES C CXX ASM)

# Avoid trying to build an exe for the host during try_compile when cross-compiling
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY CACHE STRING "")

if(NOT CMAKE_TOOLCHAIN_FILE)
  message(FATAL_ERROR "Please pass -DCMAKE_TOOLCHAIN_FILE=path/to/arm-none-eabi-gcc.cmake")
endif()

# ---------- MCU flags (single source of truth) ----------
set(MCU_FLAGS
  -mcpu=cortex-m7
  -mthumb
  -mfpu=fpv5-d16
  -mfloat-abi=hard
)

set(MCU_DEBUG_FLAGS -g)

set(MCU_COMPILE_OPTIONS ${MCU_FLAGS} ${MCU_DEBUG_FLAGS})

# Apply compile options at directory scope so subdirectories (UDAan_SDK) inherit them.
# This avoids trying to modify an ALIAS target.
add_compile_options(${MCU_COMPILE_OPTIONS})

# ---------- Add SDK ----------
add_subdirectory(UDAan_SDK)  # this may create targets and/or alias targets such as UDAan::SDK

# Optional: debug what target type was created for UDAan::SDK
if(TARGET UDAan::SDK)
  get_target_property(_udaan_type UDAan::SDK TYPE)
  message(STATUS "UDAan::SDK exists, TYPE=${_udaan_type}")
  # If _udaan_type is "ALIAS" you cannot call target_compile_options on it.
endif()

# ---------- App target ----------
add_executable(app
  UDAan_App/main.cpp
  UDAan_App/stm32h7xx_it.c
)

# Common defines
target_compile_definitions(app PRIVATE STM32H747xx CORE_CM7 USE_HAL_DRIVER)

# Also ensure the app target itself has the same compile options (redundant safe-guard)
target_compile_options(app PRIVATE ${MCU_COMPILE_OPTIONS})

# Link options (keep link flags consistent)
target_link_options(app PRIVATE ${MCU_FLAGS} -Wl,--gc-sections -specs=nosys.specs)

# Add HAL sources if SDK exported a variable
if(DEFINED UDAAN_HAL_SRCS)
  target_sources(app PRIVATE ${UDAAN_HAL_SRCS})
endif()

# Utilities that belong to final image
target_sources(app PRIVATE
  UDAan_SDK/utilities/syscalls.c
  UDAan_SDK/utilities/sysmem.c
  UDAan_SDK/utilities/system_stm32h747xx.c
)

# Startup and linker script for CM7 core
target_sources(app PRIVATE UDAan_SDK/utilities/cm7_startup.s)
set_source_files_properties(UDAan_SDK/utilities/cm7_startup.s PROPERTIES LANGUAGE ASM)
target_link_options(app PRIVATE "-T${CMAKE_CURRENT_SOURCE_DIR}/UDAan_SDK/utilities/cm7_linker.ld")

# Include SDK headers (assuming SDK configured PUBLIC include dirs)
target_link_libraries(app PRIVATE UDAan::SDK)

# Output name directory
set_target_properties(app PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  OUTPUT_NAME "cm7"
  SUFFIX ".elf"
)

# --- find correct objcopy/size (adjust HINTS to your toolchain if necessary)
find_program(OBJCOPY NAMES arm-none-eabi-objcopy
  HINTS "C:/ST/STM32CubeCLT_1.19.0/GNU-tools-for-STM32/bin" ENV PATH)
find_program(SIZEPROG NAMES arm-none-eabi-size
  HINTS "C:/ST/STM32CubeCLT_1.19.0/GNU-tools-for-STM32/bin" ENV PATH)

# ---------- Post-build target ----------
if(OBJCOPY AND SIZEPROG)
  find_program(POST_BUILD_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/post_build.bat")

  if(POST_BUILD_SCRIPT)
    add_custom_target(all_postbuild ALL
      COMMAND "${POST_BUILD_SCRIPT}" "$<TARGET_FILE:app>"
      WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
      COMMENT "Generating .bin, .hex, and displaying ELF size"
      VERBATIM
      DEPENDS app
    )

    message(STATUS "To build everything (including post-build): run 'ninja' or 'cmake --build .'")
    message(STATUS "To build just the ELF: run 'ninja app'")
    message(STATUS "To run post-build manually: run 'ninja all_postbuild'")
  else()
    message(WARNING "post_build.bat not found; skipping post-build steps")
  endif()
else()
  message(WARNING "OBJCOPY or SIZEPROG not found; skipping post-build steps")
endif()