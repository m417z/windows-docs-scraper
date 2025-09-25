# ICredentialProviderCredential::GetComboBoxValueAt

## Description

Gets the string label for a combo box entry at the given index.

## Parameters

### `dwFieldID` [in]

Type: **DWORD**

The identifier for the combo box to query.

### `dwItem`

Type: **DWORD**

The index of the desired item.

### `ppszItem` [out]

Type: **LPWSTR***

A pointer to the string value that receives the combo box label.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.