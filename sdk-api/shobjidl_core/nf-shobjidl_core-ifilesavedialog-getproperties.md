# IFileSaveDialog::GetProperties

## Description

Retrieves the set of property values for a saved item or an item in the process of being saved.

## Parameters

### `ppStore` [out]

Type: **[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)****

Address of a pointer to an [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) that receives the property values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can be called while the dialog is showing to retrieve the current set of values in the metadata collection pane. It can also be called after the dialog has closed, to retrieve the final set of values.

The call to this method will fail unless property collection has been turned on with a call to [IFileSaveDialog::SetCollectedProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifilesavedialog-setcollectedproperties).