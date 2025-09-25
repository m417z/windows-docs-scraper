# ICredentialProviderCredential::GetCheckboxValue

## Description

Retrieves the checkbox value.

## Parameters

### `dwFieldID` [in]

Type: **DWORD**

The identifier for the field.

### `pbChecked` [out]

Type: **BOOL***

Indicates the state of the checkbox. **TRUE** indicates the checkbox is checked, otherwise **FALSE**.

### `ppszLabel` [out]

Type: **LPWSTR***

Points to the label on the checkbox.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.