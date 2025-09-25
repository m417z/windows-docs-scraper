# CryptCATAdminCalcHashFromFileHandle2 function

## Description

The **CryptCATAdminCalcHashFromFileHandle2** function calculates the hash for a file by using the specified algorithm.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `hCatAdmin` [in]

Handle of an open catalog administrator context. For more information, see [CryptCATAdminAcquireContext2](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadminacquirecontext2).

### `hFile` [in]

A handle to the file whose hash is being calculated. This parameter cannot be **NULL** and must be a valid file handle.

### `pcbHash` [in, out]

Pointer to a **DWORD** variable that contains the number of bytes in the *pbHash* parameter. Upon input, set *pcbHash* to the number of bytes allocated for *pbHash*. Upon return, *pcbHash* contains the number of returned bytes in *pbHash*. If *pbHash* is set to **NULL**, then *pcbHash* contains the number of bytes to allocate for *pbHash*.

### `pbHash`

Pointer to a **BYTE** buffer that receives the hash. If you set this parameter to **NULL**, then *pcbHash* will contain the number of bytes to allocate for *pbHash*, and a subsequent call can be made to retrieve the hash.

### `dwFlags`

Reserved. This value must be zero.

## Return value

If the function succeeds, the return value is nonzero (**TRUE**).

If the function fails, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table lists the error codes most commonly returned by the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *hFile* parameter must not be **NULL**.<br><br>The *hFile* parameter must be a valid file handle.<br><br>The *pcbHash* parameter must not be **NULL**.<br><br>The *dwFlags* parameter must be zero (0). |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by the *pbHash* parameter was not **NULL** but was not large enough to be written. The correct size of the required buffer is contained in the value pointed to by the *pcbHash* parameter. |
| **NTE_BAD_ALGID** | The hash algorithm specified by the *pwszHashAlgorithm* parameter cannot be found. |

## Remarks

The amount of time this function takes to execute depends on the length of the file being hashed, the algorithm being used, and the file location. For example, it takes several seconds to calculate the hash of a local file that is very large (a few hundred megabytes).

## See also

[CryptCATAdminCalcHashFromFileHandle](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadmincalchashfromfilehandle)

[CryptCATAdminCalcHashFromFileHandle2](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatadmincalchashfromfilehandle2)