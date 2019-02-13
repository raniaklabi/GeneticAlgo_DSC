FOR %%i IN (1 ) DO (
FOR %%s IN (20 ) DO (
FOR %%t IN (30 50) DO (
FOR %%j IN (1 2) DO (
DSCHeuristicBete.exe %%i %%s %%t 10 1 500 200 5 exemple%%s_%%t_%%i_%%j.txt 1
)
)
)
)