@echo off
setlocal
echo ^>>> Creating binary and hex...^>
"C:\ST\STM32CubeCLT_1.19.0\GNU-tools-for-STM32\bin\arm-none-eabi-objcopy.exe" -O binary "%~1" "%~dp0\build\cm7.bin"
"C:\ST\STM32CubeCLT_1.19.0\GNU-tools-for-STM32\bin\arm-none-eabi-objcopy.exe" -O ihex "%~1" "%~dp0\build\cm7.hex"
echo ^>>> ELF size:^>
"C:\ST\STM32CubeCLT_1.19.0\GNU-tools-for-STM32\bin\arm-none-eabi-size.exe" --format=berkeley "%~1"
endlocal