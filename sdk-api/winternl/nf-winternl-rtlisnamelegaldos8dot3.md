# RtlIsNameLegalDOS8Dot3 function

## Description

[**RtlIsNameLegalDOS8Dot3**
is available for use in Windows XP. It may be altered or unavailable in
subsequent versions. Applications that target a minimum of Windows Server 2003 and
Windows XP with Service Pack 1 (SP1) and later should use the **CheckNameLegalDOS8Dot3**
function.]

Determines whether or not a specified name can be used to create a file on the FAT file
system.

## Parameters

### `Name` [in]

The file name, in 8.3 format.

### `OemName` [in, out, optional]

A pointer to a buffer that receives the OEM string that corresponds to *Name*.

This parameter can be **NULL**.

### `NameContainsSpaces` [out, optional]

If the function returns **TRUE**, this parameter indicates whether or not the name
contains spaces.

If the function returns **FALSE**, this parameter is undefined.

## Return value

If the specified name forms a valid 8.3 FAT file system name in the current OEM code page, the function
returns **TRUE**. Otherwise, the function returns **FALSE**.

## Remarks

This function does not have an associated import library. You must use the
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to
NtDll.dll.

## See also

[CheckNameLegalDOS8Dot3](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-checknamelegaldos8dot3a)