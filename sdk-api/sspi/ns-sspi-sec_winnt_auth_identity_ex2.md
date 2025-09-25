# SEC_WINNT_AUTH_IDENTITY_EX2 structure

## Description

Contains information about an authentication identity. The **SEC_WINNT_AUTH_IDENTITY_EX2** structure contains authentication data that is provided to the [AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) function.

## Members

### `Version`

The version number of the structure. This must be **SEC_WINNT_AUTH_IDENTITY_VERSION_2**.

### `cbHeaderLength`

The size, in bytes, of the structure header.

### `cbStructureLength`

The size, in bytes, of the structure.

### `UserOffset`

The offset from the beginning of the structure to the beginning of the user name string.

### `UserLength`

The size, in bytes, of the user name string.

### `DomainOffset`

The offset from the beginning of the structure to the beginning of the domain name string.

An identity credential should contain the identity provider name instead of the domain name.

### `DomainLength`

The size, in bytes, of the domain name string.

### `PackedCredentialsOffset`

The offset from the beginning of the structure to the beginning of the packed credentials.

The packed credential is a [SEC_WINNT_AUTH_PACKED_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_packed_credentials) structure that contains a credential type that uniquely specifies the credential type.

### `PackedCredentialsLength`

The size, in bytes, of the packed credentials string.

### `Flags`

An **unsigned long** flag that indicates the type used by negotiable [security packages](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

| Value | Meaning |
| --- | --- |
| **SEC_WINNT_AUTH_IDENTITY_MARSHALLED**<br><br>4 (0x4) | All data is in one buffer. |
| **SEC_WINNT_AUTH_IDENTITY_ONLY**<br><br>8 (0x8) | Used with the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP). Credentials are for identity only. The Kerberos package is directed to not include authorization data in the ticket. |
| **SEC_WINNT_AUTH_IDENTITY_ANSI**<br><br>1 (0x1) | Credentials are in ANSI form. |
| **SEC_WINNT_AUTH_IDENTITY_UNICODE**<br><br>2 (0x2) | Credentials are in Unicode form. |
| **SEC_WINNT_AUTH_IDENTITY_FLAGS_ID_PROVIDER**<br><br>524288 (0x80000) | When the credential type is password, the presence of this flag specifies that the structure is an online ID credential. The **DomainOffset** and **DomainLength** members correspond to the online ID provider name.<br><br>**Windows Server 2008 R2 and Windows 7:** This flag is not supported. |
| **SEC_WINNT_AUTH_IDENTITY_FLAGS_PROCESS_ENCRYPTED**<br><br>16 (0x10) | The structure is encrypted by the [SspiEncryptAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentity) function or by the [SspiEncryptAuthIdentityEx](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentityex) function with the SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_PROCESS option. It can only be decrypted by the same process.<br><br>**Windows Server 2008 R2 and Windows 7:** This flag is not supported. |
| **SEC_WINNT_AUTH_IDENTITY_FLAGS_SYSTEM_PROTECTED**<br><br>32 (0x20) | The structure is encrypted by the [SspiEncryptAuthIdentityEx](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentityex) function with the SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_LOGON option under the SYSTEM security context. It can only be decrypted by a thread running as SYSTEM.<br><br>**Windows Server 2008 R2 and Windows 7:** This flag is not supported. |
| **SEC_WINNT_AUTH_IDENTITY_FLAGS_USER_PROTECTED**<br><br>64 (0x40) | The structure is encrypted by the [SspiEncryptAuthIdentityEx](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentityex) function with the SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_LOGON option under a non-SYSTEM security context. It can only be decrypted by a thread running in the same logon session in which it was encrypted.<br><br>**Windows Server 2008 R2 and Windows 7:** This flag is not supported. |
| **SEC_WINNT_AUTH_IDENTITY_FLAGS_RESERVED**<br><br>65536 (0x10000) | The authentication identity buffer is **cbStructureLength** + 8 padding bytes that are necessary for in-place encryption or decryption of the identity. |

### `PackageListOffset`

The offset from the beginning of the structure to the beginning of the list of supported packages.

### `PackageListLength`

The size, in bytes, of the supported package list.

## Remarks

This authentication identity buffer can be returned from several credential APIs, for example, the [GetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-getserialization) method and the [CredUIPromptForWindowsCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa) and [SspiPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspipromptforcredentialsa) functions.

The structure describes a header of the authentication identity buffer and the data is appended at the end of the structure. Although the buffer size is specified by the **cbStructureLength** member, the actual buffer size can be larger or smaller than **cbStructureLength**. Some functions, such as [SspiValidateAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspivalidateauthidentity), take a pointer, but not the buffer size, to the identity structure as input. As a result, those functions can validate the internal buffer data but cannot verify the buffer size. This can result in reading or writing data outside of the buffer range. To avoid buffer overruns when handling an untrusted identity buffer, applications should call [SspiUnmarshalAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiunmarshalauthidentity) to obtain a pointer to an identity structure with a validated size and then pass that pointer to the functions.

The **SEC_WINNT_AUTH_IDENTITY_EX2** structure can be returned by [QueryContextAttributes(CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) and consumed by [AcquireCredentialsHandle(CredSSP)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea), [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser), and other identity provider interfaces.

[SEC_WINNT_AUTH_PACKED_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_packed_credentials) can contain a password credential type, defined as SEC_WINNT_AUTH_DATA_TYPE_PASSWORD. This credential type describes password credentials of a domain user as well as other online identities. Applications must define _SEC_WINNT_AUTH_TYPES to compile code that references this credential type as well as other definitions of the **SEC_WINNT_AUTH_PACKED_CREDENTIALS** structure.

Applications should not query or set the **Flags** member directly. Use the [SspiIsAuthIdentityEncrypted](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiisauthidentityencrypted), [SspiEncryptAuthIdentityEx](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentityex), and [SspiDecryptAuthIdentityEx](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspidecryptauthidentityex) functions to manage the encryption and decryption of the **SEC_WINNT_AUTH_IDENTITY_EX2** structure.

Identity providers must explicitly check or set SEC_WINNT_AUTH_IDENTITY_FLAGS_ID_PROVIDER and the domain name fields to differentiate their password credential from a domain password and another identity provider's password.

The [CredPackAuthenticationBuffer](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credpackauthenticationbuffera) function can be called with the CRED_PACK_ID_PROVIDER_CREDENTIALS option to create a **SEC_WINNT_AUTH_IDENTITY_EX2** structure with the authentication data of SEC_WINNT_AUTH_DATA_TYPE_PASSWORD credential type, a **Flags** member that contains the SEC_WINNT_AUTH_IDENTITY_FLAGS_ID_PROVIDER value, and a **DomainOffset** member set to the provider name.