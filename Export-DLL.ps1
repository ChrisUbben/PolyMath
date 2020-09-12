<#
.SYNOPSIS
Recursively gathers all header files and makes them available in the output directory.

.DESCRIPTION
Recursively gathers all header files and makes them available in the output directory.
To use this script, add the following to the post build events in VS:
powershell.exe -ExecutionPolicy Bypass -NoProfile -NonInteractive -File $(SolutionDir)Export-DLL.ps1 "$(ProjectDir)" "$(OutDir)"

.PARAMETER ProjectDir
The $(ProjectDir) macro to be filled in by VS.

.PARAMETER OutputPath
The $(OutputPath) macro to be filled in by VS.
#>

#TODO: Add support to generate a master <Project-Name>.h and package everything up as zip.

param(
    [Parameter(Mandatory=$true)]
    [ValidateNotNullOrEmpty()]
    [string]$ProjectDir,

    [Parameter(Mandatory=$true)]
    [ValidateNotNullOrEmpty()]
    [string]$OutputPath
)

Push-Location
try
{
    Set-Location -Path $ProjectDir

    # Copy header files
    $ExcludedFiles = @(
        'stdafx.h',
        'pch.h',
        'targetver.h'
    )

    $HeaderFiles = Get-ChildItem '*.h' -Recurse | Where-Object {$ExcludedFiles -notcontains $_.Name}

    if (-not (Test-Path -Path $OutputPath))
    {
        New-Item -Path $OutputPath -ItemType Directory -Force | Out-Null
    }
    $HeaderFiles | Copy-Item -Destination $OutputPath -Force

    return 0
}
catch
{
    return 1
}
finally
{
    Pop-Location
}