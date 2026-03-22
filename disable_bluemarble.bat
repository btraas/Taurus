@echo off
set "SCRIPT_DIR=%~dp0"
set "SOURCE=%SCRIPT_DIR%Assets\BM_v4.50_HI.FPK"
set "DEST=%SCRIPT_DIR%Assets\BM_v4.50_HI.FPK.bak"

if not exist "%SOURCE%" (
    echo ERROR: Blue Marble is not enabled.
    pause
    exit /b 1
)


echo Disabling Blue Marble. Warning, this may break multiplayer for this mod until you re-enable....

move "%SOURCE%" "%DEST%"

if errorlevel 1 (
    echo ERROR: Failed to disable Blue Marble.
) else (
    echo Success
)

pause

