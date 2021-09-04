@ECHO OFF
CHCP 1251 >NUL
ECHO -- строка параметров: %*
ECHO -- параметр 1: %1
ECHO -- параметр 2: %2
ECHO -- параметр 3: %3
SET /A C = %1 %3% %2
ECHO Результат: %C%