# ICredentialProviderCredentialEvents::SetFieldCheckbox

## Description

Communicates to the Logon UI or Credential UI that a checkbox field has changed and that the UI should be updated.

## Parameters

### `pcpc` [in]

Type: **[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)***

The credential containing the checkbox field that is being set. This value should be set to **this**. See [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents) for more information.

### `dwFieldID` [in]

Type: **DWORD**

The unique field ID for the checkbox.

### `bChecked` [in]

Type: **BOOL**

The new state of the checkbox. **TRUE** indicates the checkbox should be checked, **FALSE** indicates it should not.

### `pszLabel` [in]

Type: **LPCWSTR**

The new string for the checkbox label.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.