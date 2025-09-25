# ICredentialProviderCredentialEvents::SetFieldComboBoxSelectedItem

## Description

Communicates to the Logon UI or Credential UI that the selected item in a combo box has changed and that the UI should be updated.

## Parameters

### `pcpc` [in]

Type: **[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)***

The credential containing the combo box being set. This value should be set to **this**. See [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents) for more information.

### `dwFieldID` [in]

Type: **DWORD**

The unique ID of the combo box.

### `dwSelectedItem` [in]

Type: **DWORD**

The index of the item to select in the combo box.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.