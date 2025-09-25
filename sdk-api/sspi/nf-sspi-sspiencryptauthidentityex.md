# SspiEncryptAuthIdentityEx function

## Description

Encrypts a **SEC_WINNT_AUTH_IDENTITY_OPAQUE** structure.

## Parameters

### `Options` [in]

Encryption options. This can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_LOGON | The encrypted structure can only be decrypted by a security context in the same logon session. This option is used to protect an identity buffer that is being sent over a local RPC. |
| SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_PROCESS | The encrypted structure can only be decrypted by the same process. Calling the function with this option is equivalent to calling [SspiEncryptAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentity). This option is used to protect an identity buffer that is being persisted in a process's private memory for an extended period. |

### `AuthData` [in, out]

On input, a pointer to an identity buffer to encrypt. This buffer must be prepared for encryption prior to the call to this function. This can be done by calling the function [SspiEncryptAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentity). On output, the encrypted identity buffer.

## Return value

If the function succeeds, it returns SEC_E_OK.

If the function fails, it returns a nonzero error code.

## Remarks

To transfer credentials securely across processes, applications typically call this function with the SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_LOGON option, followed by [SspiMarshalAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspimarshalauthidentity) to obtain a marshaled authentication buffer and its length.
For example, Online Identity Credential Provider does this to return the authentication buffer from their [ICredentialProviderCredential::GetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-getserialization) method.