# CryptProtectMemory function

## Description

The **CryptProtectMemory** function [encrypts](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) memory to prevent others from viewing sensitive information in your process. For example, use the **CryptProtectMemory** function to encrypt memory that contains a password. Encrypting the password prevents others from viewing it when the process is paged out to the swap file. Otherwise, the password is in [plaintext](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and viewable by others.

## Parameters

### `pDataIn` [in, out]

A pointer to the block of memory to encrypt. The *cbDataIn* parameter specifies the number of bytes that will be encrypted. If the data contained in the memory space is smaller than the number of bytes specified, data outside of the intended block will be encrypted. If it is larger than *cbDataIn* bytes, then only the first *cbDataIn* bytes will be encrypted.

### `cbDataIn` [in]

Number of bytes of memory pointed to by the *pData* parameter to encrypt. The number of bytes must be a multiple of the **CRYPTPROTECTMEMORY_BLOCK_SIZE** constant defined in Wincrypt.h.

### `dwFlags` [in]

This parameter can be one of the following flags. You must specify the same flag when encrypting and decrypting the memory.

| Value | Meaning |
| --- | --- |
| **CRYPTPROTECTMEMORY_SAME_PROCESS** | Encrypt and decrypt memory in the same process. An application running in a different process will not be able to decrypt the data. |
| **CRYPTPROTECTMEMORY_CROSS_PROCESS** | Encrypt and decrypt memory in different processes. An application running in a different process will be able to decrypt the data. |
| **CRYPTPROTECTMEMORY_SAME_LOGON** | Use the same logon credentials to encrypt and decrypt memory in different processes. An application running in a different process will be able to decrypt the data. However, the process must run as the same user that encrypted the data and in the same logon session. |

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Using [CryptProtectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectmemory) and [CryptUnprotectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectmemory) for password encryption is not secure because the data exists as plaintext in memory before it is encrypted and at any time the caller decrypts it for use.

Typically, you use the **CryptProtectMemory** function to encrypt sensitive information that you are going to decrypt while your process is running. Do not use this function to save data that you want to decrypt later; you will not be able to decrypt the data if the computer is restarted. To save encrypted data to a file to decrypt later, use the [CryptProtectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectdata) function.

Call the [CryptUnprotectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectmemory) function to decrypt memory encrypted with the **CryptProtectMemory** function. When you have finished using the sensitive information, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function.

Use the CRYPTPROTECTMEMORY_CROSS_PROCESS or CRYPTPROTECTMEMORY_SAME_LOGON flag if you use RPC or LRPC to pass encrypted data to another process. The receiving process must specify the same flag to decrypt the data. Also, use these flags if you use shared memory.

If the client uses the CRYPTPROTECTMEMORY_SAME_LOGON flag, the server must impersonate the client ([RpcImpersonateClient](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcimpersonateclient)) before decrypting the memory.

#### Examples

The following example calls the **CryptProtectMemory** function to encrypt data that is in memory.

```cpp
#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>

#define SSN_STR_LEN 12  // includes null

void main()
{
    HRESULT hr = S_OK;
    LPWSTR pSensitiveText = NULL;
    DWORD cbSensitiveText = 0;
    DWORD cbPlainText = SSN_STR_LEN*sizeof(WCHAR);
    DWORD dwMod = 0;

    //  Memory to encrypt must be a multiple of CRYPTPROTECTMEMORY_BLOCK_SIZE.
    if (dwMod = cbPlainText % CRYPTPROTECTMEMORY_BLOCK_SIZE)
        cbSensitiveText = cbPlainText +
		(CRYPTPROTECTMEMORY_BLOCK_SIZE - dwMod);
    else
        cbSensitiveText = cbPlainText;

    pSensitiveText = (LPWSTR)LocalAlloc(LPTR, cbSensitiveText);
    if (NULL == pSensitiveText)
    {
        wprintf(L"Memory allocation failed.\n");
        return E_OUTOFMEMORY;
    }

    //  Place sensitive string to encrypt in pSensitiveText.

    if (!CryptProtectMemory(pSensitiveText, cbSensitiveText,
		CRYPTPROTECTMEMORY_SAME_PROCESS))
    {
        wprintf(L"CryptProtectMemory failed: %d\n", GetLastError());
        SecureZeroMemory(pSensitiveText, cbSensitiveText);
        LocalFree(pSensitiveText);
        pSensitiveText = NULL;
        return E_FAIL;
    }

    //  Call CryptUnprotectMemory to decrypt and use the memory.

    SecureZeroMemory(pSensitiveText, cbSensitiveText);
    LocalFree(pSensitiveText);
    pSensitiveText = NULL;

    return hr;
}
```

## See also

[CryptProtectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectdata)

[CryptUnprotectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectmemory)

[RtlDecryptMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-rtldecryptmemory)

[RtlEncryptMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-rtlencryptmemory)