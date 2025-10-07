# CSCGetSpaceUsageW function

\[This function is not supported and should not be used.\]

Retrieves information about the space used by the Offline Files cache.

## Parameters

*lptzLocation* \[in, out\]

The directory location of the cache.

*dwSize* \[in\]

The size of the *lptzLocation* buffer, in characters.

*lpdwMaxSpaceHigh* \[in, out\]

The high-order **DWORD** of the maximum number of bytes available in the cache.

*lpdwMaxSpaceLow* \[in, out\]

The low-order **DWORD** of the maximum number of bytes available in the cache.

*lpdwCurrentSpaceHigh* \[in, out\]

The high-order **DWORD** of the current number of bytes available in the cache.

*lpdwCurrentSpaceLow* \[in, out\]

The low-order **DWORD** of the current number of bytes available in the cache.

*lpcntTotalFiles* \[in, out\]

The total number of files in the cache.

*lpcntTotalDirs* \[in, out\]

The total number of directories in the cache.

## Return value

This function returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| DLL<br> | Cscmig.dll |

