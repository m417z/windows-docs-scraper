# ICredentialProviderCredential::GetComboBoxValueCount

## Description

Gets a count of the items in the specified combo box and designates which item should have initial selection.

## Parameters

### `dwFieldID` [in]

Type: **DWORD**

The identifier for the combo box to gather information about.

### `pcItems` [out]

Type: **DWORD***

A pointer to the number of items in the given combo box.

### `pdwSelectedItem` [out]

Type: **DWORD***

Contains a pointer to the item that receives initial selection.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Credential UI and Logon UI use this method to obtain the number of items in a combo box and designate which item should have initial selection.