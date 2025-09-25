# ICredentialProviderCredentialEvents::SetFieldState

## Description

Communicates to the Logon UI or Credential UI that a field state has changed and that the UI should be updated.

## Parameters

### `pcpc` [in]

Type: **[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)***

The credential containing a field whose state is being set. This value should be set to **this**. See [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents) for more information.

### `dwFieldID` [in]

Type: **DWORD**

The unique ID of the field where the change occurred to generate the event.

### `cpfs` [in]

Type: **[CREDENTIAL_PROVIDER_FIELD_STATE](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_field_state)**

The value from the [CREDENTIAL_PROVIDER_FIELD_STATE](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_field_state) enumeration that specifies the new field state.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.