# CSCQueryDatabaseStatus function

\[This function is not supported and should not be used.\]

Retrieves the status of the Offline Files cache.

## Parameters

*pulStatus*

The status. This parameter can be one of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------|
| **FLAG\_DATABASESTATUS\_ENCRYPTED**

0x00000002 | The cache is marked for encryption and all files in the cache are encrypted.\ | | **FLAG\_DATABASESTATUS\_PARTIALLY\_ENCRYPTED**

0x00000004 | The cache is marked for encryption, but some files in the cache are not encrypted.\ | | **FLAG\_DATABASESTATUS\_PARTIALLY\_UNENCRYPTED**

0x00000004 | The cache is not marked for encryption, but not all files in the cache have been decrypted.\ | | **FLAG\_DATABASESTATUS\_UNENCRYPTED**

0x00000000 | The cache is not marked for encryption and all files in the cache have been decrypted.\ |

*pulErrors*

This parameter is a nonzero value if there is an internal database error or 0 otherwise.

## Return value

This function returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| DLL<br> | Cscmig.dll |

## See also

[**CSCIsCSCEnabled**](https://learn.microsoft.com/windows/win32/devnotes/csciscscenabled)

