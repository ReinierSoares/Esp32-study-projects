# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Reinier/esp/esp-idf/components/bootloader/subproject"
  "G:/Meu Drive/Projetos/ESP32/scan/build/bootloader"
  "G:/Meu Drive/Projetos/ESP32/scan/build/bootloader-prefix"
  "G:/Meu Drive/Projetos/ESP32/scan/build/bootloader-prefix/tmp"
  "G:/Meu Drive/Projetos/ESP32/scan/build/bootloader-prefix/src/bootloader-stamp"
  "G:/Meu Drive/Projetos/ESP32/scan/build/bootloader-prefix/src"
  "G:/Meu Drive/Projetos/ESP32/scan/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "G:/Meu Drive/Projetos/ESP32/scan/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "G:/Meu Drive/Projetos/ESP32/scan/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
