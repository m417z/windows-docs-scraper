# CredPackAuthenticationBufferA function

## Description

The **CredPackAuthenticationBuffer** function converts a string user name and password into an authentication buffer.

Beginning with Windows 8 and Windows Server 2012, the **CredPackAuthenticationBuffer** function converts an identity credential into an authentication buffer, which is a [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure. This buffer can be passed to [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser), [AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea), or other identity provider interfaces.

## Parameters

### `dwFlags` [in]

Specifies how the credential should be packed. This can be a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **CRED_PACK_PROTECTED_CREDENTIALS** | Encrypts the credential so that it can only be decrypted by processes in the caller's logon session. |
| **CRED_PACK_WOW_BUFFER** | Encrypts the credential in a WOW buffer. |
| **CRED_PACK_GENERIC_CREDENTIALS** | Encrypts the credential in a CRED_GENERIC buffer. |
| **CRED_PACK_ID_PROVIDER_CREDENTIALS** | Encrypts the credential of an online identity into a [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure. If CRED_PACK_GENERIC_CREDENTIALS and CRED_PACK_ID_PROVIDER_CREDENTIALS are not set, encrypts the credentials in a KERB_INTERACTIVE_LOGON buffer.<br><br>**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008:** This value is not supported. |

### `pszUserName` [in]

A pointer to a null-terminated string that specifies the user name to be converted. For domain users, the string must be in the following format:

*DomainName***\\***UserName*

For online identities, if the credential is a plaintext password, the user name format is *ProviderName***\\***UserName*. If the credential is a [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure, the user name is an encoded string that is the *UserName* parameter output of a function call to [SspiEncodeAuthIdentityAsStrings](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencodeauthidentityasstrings).

For [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) or certificate credentials, the user name is an encoded string that is the output of a function call to [CredMarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credmarshalcredentiala) with the CertCredential option.

**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** Online identities are not supported.

### `pszPassword` [in]

A pointer to a null-terminated string that specifies the password to be converted.

For [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) credentials, the password is an encoded string that is in the *ppszPackedCredentialsString* output of a function call to [SspiEncodeAuthIdentityAsStrings](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencodeauthidentityasstrings).

For [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) credentials, this is the *smart card* PIN.

**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** Online identities are not supported.

### `pPackedCredentials` [out]

A pointer to an array of bytes that, on output, receives the packed authentication buffer. This parameter can be **NULL** to receive the required buffer size in the *pcbPackedCredentials* parameter.

### `pcbPackedCredentials` [in, out]

A pointer to a **DWORD** value that specifies the size, in bytes, of the *pPackedCredentials* buffer. On output, if the buffer is not of sufficient size, specifies the required size, in bytes, of the *pPackedCredentials* buffer.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**.

For extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function, which may return the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer provided by *pPackedCredentials* is too small. |

## Remarks

> [!NOTE]
> The wincred.h header defines CredPackAuthenticationBuffer as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).