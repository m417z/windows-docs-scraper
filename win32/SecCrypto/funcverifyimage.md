# CRYPT\_VERIFY\_IMAGE function pointer

The **FuncVerifyImage** callback function is used by a [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) to verify the signature of a DLL.

All auxiliary DLLs into which a CSP makes function calls must be signed in the same manner (and with the same key) as the primary CSP DLL. To ensure this signature, the auxiliary DLLs must be loaded dynamically by using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) function. But before the DLL is loaded, the signature of the DLL must be verified. The CSP performs this verification by calling the **FuncVerifyImage** function, as shown in the example below.

## Parameters

*lpszImage* \[in\]

The address of a null-terminated string that contains the path and file name of the DLL to verify the signature for.

*pbSigData* \[in\]

The address of a buffer that contains the signature.

## Return value

Returns **TRUE** if the function succeeds, **FALSE** if it fails.

## Examples

The following example shows how to use the **FuncVerifyImage** callback function to verify the signature of a DLL before it is loaded by a CSP.

```C++
BOOL (FARPROC *ProvVerifyImage)(LPCSTR lpszImage, BYTE *pSigData);

//  "ProvVerifyImage" has been set to "pVTable->FuncVerifyImage"
//  within the CPAcquireContext function.

//  bSignature is a previously assigned BYTE array that contains the
//  signature that is stored in the C:\Winnt40\System32\signature.sig
//  file. During development, this file is created with the
//  Sign.exe tool.
...

//  Verify the signature in the
//  C:\Winnt40\System32\Signature.dll file.
if(RCRYPT_FAILED(ProvVerifyImage
    ("c:\\winnt40\\system32\\signature.dll",
        bSignature)) {
    SetLastError(NTE_BAD_SIGNATURE);
    return CRYPT_FAILED;
}

//  Load the DLL with the LoadLibrary function, then acquire pointers
//  to the functions with the GetProcAddress function.
//...
```

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Cspdk.h |

## See also

[**CPAcquireContext**](https://www.bing.com/search?q=**CPAcquireContext**)

[**VTableProvStruc**](https://learn.microsoft.com/windows/win32/seccrypto/vtableprovstruc)

