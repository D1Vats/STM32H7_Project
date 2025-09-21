cmake_minimum_required(VERSION 3.20)
project(UDAan_SDK LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

# Adjust these to where your HAL/CMSIS installation lives on disk.
set(HAL_ROOT "C:/Users/dwije/STM32H747/hal")
set(CMSIS_ROOT "C:/Users/dwije/STM32H747/cmsis")

set(HAL_INC "${HAL_ROOT}/Inc")
set(HAL_SRC "${HAL_ROOT}/Src")
set(HAL_LEGACY "${HAL_ROOT}/Inc/Legacy")
set(CMSIS_INC "${CMSIS_ROOT}/Include")
set(CMSIS_DEVICE_INC "${CMSIS_ROOT}/Device/ST/STM32H7xx/Include")

if(NOT EXISTS "${HAL_INC}" OR NOT EXISTS "${HAL_SRC}" OR NOT EXISTS "${CMSIS_INC}" OR NOT EXISTS "${CMSIS_DEVICE_INC}")
  message(FATAL_ERROR "HAL or CMSIS directory problems. Check HAL_ROOT/CMSIS_ROOT.")
endif()

# Your wrapper sources only (do NOT include HAL_SRC here for header-only approach)
file(GLOB_RECURSE UDAAN_SDK_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp"
)

if(NOT UDAAN_SDK_SOURCES)
  message(FATAL_ERROR "No SDK sources found in ${CMAKE_CURRENT_SOURCE_DIR}/Source")
endif()

add_library(UDAan_SDK STATIC ${UDAAN_SDK_SOURCES})

# startup objects are not part of the SDK for header-only approach; they belong to the app
# Provide include directories so users get HAL/CMSIS headers
target_include_directories(UDAan_SDK PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
  $<BUILD_INTERFACE:${HAL_INC}>
  $<BUILD_INTERFACE:${HAL_LEGACY}>
  $<BUILD_INTERFACE:${CMSIS_INC}>
  $<BUILD_INTERFACE:${CMSIS_DEVICE_INC}>
)

# We want the SDK user to include USE_HAL_DRIVER automatically
target_compile_definitions(UDAan_SDK PUBLIC USE_HAL_DRIVER)

# C++ standard
target_compile_features(UDAan_SDK PUBLIC c_std_11 cxx_std_20)

# Provide a variable listing HAL sources for the application to compile later
file(GLOB_RECURSE UDAAN_HAL_SRCS "${HAL_SRC}/*.c")
set(UDAAN_HAL_SRCS ${UDAAN_HAL_SRCS} PARENT_SCOPE)

# Provide helpful alias for consumers
add_library(UDAan::SDK ALIAS UDAan_SDK)
