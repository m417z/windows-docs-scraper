# ICredentialProviderCredentialEvents::DeleteFieldComboBoxItem

## Description

Communicates to the Logon UI or Credential UI that an item should be deleted from a combo box and that the UI should be updated.

## Parameters

### `pcpc` [in]

Type: **[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)***

The credential containing the combo box that needs to be updated. This value should be set to **this**. See [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents) for more information.

### `dwFieldID` [in]

Type: **DWORD**

The unique ID of the combo box.

### `dwItem` [in]

Type: **DWORD**

The index of the item that is deleted.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.