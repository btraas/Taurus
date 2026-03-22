@echo off
set "SCRIPT_DIR=%~dp0"
set "SOURCE=%SCRIPT_DIR%Assets\BM_v4.50_HI.FPK.bak"
set "DEST=%SCRIPT_DIR%Assets\BM_v4.50_HI.FPK"

if exist "%DEST%" (
    echo ERROR: Blue Marble is already enabled.
    pause
    exit /b 1
)

if not exist "%SOURCE%" (
    echo ERROR: Blue Marble files not found. Failed to enable.
    pause
    exit /b 1
)

echo "Enabling Blue Marble...."

move "%SOURCE%" "%DEST%"

if errorlevel 1 (
    echo ERROR: Failed to enable Blue Marble.
) else (
    echo Success
)

echo Done.
pause

