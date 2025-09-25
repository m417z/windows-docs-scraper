# CryptCATAdminCalcHashFromFileHandle function

## Description

[The **CryptCATAdminCalcHashFromFileHandle** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATAdminCalcHashFromFileHandle** function calculates the hash for a file. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hFile` [in]

A handle to the file whose hash is being calculated. This parameter cannot be **NULL** and must be a valid file handle.

### `pcbHash` [in, out]

A pointer to a **DWORD** variable that contains the number of bytes in *pbHash*. Upon input, set *pcbHash* to the number of bytes allocated for *pbHash*. Upon return, *pcbHash* contains the number of returned bytes in *pbHash*. If *pbHash* is passed as **NULL**, then *pcbHash* contains the number of bytes to allocate for *pbHash*.

### `pbHash` [in]

A pointer to a **BYTE** buffer that receives the hash. If this parameter is passed in as **NULL**, then *pcbHash* contains the number of bytes to allocate for *pbHash*, and a subsequent call can be made to retrieve the hash.

### `dwFlags` [in]

This parameter is reserved for future use and must be set to zero.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails. If **FALSE** is returned, call the **GetLastError** function to determine the reason for failure. If not enough memory has been allocated for *pbHash*, the **CryptCATAdminCalcHashFromFileHandle** function will set the last error to ERROR_INSUFFICIENT_BUFFER.