# CryptUnprotectMemory function

## Description

The **CryptUnprotectMemory** function decrypts memory that was encrypted using the [CryptProtectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectmemory) function.

## Parameters

### `pDataIn` [in, out]

A pointer to the block of memory to decrypt. The *cbData* parameter specifies the number of bytes that the function will attempt to decrypt. If the data contained in the memory space is smaller than the number of bytes specified, the function will attempt to decrypt data outside of the intended block. If it is larger than *cbData* bytes, then only the first *cbData* bytes will be decrypted.

### `cbDataIn` [in]

Number of bytes of memory pointed to by the *pData* parameter to decrypt. The number of bytes must be a multiple of the **CRYPTPROTECTMEMORY_BLOCK_SIZE** constant defined in Wincrypt.h.

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

 You must encrypt and decrypt the memory during the same boot session. If the computer is restarted before you call the **CryptUnprotectMemory** function, you will not be able to decrypt the data.

You must pass the same flag to **CryptUnprotectMemory** and [CryptProtectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectmemory). If you pass different flags, the **CryptUnprotectMemory** function succeeds; however, the result is unpredictable.

 When you have finished using the sensitive information, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function.

#### Examples

The following example calls the **CryptUnprotectMemory** function to decrypt data that is in memory. The example assumes the variable pEncryptedText points to a string that has been encrypted using the [CryptProtectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectmemory) function.

```cpp
#include <windows.h>
#include <stdio.h>
#include <Wincrypt.h>
#include <strsafe.h>
#pragma comment(lib, "crypt32.lib")

void main()
{
    LPWSTR pEncryptedText;  // contains the encrypted text
    DWORD cbEncryptedText;  // number of bytes to which
	                        // pEncryptedText points

    if (CryptUnprotectMemory(pEncryptedText, cbEncryptedText,
		CRYPTPROTECTMEMORY_SAME_PROCESS))
    {
        // Use the decrypted string.
    }
    else
    {
        wprintf(L"CryptUnprotectMemory failed: %d\n",
			GetLastError());
    }

    // Clear and free memory after using
    // the decrypted string or if an error occurs.
    SecureZeroMemory(pEncryptedText, cbEncryptedText);
    LocalFree(pEncryptedText);
    pEncryptedText = NULL;
}
```

## See also

[CryptProtectMemory](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectmemory)

[CryptUnprotectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectdata)

[RtlDecryptMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-rtldecryptmemory)

[RtlEncryptMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-rtlencryptmemory)