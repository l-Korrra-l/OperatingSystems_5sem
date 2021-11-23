@ECHO OFF
CHCP 1251 >NUL
ECHO -- строка параметров: %*
ECHO -- параметр 1: %1
ECHO -- параметр 2: %2
ECHO -- параметр 3: %3
SET /A C = %1 + %2
ECHO %1 + %2 = %C%
SET /A C = %1 * %2
ECHO %1 * %2 = %C%
SET /A C = %3 / %2
ECHO %3 / %2 = %C%
SET /A C = %2 - %1
ECHO %2 - %1 = %C%
SET /A C = (%2 - %1) * (%1 - %2)
ECHO (%2 - %1) * (%1 - %2) = %C%