@echo off
setlocal

set OUT_DIR=web
if not exist %OUT_DIR% mkdir %OUT_DIR%

set FILES="vendor\raylib\bin\wasm\libraylib.web.a"

set "FLAGS=-DPLATFORM_WEB"
set "FLAGS=%FLAGS% -I ./vendor/raylib/include"
set "FLAGS=%FLAGS% -sEXPORTED_RUNTIME_METHODS=['HEAPF32'] -sUSE_GLFW=3 -sWASM_BIGINT -sWARN_ON_UNDEFINED_SYMBOLS=0 -sASSERTIONS --shell-file src\index_template.html"

if "%~1" == "--debug" (
    REM put something
) else if "%~1" == "--release" (
    set "FLAGS=%FLAGS% -O3"
)

cmd /c emcc -o %OUT_DIR%\index.html src\main.c %FLAGS% %FILES% 

echo Web build created in %OUT_DIR%

endlocal
