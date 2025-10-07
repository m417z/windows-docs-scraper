# WTHelperGetFileHash function

\[The **WTHelperGetFileHash** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.\]

The **WTHelperGetFileHash** function verifies the signature of a signed file and obtains the hash value and algorithm identifier for the file.

> [!Note]
> This function is not declared in a published header file. To use this function, declare it in the exact format shown. This function also has no associated import library. You must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

*pwszFilename* \[in\]

A pointer to a null-terminated Unicode string that contains the path and file name of the file to get the hash for.

*dwFlags* \[in\]

This parameter is not used and should be zero.

*pvReserved* \[in, out, optional\]

This parameter is not used and should be **NULL**.

*pbFileHash* \[out, optional\]

A pointer to a buffer to receive the hash value for the file. The *pcbFileHash* parameter contains the size of this buffer.

*pcbFileHash* \[in, out, optional\]

A pointer to a **DWORD** variable that, on input, contains the size, in bytes, of the *pbFileHash* buffer and, on output, receives the size, in bytes, of the hash value.

To obtain the required size of the hash value, pass **NULL** for the *pbFileHash* parameter. This function will place the required size, in bytes, of the hash value in this location.

If the *pbFileHash* parameter is not **NULL**, and the size is not large enough to receive the hash value, this function will place the required size, in bytes, in this location and return **ERROR\_MORE\_DATA**.

*pHashAlgid* \[out, optional\]

A pointer to an [**ALG\_ID**](https://learn.microsoft.com/windows/win32/seccrypto/alg-id) variable to receive the identifier of the algorithm used to create the hash value. This parameter can be **NULL** if this information is not needed.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
|-----------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------|
| **ERROR\_SUCCESS** | The file is signed, and the signature was verified.<br> |
| **ERROR\_MORE\_DATA** | The *pbFileHash* parameter is not **NULL**, and the size specified by the *pcbFileHash* parameter is not large enough to receive the hash.<br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | A memory allocation failure occurred.<br> |
| **TRUST\_E\_BAD\_DIGEST** | The signature of the file was not verified.<br> |
| **TRUST\_E\_NOSIGNATURE** | The file was not signed or had a signature that is not valid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Wintrust.dll |

