@echo off

rem clear Res
del /Q Res\pafish.aps>nul 2>nul
echo clear Res Done!

rem clear VS2010&VS2015
for /d %%i in (*) do (
	if "%%i" neq "Res" (
		rmdir /S /Q %%i\.vs>nul 2>nul
		rmdir /S /Q %%i\ipch>nul 2>nul
		
		rem VC6 Only
		rmdir /S /Q %%i\Debug>nul 2>nul
		rmdir /S /Q %%i\Release>nul 2>nul

		rmdir /S /Q %%i\Win32>nul 2>nul
		rmdir /S /Q %%i\x64>nul 2>nul
		del /Q %%i\*.user>nul 2>nul
		del /Q %%i\*.ncb>nul 2>nul
		del /Q /A:H %%i\*.suo>nul 2>nul
		del /Q %%i\*.sdf>nul 2>nul
		del /Q %%i\*.db>nul 2>nul
		
		rem VC6 Only
		del /Q %%i\*.opt>nul 2>nul
		del /Q %%i\*.plg>nul 2>nul
		del /Q %%i\*.positions>nul 2>nul

		rem log files
		del /Q %%i\hi_*>nul 2>nul
		del /Q %%i\*.log>nul 2>nul
		echo clear %%i Done!
	)
)
echo clear All Done!
pause