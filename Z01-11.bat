@ECHO OFF
CHCP 1251 >NUL
ECHO -- строка параметров: %*
ECHO -- режим: %1
ECHO -- имя файла: %2
if [%1] == [] if [%2] == [] (
    echo ---+ %0 режим файл
    echo ---++ режим = {создать, удалить}
    echo ---++ файл = имя файла
    goto :exit
)

if [%1] == [удалить] if exist %2 (
    del %2
    echo ---+ файл удален
    goto :exit
) else (
    echo  ---+ %2 файл не найден
    goto :exit
) else if [%1] == [создать] if exist %2 (
    echo  ---+ %2 файл уже существует
    goto :exit
) else (
    echo nul> %2
    echo ---+ создан
    goto :exit
)

:exit