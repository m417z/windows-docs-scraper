# ICredentialProviderCredentialEvents::AppendFieldComboBoxItem

## Description

Communicates to the Logon UI or Credential UI that a combo box needs an item appended and that the UI should be updated.

## Parameters

### `pcpc` [in]

Type: **[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)***

The credential containing the combo box that needs an item added. This value should be set to **this**. See [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents) for more information.

### `dwFieldID` [in]

Type: **DWORD**

The unique ID of the combo box.

### `pszItem` [in]

Type: **LPCWSTR**

The string that will be appended to the combo box as a new option.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.