# CSCFindFirstFileW function

\[This function is not supported and should not be used.\]

Searches for a file in the Offline Files cache that meets the specified criteria.

## Parameters

*lpszFileName* \[in\]

A pointer to a null-terminated string that specifies a valid UNC directory or path.

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
| **FLAG\_CSC\_HINT\_PIN\_USER**

0x01 | A user has made the file available offline.\ | | **FLAG\_CSC\_HINT\_PIN\_INHERIT\_USER**

0x02 | A user has made the parent available offline and marked the parent such that its children are available offline.\ | | **FLAG\_CSC\_HINT\_PIN\_INHERIT\_SYSTEM**

0x04 | An administrator or group policy has made the parent available offline and marked the parent such that its children are available offline.\ | | **FLAG\_CSC\_HINT\_PIN\_SYSTEM**

0x10 | An administrator or group policy has made the file available offline.\ |

*lpOrgFileTime* \[out\]

A pointer to a [**FILETIME**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure to receive the date and time information for the file or subdirectory.

## Return value

If the function succeeds, the return value is a search handle used in a subsequent call to [**CSCFindNextFileW**](https://learn.microsoft.com/windows/win32/devnotes/cscfindnextfilew) or [**CSCFindClose**](https://learn.microsoft.com/windows/win32/devnotes/cscfindclose).

If the function fails, the return value is **INVALID\_HANDLE\_VALUE**.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| DLL<br> | Cscmig.dll |

