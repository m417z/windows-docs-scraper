# CredUnPackAuthenticationBufferW function

## Description

The **CredUnPackAuthenticationBuffer** function converts an authentication buffer returned by a call to the [CredUIPromptForWindowsCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa) function into a string user name and password.

## Parameters

### `dwFlags` [in]

Setting the value of this parameter to **CRED_PACK_PROTECTED_CREDENTIALS** specifies that the function attempts to decrypt the credentials in the authentication buffer. If the credential cannot be decrypted, the function returns **FALSE**, and a call to the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function will return the value **ERROR_NOT_CAPABLE**.

How the decryption is done depends on the format of the authentication buffer.

If the authentication buffer is a [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure, the function can decrypt the buffer if it is encrypted by using [SspiEncryptAuthIdentityEx](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentityex) with the SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_LOGON option.

If the authentication buffer is one of the marshaled KERB_*_LOGON structures, the function decrypts the password before returning it in the *pszPassword* buffer.

### `pAuthBuffer` [in]

A pointer to the authentication buffer to be converted.

This buffer is typically the output of the [CredUIPromptForWindowsCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa) or [CredPackAuthenticationBuffer](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credpackauthenticationbuffera) function. This must be one of the following types:

* A [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure for identity credentials. The function does not accept other [SEC_WINNT_AUTH_IDENTITY](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_a) structures.
* A [KERB_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_logon) or [KERB_INTERACTIVE_UNLOCK_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_unlock_logon) structure for password credentials.
* A [KERB_CERTIFICATE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_logon) or [KERB_CERTIFICATE_UNLOCK_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_unlock_logon) structure for smart card certificate credentials.
* GENERIC_CRED for generic credentials.

### `cbAuthBuffer` [in]

The size, in bytes, of the *pAuthBuffer* buffer.

### `pszUserName` [out]

A pointer to a null-terminated string that receives the user name.

This string can be a marshaled credential. See Remarks.

### `pcchMaxUserName` [in, out]

A pointer to a **DWORD** value that specifies the size, in characters, of the *pszUserName* buffer. On output, if the buffer is not of sufficient size, specifies the required size, in characters, of the *pszUserName* buffer. The size includes terminating null character.

### `pszDomainName` [out]

A pointer to a null-terminated string that receives the name of the user's domain.

### `pcchMaxDomainName` [in, out]

A pointer to a **DWORD** value that specifies the size, in characters, of the *pszDomainName* buffer. On output, if the buffer is not of sufficient size, specifies the required size, in characters, of the *pszDomainName* buffer. The size includes the terminating null character. The required size can be zero if there is no domain name.

### `pszPassword` [out]

A pointer to a null-terminated string that receives the password.

### `pcchMaxPassword` [in, out]

A pointer to a **DWORD** value that specifies the size, in characters, of the *pszPassword* buffer. On output, if the buffer is not of sufficient size, specifies the required size, in characters, of the *pszPassword* buffer. The size includes the terminating null character.

This string can be a marshaled credential. See Remarks.

#### - pcchlMaxUserName [in, out]

A pointer to a **DWORD** value that specifies the size, in characters, of the *pszUserName* buffer. On output, if the buffer is not of sufficient size, specifies the required size, in characters, of the *pszUserName* buffer. The size includes terminating null character.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**.

For extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. The following table shows common values for the **GetLastError** function.

| Return code/value | Description |
| --- | --- |
| ****ERROR_NOT_CAPABLE**** | CRED_PACK_PROTECTED_CREDENTIALS was passed as the value of the *dwFlags* parameter, but this function cannot decrypt the credential because the security context used to protect the password is different from the security context of the caller. |
| ****ERROR_INSUFFICIENT_BUFFER**** | One of the output buffers, *pszUserName*, *pszDomainName*, or *pszPassword*, was of insufficient size. |
| ****ERROR_NOT_SUPPORTED**** | The authentication buffer is not of a supported type. |

## Remarks

Beginning with Windows 8 and Windows Server 2012, the authentication buffer can be a [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure, which can be optionally encrypted by using the [SspiEncryptAuthIdentityEx](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentityex) function with the SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_LOGON option. This credential format is returned by a Credential Provider of an Identity Provider by using the [CredUIPromptForWindowsCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa) or [SspiPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspipromptforcredentialsa) function. This structure can also be constructed by using the [CredPackAuthenticationBuffer](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credpackauthenticationbuffera) function.
If the authentication buffer *pAuthBuffer* represents a nonpassword credential, such as [KERB_CERTIFICATE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_logon) or **SEC_WINNT_AUTH_IDENTITY_EX2**, the function must marshal the credential as character strings, returned as user name, domain name, and password strings. The marshaling is done by using a specific procedure. When *dwFlags* contains the CRED_PACK_PROTECTED_CREDENTIALS flag, the caller must run in the same logon session in which the credential was encrypted.

> [!NOTE]
> The wincred.h header defines CredUnPackAuthenticationBuffer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).