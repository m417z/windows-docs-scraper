# SspiDecryptAuthIdentityEx function

## Description

Decrypts a **SEC_WINNT_AUTH_IDENTITY_OPAQUE** structure.

## Parameters

### `Options` [in]

Decryption options. This parameter should be the same value as the value passed to the [SspiEncryptAuthIdentityEx](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentityex) function, which can be one of the following values.

| Value | Meaning |
| --- | --- |
| SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_LOGON | The encrypted structure can only be decrypted by a security context in the same logon session. This option is used to protect an identity buffer that is being sent over a local RPC. |
| SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_PROCESS | The encrypted structure can only be decrypted by the same process. Calling the function with this option is equivalent to calling [SspiEncryptAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentity). This option is used to protect an identity buffer that is being persisted in a process's private memory for an extended period. |

### `EncryptedAuthData` [in, out]

 This buffer is the output of the [SspiEncryptAuthIdentityEx](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentityex) function.

## Return value

If the function succeeds, it returns SEC_E_OK.

If the function fails, it returns a nonzero error code.