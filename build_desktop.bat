@echo off
setlocal

set OUT_DIR=build
if not exist %OUT_DIR% mkdir %OUT_DIR%
set OUT_DIR_BIN=%OUT_DIR%\bin
if not exist %OUT_DIR_BIN% mkdir %OUT_DIR_BIN%
set OUT_DIR_OBJ=%OUT_DIR%\obj
if not exist %OUT_DIR_OBJ% mkdir %OUT_DIR_OBJ%

set "FLAGS=/nologo /std:c11 /utf-8 /FC"
set "FLAGS=%FLAGS% -W4 -wd4127 -wd4146 -wd4505 -wd4456 -wd4457"
set "FLAGS=%FLAGS% /DUNICODE /D_UNICODE /D_CRT_SECURE_NO_WARNINGS"
set "FLAGS=%FLAGS% /Ivendor\raylib\include"
set "FLAGS=%FLAGS% /link /LIBPATH:vendor\raylib\bin\windows\msvc16 /NODEFAULTLIB:libcmt /INCREMENTAL:no"
set "FLAGS=%FLAGS% raylib.lib winmm.lib user32.lib shell32.lib gdi32.lib"

if "%~1" == "--debug" (
    set "FLAGS=%FLAGS% /Od /Zi /MDd"
    set "FLAGS=%FLAGS% /DDEBUG /D_DEBUG"

) else if "%~1" == "--release" (
    set "FLAGS=/O2 /MT /GF"
    set "FLAGS=/DNDEBUG /D_NDEBUG %FLAGS%"
)

cl src\main.c /Fo"%OUT_DIR_OBJ%\\" /Fe"%OUT_DIR_BIN%\\game_desktop.exe" %FLAGS% 
if %ERRORLEVEL% neq 0 exit /b 1

echo Desktop build created in %OUT_DIR%\bin

endlocal
