@echo off
setlocal EnableDelayedExpansion
::
:: Вид сборки / суффикс в названии каталога сборки
::
:: "Ninja" / "ninja"
:: "Visual Studio 17 2022" / "visual_studio"
::
set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

set arr[0].file=run_bubble_sort.bat
set arr[1].file=run_bubble_sort_mf.bat
set arr[2].file=run_refactoring_and_print.bat
set arr[3].file=run_base_theory_p1.bat
set arr[4].file=run_base_theory_tasks_p1.bat
set arr[5].file=run_obuchaika.bat

set arr[0].folder=bubble_sort
set arr[1].folder=bubble_sort_mf
set arr[2].folder=refactoring_and_print
set arr[3].folder=base_theory_p1
set arr[4].folder=base_theory_tasks_p1
set arr[5].folder=obuchaika

for /L %%i in (0,1,5) do ( 
	copy ..\%SOURCE_FOLDER%\!arr[%%i].folder!\!arr[%%i].file! .\!arr[%%i].folder!
)

copy ..\run_tests.bat .
