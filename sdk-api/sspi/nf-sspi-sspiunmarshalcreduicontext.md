# SspiUnmarshalCredUIContext function

## Description

Deserializes credential information obtained by a credential provider during a previous call to the [ICredentialProvider::SetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setserialization) method.

## Parameters

### `MarshaledCredUIContext` [in]

The serialized credential information obtained as the **rgbSerialization** member of the [CREDENTIAL_PROVIDER_CREDENTIAL_SERIALIZATION](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_credential_serialization) structure retrieved from a call to the [ICredentialProvider::SetSerialization](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setserialization) method.

### `MarshaledCredUIContextLength` [in]

The size, in bytes, of the *MarshaledCredUIContext* buffer.

### `CredUIContext` [out]

A pointer to a [SEC_WINNT_CREDUI_CONTEXT](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_credui_context) structure that specifies the deserialized credential information.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.