# ICredentialProviderCredential::SetCheckboxValue

## Description

Enables a Logon UI and Credential UI to indicate that a checkbox value has changed.

## Parameters

### `dwFieldID` [in]

Type: **DWORD**

The identifier for the field to update.

### `bChecked` [in]

Type: **BOOL**

Indicates the new value for the checkbox. **TRUE** means the checkbox should be checked, **FALSE** means unchecked.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.