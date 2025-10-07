# CSCFindNextFileW function

\[This function is not supported and should not be used.\]

Continues a file search operation.

## Parameters

*hFind* \[in\]

A search handle returned by the [**CSCFindFirstFileW**](https://learn.microsoft.com/windows/win32/devnotes/cscfindfirstfilew) function.

*lpFind32* \[out\]

A pointer to the [**WIN32\_FIND\_DATA**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-win32_find_dataa) structure that receives information about the file or subdirectory.

*lpdwStatus* \[out\]

An NTSTATUS code that indicates the status of the call.

*lpdwPinCount* \[out\]

This parameter is nonzero if the file has been made available offline or 0 otherwise.

*lpdwHintFlags* \[out\]

This parameter can be one of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**FLAG\_CSC\_HINT\_PIN\_USER**

0x01

| A user has made the file available offline.<br> |
|

**FLAG\_CSC\_HINT\_PIN\_INHERIT\_USER**

0x02

| A user has made the parent available offline and marked the parent such that its children are available offline.<br> |
|

**FLAG\_CSC\_HINT\_PIN\_INHERIT\_SYSTEM**

0x04

| An administrator or group policy has made the parent available offline and marked the parent such that its children are available offline.<br> |
|

**FLAG\_CSC\_HINT\_PIN\_SYSTEM**

0x10

| An administrator or group policy has made the file available offline.<br> |

*lpOrgFileTime* \[in\]

A pointer to a [**FILETIME**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure to receive the date and time information for the file or subdirectory.

## Return value

This function returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| DLL<br> | Cscmig.dll |

