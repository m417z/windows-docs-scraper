# ICredentialProviderCredentialEvents::SetFieldInteractiveState

## Description

Communicates to the Logon UI or Credential UI that the interactivity state of a field has changed and that the UI should be updated.

## Parameters

### `pcpc` [in]

Type: **[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)***

The credential containing a field whose interactivity state is being set. This value should be set to **this**. See [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents) for more information.

### `dwFieldID` [in]

Type: **DWORD**

The unique ID of the field.

### `cpfis` [in]

Type: **[CREDENTIAL_PROVIDER_FIELD_INTERACTIVE_STATE](https://learn.microsoft.com/windows/win32/api/credentialprovider/ne-credentialprovider-credential_provider_field_interactive_state)**

The new interactive state of the field.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.