# SEC_WINNT_CREDUI_CONTEXT structure

## Description

Specifies unserialized credential information. The credential information can be serialized by passing it as the **rgbSerialization** member of a [CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization) structure in a call to the [ICredentialProvider::SetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setserialization) method.

The unserialized information can be obtained by calling the [SspiUnmarshalCredUIContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspiunmarshalcreduicontext) function.

## Members

### `cbHeaderLength`

The size, in bytes, of the header.

### `CredUIContextHandle`

A handle to the credential context.

### `UIInfo`

A pointer to a [CREDUI_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credui_infoa) structure that specifies information for the credential prompt dialog box.

### `dwAuthError`

Specifies why prompting for credentials is needed. A caller can pass this Windows error parameter, returned by another authentication call, to allow the dialog box to accommodate certain errors. For example, if the password expired status code is passed, the dialog box prompts the user to change the password on the account.

### `pInputAuthIdentity`

The opaque authentication identity data.

### `TargetName`

The name of the target.