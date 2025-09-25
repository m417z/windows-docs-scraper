# GetOleaccVersionInfo function

## Description

Retrieves the version number and build number of the Microsoft Active Accessibility file Oleacc.dll.

## Parameters

### `pVer` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Address of a **DWORD** that receives the version number. The major version number is placed in the high word, and the minor version number is placed in the low word.

### `pBuild` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Address of a **DWORD** that receives the build number. The major build number is placed in the high word, and the minor build number is placed in the low word.

## Remarks

This function provides an easy way to get the version and build numbers for Oleacc.dll. The [GetFileVersionInfoSize](https://learn.microsoft.com/windows/win32/api/winver/nf-winver-getfileversioninfosizea), [GetFileVersionInfo](https://learn.microsoft.com/windows/win32/api/winver/nf-winver-getfileversioninfoa), and [VerQueryValue](https://learn.microsoft.com/windows/win32/api/winver/nf-winver-verqueryvaluea) functions can be used to retrieve the same information.