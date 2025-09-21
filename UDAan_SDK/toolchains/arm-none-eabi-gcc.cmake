# toolchain-arm-none-eabi.cmake
# Minimal toolchain file for arm-none-eabi (STM32CubeCLT)
# Adjust paths if your toolchain is installed in a different folder.

# Declare cross-compiling
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Path to the ARM GNU toolchain (adjust if installed elsewhere)
set(ARM_GNU_DIR "C:/ST/STM32CubeCLT_1.19.0/GNU-tools-for-STM32/bin")

# Compilers
set(CMAKE_C_COMPILER   "${ARM_GNU_DIR}/arm-none-eabi-gcc.exe"  CACHE STRING "" FORCE)
set(CMAKE_CXX_COMPILER "${ARM_GNU_DIR}/arm-none-eabi-g++.exe"  CACHE STRING "" FORCE)
set(CMAKE_ASM_COMPILER "${ARM_GNU_DIR}/arm-none-eabi-gcc.exe"  CACHE STRING "" FORCE)

# Tools
set(CMAKE_OBJCOPY  "${ARM_GNU_DIR}/arm-none-eabi-objcopy.exe"  CACHE STRING "" FORCE)
set(CMAKE_OBJDUMP  "${ARM_GNU_DIR}/arm-none-eabi-objdump.exe"  CACHE STRING "" FORCE)
set(CMAKE_AR       "${ARM_GNU_DIR}/arm-none-eabi-ar.exe"      CACHE STRING "" FORCE)
set(CMAKE_RANLIB   "${ARM_GNU_DIR}/arm-none-eabi-ranlib.exe"  CACHE STRING "" FORCE)
set(CMAKE_SIZE     "${ARM_GNU_DIR}/arm-none-eabi-size.exe"    CACHE STRING "" FORCE)

# Prevent CMake from trying to link host executables during try_compile
# (Optional, but avoids the immediate "unrecognized option '--major-image-version'" issue)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Optionally set default flags for the MCU (you can also set them in your top-level CMakeLists

# End of toolchain file
