# PvkPrivateKeySave function

> [!IMPORTANT]
> This API is deprecated. Microsoft may remove this API in future releases.

The **PvkPrivateKeySave** function saves a [*private key*](https://learn.microsoft.com/windows/win32/secgloss/p-gly) and its corresponding [*public key*](https://learn.microsoft.com/windows/win32/secgloss/p-gly) to a specified file.

> [!Note]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Mssign32.dll.

## Parameters

*hCryptProv* \[in\]

A handle to a [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP).

*hFile* \[in\]

A handle to a file created with initial read/write permission and subsequent read-only permission.

*dwKeySpec* \[in\]

A long integer for the type of key. Possible values include **AT\_KEYEXCHANGE** or **AT\_SIGNATURE**.

*hwndOwner* \[in\]

If a password is required to encrypt the private key, this parameter is a handle to the parent of the dialog box; otherwise, it is **NULL**.

*pwszKeyName* \[in\]

A pointer to a null-terminated string for the name of the key to be saved.

*dwFlags* \[in\]

A **DWORD** value that specifies additional options for the function. For more information, see the *dwFlags* parameter in [**CryptExportKey**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/nf-wincrypt-cryptexportkey).

## Return value

Upon success, this function returns **TRUE**. The **PvkPrivateKeySave** function returns **FALSE** if it fails.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Mssign32.dll |

