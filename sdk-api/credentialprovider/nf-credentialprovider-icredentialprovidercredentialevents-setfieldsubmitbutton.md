# ICredentialProviderCredentialEvents::SetFieldSubmitButton

## Description

Enables credentials to set the field that the submit button appears adjacent to.

## Parameters

### `pcpc` [in]

Type: **[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)***

The credential whose submit button location is being set. This value should be set to **this**. See [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents) for more information.

### `dwFieldID` [in]

Type: **DWORD**

The unique field ID of the submit button.

### `dwAdjacentTo` [in]

Type: **DWORD**

The unique field ID of the field that the submit button should be adjacent to when this method completes.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.