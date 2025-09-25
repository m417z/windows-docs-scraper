# ICredentialProviderCredentialEvents::SetFieldString

## Description

Communicates to the Logon UI or Credential UI that the string associated with a field has changed and that the UI should be updated.

## Parameters

### `pcpc` [in]

Type: **[ICredentialProviderCredential](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredential)***

The credential containing a field whose interactivity state is being set. This value should be set to **this**. See [ICredentialProviderCredentialEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialprovidercredentialevents) for more information.

### `dwFieldID` [in]

Type: **DWORD**

The unique ID of the field for which the string is being set.

### `psz` [in]

Type: **LPCWSTR**

A pointer to the new string for the field.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.