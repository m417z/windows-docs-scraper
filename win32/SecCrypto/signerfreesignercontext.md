# SignerFreeSignerContext function

The **SignerFreeSignerContext** function frees a [**SIGNER\_CONTEXT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-context) structure allocated by a previous call to the [**SignerSignEx**](https://learn.microsoft.com/windows/win32/seccrypto/signersignex) function.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*pSignerContext* \[in\]

A pointer to the [**SIGNER\_CONTEXT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-context) structure to free.

## Return value

If the function succeeds, the function returns S\_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/win32/seccrypto/common-hresult-values).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll |

## See also

[**SIGNER\_CONTEXT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-context)

[**SignerSignEx**](https://learn.microsoft.com/windows/win32/seccrypto/signersignex)

