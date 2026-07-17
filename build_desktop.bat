@echo off
setlocal

set OUT_DIR=build
if not exist %OUT_DIR% mkdir %OUT_DIR%
set OUT_DIR_BIN=%OUT_DIR%\bin
if not exist %OUT_DIR_BIN% mkdir %OUT_DIR_BIN%
set OUT_DIR_OBJ=%OUT_DIR%\obj
if not exist %OUT_DIR_OBJ% mkdir %OUT_DIR_OBJ%

set "C_FLAGS=/nologo"
set "C_FLAGS=%C_FLAGS% /std:c11 /utf-8 /FC"
set "C_FLAGS=%C_FLAGS% -W4 -wd4127 -wd4146 -wd4505 -wd4456 -wd4457"
set "C_FLAGS=%C_FLAGS% /DUNICODE /D_UNICODE /D_CRT_SECURE_NO_WARNINGS"
set "C_FLAGS=%C_FLAGS% /Ivendor\raylib\include"

set "L_FLAGS=/link"
set "L_FLAGS=%L_FLAGS% /LIBPATH:vendor\raylib\bin\windows\msvc16"
set "L_FLAGS=%L_FLAGS% /SUBSYSTEM:windows /ENTRY:mainCRTStartup /NODEFAULTLIB:libcmt /INCREMENTAL:no"
set "L_FLAGS=%L_FLAGS% raylib.lib opengl32.lib winmm.lib user32.lib shell32.lib gdi32.lib"

if "%~1" == "--debug" (
    set "C_FLAGS=%C_FLAGS% /Od /Zi /MDd"
    set "C_FLAGS=%C_FLAGS% /DDEBUG /D_DEBUG"

) else if "%~1" == "--release" (
    set "C_FLAGS=%C_FLAGS% /O2 /MT /GF"
    set "C_FLAGS=%C_FLAGS% /DNDEBUG /D_NDEBUG"
)

cl src\main.c /Fo"%OUT_DIR_OBJ%\\" /Fe"%OUT_DIR_BIN%\\game_desktop.exe" %C_FLAGS% %L_FLAGS%
if %ERRORLEVEL% neq 0 exit /b 1

echo Desktop build created in %OUT_DIR%\bin

endlocal
