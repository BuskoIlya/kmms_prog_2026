@echo off

::
:: Вид сборки / суффикс в названии каталога сборки
::
:: "Ninja" / "ninja"
:: "Visual Studio 17 2022" / "visual_studio"
::
set BUILD_TYPE=Ninja

set BUILD_SUFFIX=ninja

chcp 1251

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=src

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

cd ..
