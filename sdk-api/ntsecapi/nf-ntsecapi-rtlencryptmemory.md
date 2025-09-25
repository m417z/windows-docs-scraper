# RtlEncryptMemory function

## Description

[The [RtlDecryptMemory](https://learn.microsoft.com/windows/win32/api/ntsecapi/nf-ntsecapi-rtldecryptmemory) function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [CryptProtectMemory](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptprotectmemory) function.]

The **RtlEncryptMemory** function encrypts memory contents. The encrypted contents can be decrypted by a subsequent call to the [RtlDecryptMemory](https://learn.microsoft.com/windows/win32/api/ntsecapi/nf-ntsecapi-rtldecryptmemory) function.

> [!NOTE]
> This function has no associated import library. This function is available as a resource named **SystemFunction040** in `Advapi32.dll`. You must use the [LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to `Advapi32.dll`.

## Parameters

### `Memory` [in, out]

A pointer to the memory to encrypt. The size of the memory must be a multiple of the **RTL_ENCRYPT_MEMORY_SIZE** constant.

### `MemorySize` [in]

Number of bytes to which *Memory* points. The number of bytes must be a multiple of the **RTL_ENCRYPT_MEMORY_SIZE** constant.

### `OptionFlags` [in]

Value that specifies how the encryption works over process boundaries and impersonation. This parameter can be one of the following values. The values are mutually exclusive. You must specify the same flag when encrypting and decrypting the memory.

| Value | Meaning |
|-------|---------|
| `0` | Encrypt and decrypt memory in the same process. An application running in a different process will not be able to decrypt the data. |
| **RTL_ENCRYPT_OPTION_CROSS_PROCESS**<br>`0x01` | Encrypt and decrypt memory in different processes. An application running in a different process will be able to decrypt the data. |
| **RTL_ENCRYPT_OPTION_SAME_LOGON**<br>`0x02` | Use the same logon credentials to encrypt and decrypt memory in different processes. An application running in a different process will be able to decrypt the data. However, the process must run as the same user that encrypted the data and in the same logon session. |
| **RTL_ENCRYPT_OPTION_FOR_SYSTEM**<br>`0x04` | Allow callers to encrypt information to be decrypted only by a system process. |

## Return value

If the function is successful, the return value is **STATUS_SUCCESS**.

If the function fails, the return value is an **NTSTATUS** code that indicates the error.