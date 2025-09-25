# CryptFreeOIDFunctionAddress function

## Description

The **CryptFreeOIDFunctionAddress** function releases a handle returned by
[CryptGetOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetoidfunctionaddress) or
[CryptGetDefaultOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetdefaultoidfunctionaddress) by decrementing the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) on the function handle. In some cases, the DLL file associated with the function is unloaded. For details, see Remarks.

## Parameters

### `hFuncAddr` [in]

Handle of the function previously obtained from a call to
[CryptGetOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetoidfunctionaddress) or
[CryptGetDefaultOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetdefaultoidfunctionaddress).

### `dwFlags` [in]

Reserved for future use and must be zero.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**).

## Remarks

If the [reference count](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) becomes zero and a DLL is loaded for the function being freed, the DLL might be unloaded. If the DLL exports the [DLLCanUnloadNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow) function, that function is called and its return is checked. An S_FALSE return from this function cancels the unloading of the DLL at this time. If the function returns S_TRUE or if the DLL does not export the **DLLCanUnloadNow** function, an unloading process is started. In this case, actual unloading is deferred for 15 seconds. If another **CryptFreeOIDFunctionAddress** or [CryptGetDefaultOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetdefaultoidfunctionaddress) that requires the DLL occurs before the 15 seconds elapse, the deferred unload process is canceled.

## See also

[CryptGetDefaultOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetdefaultoidfunctionaddress)

[CryptGetOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetoidfunctionaddress)

[DLLCanUnloadNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow)

[OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)