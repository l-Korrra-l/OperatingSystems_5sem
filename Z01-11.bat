@ECHO OFF
CHCP 1251 >NUL
ECHO -- ������ ����������: %*
ECHO -- �����: %1
ECHO -- ��� �����: %2
if [%1] == [] if [%2] == [] (
    echo ---+ %0 ����� ����
    echo ---++ ����� = {�������, �������}
    echo ---++ ���� = ��� �����
    goto :exit
)

if [%1] == [�������] if exist %2 (
    del %2
    echo ---+ ���� ������
    goto :exit
) else (
    echo  ---+ %2 ���� �� ������
    goto :exit
) else if [%1] == [�������] if exist %2 (
    echo  ---+ %2 ���� ��� ����������
    goto :exit
) else (
    echo nul> %2
    echo ---+ ������
    goto :exit
)

:exit