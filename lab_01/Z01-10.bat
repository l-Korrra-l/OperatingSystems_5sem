@ECHO OFF
CHCP 1251 >NUL
ECHO -- ������ ����������: %*
ECHO -- �������� 1: %1
ECHO -- �������� 2: %2
ECHO -- �������� 3: %3
SET /A C = %1 %3% %2
ECHO ���������: %C%