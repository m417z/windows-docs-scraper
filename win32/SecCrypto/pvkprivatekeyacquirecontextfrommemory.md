# PvkPrivateKeyAcquireContextFromMemory function

> [!IMPORTANT]
> This API is deprecated. Microsoft may remove this API in future releases.

The **PvkPrivateKeyAcquireContextFromMemory** function creates a temporary container in the [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) and loads a [*private key*](https://learn.microsoft.com/windows/win32/secgloss/p-gly) from memory into the container.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*pwszProvName* \[in\]

A pointer to a null-terminated string that contains the name of the CSP whose type is requested in *dwProvType*.

*dwProvType* \[in\]

A **DWORD** value for the CSP type. For more information about CSP types, see [Cryptographic Provider Types](https://learn.microsoft.com/windows/win32/seccrypto/cryptographic-provider-types).

*pbData* \[in\]

A pointer to a buffer to receive the context data. The caller must provide this resource.

*cbData* \[in\]

A **DWORD** value that specifies the size, in bytes, of the *pbData* buffer. The caller must provide this value.

*hwndOwner* \[in\]

If a password is required to decrypt the context data pointed to by the *pbData* parameter, this parameter is a handle to the parent of the dialog box; otherwise, it is **NULL**.

*pwszKeyName* \[in\]

A pointer to a null-terminated string that contains the name of the key to retrieve.

*pdwKeySpec* \[in, out, optional\]

A pointer to a **DWORD** value that specifies the type of key. Possible values include **AT\_KEYEXCHANGE** or **AT\_SIGNATURE**.

*phCryptProv* \[out\]

A pointer to a handle for the CSP.

*ppwszTmpContainer* \[out\]

The address of a pointer to a null-terminated string for the temporary container name. The **PvkPrivateKeyAcquireContextFromMemory** function provides the buffer for this string and initializes it. When calling **PvkPrivateKeyAcquireContextFromMemory**, the address should point to a **NULL** value.

## Return value

Upon success, this function returns **TRUE**. The **PvkPrivateKeyAcquireContextFromMemory** function returns **FALSE** if it fails.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll |

