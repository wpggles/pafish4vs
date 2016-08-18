# Microsoft Developer Studio Project File - Name="pafish4vc6" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=pafish4vc6 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "pafish4vc6.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "pafish4vc6.mak" CFG="pafish4vc6 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "pafish4vc6 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "pafish4vc6 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "pafish4vc6 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "pafish4vc6 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "pafish4vc6 - Win32 Release"
# Name "pafish4vc6 - Win32 Debug"
# Begin Group "Res"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\Res\pafish_small.rc
# End Source File
# End Group
# Begin Group "PafishAssembly"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\bochs.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\bochs.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\common.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\common.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\config.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\cpu.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\cpu.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\cuckoo.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\cuckoo.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\debuggers.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\debuggers.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\gensandbox.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\gensandbox.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\hooks.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\hooks.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\qemu.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\qemu.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\sandboxie.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\sandboxie.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\types.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\utils.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\utils.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\vbox.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\vbox.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\vmware.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\vmware.h
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\wine.c
# End Source File
# Begin Source File

SOURCE=..\..\Code\PafishAssembly\wine.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\Code\main.c
# End Source File
# End Target
# End Project
