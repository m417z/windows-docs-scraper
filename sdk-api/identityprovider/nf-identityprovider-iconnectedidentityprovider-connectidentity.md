# IConnectedIdentityProvider::ConnectIdentity

## Description

Connects an identity to a domain user.

## Parameters

### `AuthBuffer` [in]

A marshaled authentication buffer [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure that contains the credential of the online identity. The buffer can be constructed by the caller by using the [CredPackAuthenticationBuffer](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credpackauthenticationbuffera) function with the CRED_PACK_ID_PROVIDER_CREDENTIALS option or returned by an online identity credential provider from the [CredUIPromptForWindowsCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa) function. The buffer can be optionally encrypted by calling the [SspiEncryptAuthIdentityEx](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiencryptauthidentityex) function with the SEC_WINNT_AUTH_IDENTITY_ENCRYPT_SAME_LOGON option.

### `AuthBufferSize` [in]

Size, in bytes, of the *AuthBuffer* parameter.

## Return value

If the method succeeds, returns S_OK.

If the method fails, returns a Win32 error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ERROR_LOGON_FAILURE** | The user name or password is not correct. |
| **ERROR_USER_EXISTS** | The domain user is already connected or associated with an online identity from this provider. |
| **ERROR_INVALID_ACCOUNT_NAME** | The format of the online user name is not valid. |

## Remarks

The *AuthBuffer* parameter can be encrypted in the system context if the credential is collected on the secure desktop. In that case, the identity provider cannot decrypt the credential in the current process. To decrypt the buffer, the identity provider will need to send the credential to a process that is running in the system context.

## See also

[IConnectedIdentityProvider](https://learn.microsoft.com/windows/desktop/api/identityprovider/nn-identityprovider-iconnectedidentityprovider)