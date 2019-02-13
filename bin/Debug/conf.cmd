FOR %%i IN (1 2 3) DO (
FOR %%s IN (20 30 50 100 150 200) DO (
FOR %%t IN (30 50 70 100 120) DO (
DSCHeuristicBete.exe %%i %%s %%t 10 1 500 200 5 exemple%%s_%%t_%%i.txt 10
)
)
)