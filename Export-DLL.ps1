<#
.SYNOPSIS
Recursively gathers all header files and makes them available in the output directory.

.DESCRIPTION
Recursively gathers all header files and makes them available in the output directory.
To use this script, add the following to the post build events in VS:
powershell.exe -NoProfile -Command "& '$(SolutionDir)Export-DLL.ps1' -ProjectDir '$(ProjectDir)' -OutputPath '$(OutputPath)'"

TODO: Add support to generate a master <Project-Name>.h, package everything up as zip, and not copy excluded files (stdafx.h, targetver.h, etc.).

.PARAMETER ProjectDir
The $(ProjectDir) macro to be filled in by VS.

.PARAMETER OutputPath
The $(OutputPath) macro to be filled in by VS.
#>
param(
    [Parameter(Mandatory=$true)]
    [ValidateNotNullOrEmpty()]
    [string]$ProjectDir,

    [Parameter(Mandatory=$true)]
    [ValidateNotNullOrEmpty()]
    [string]$OutputPath
)

$ExcludedFiles = @(
    # 'stdafx.h',
    # 'pch.h',
    # 'targetver.h'
)

$HeaderFiles = Get-ChildItem "$ProjectDir*.h" -Recurse | Where-Object {$ExcludedFiles -notcontains $_.Name}
$HeaderFiles | Copy-Item -Destination "$OutputPath"

# # Collect all source files
# $SourceFiles = Get-ChildItem -Recurse | Where-Object {$_.Name -like "*.cpp" -or $_.Name -like "*.h"}
# powershell -Command "#Get-Content '$(ProjectDir)PolygonalMath.h' | ForEach-Object { if ($_ -match '"(?<HeaderName>.*.h)"') { $Matches['HeaderName'] } }'"
# powershell -Command "#Remove-Item -Path '$(OutputPath)target.h'"