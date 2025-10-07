# FreeCryptProvFromCertEx function

The **FreeCryptProvFromCertEx** function releases the handle either to a [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) or to a Cryptography API: Next Generation (CNG) key.

> [!NOTE]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file and use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to `Mssign32.dll`.

## Parameters

*fAcquired* `[in]`

A value that specifies whether the provider handle was acquired from the [*certificate*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

*hProv* `[in]`

A handle to a CAPICOM CSP or a handle to a CNG key.

*dwKeySpec*

The address of a **DWORD** variable that receives additional information about the key. This can be one of the following values.

| Value | Meaning |
|-------|---------|
|

**AT\_KEYEXCHANGE**

| The key pair is a key exchange pair. |
|

**AT\_SIGNATURE**

| The key pair is a signature pair. |
|

**CERT\_NCRYPT\_KEY\_SPEC**

| The key is a CNG key.<br> **Windows Server 2003 and Windows XP:** This value is not supported. |

*pwszCapiProvider* `[in, optional]`

A pointer to a null-terminated string for the provider name.

*dwProviderType* `[in]`

Specifies the CSP type. This can be zero or one of the [Cryptographic Provider Types](https://learn.microsoft.com/windows/win32/seccrypto/cryptographic-provider-types). If this member is zero, the key container is one of the CNG key storage providers.

*pwszTmpContainer* `[in, optional]`

A pointer to a null-terminated string for the name of the temporary key container.

## Return value

This function does not return a value.

## Requirements

| Requirement | Value |
|-------------|-------|
| Minimum supported client | Windows 7 \[desktop apps only\] |
| Minimum supported server | Windows Server 2008 R2 \[desktop apps only\] |
| DLL | `Mssign32.dll` |