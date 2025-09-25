# IFileSaveDialog::SetProperties

## Description

Provides a property store that defines the default values to be used for the item being saved.

## Parameters

### `pStore` [in]

Type: **[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)***

Pointer to the interface that represents the property store that contains the associated metadata.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can be called at any time before the dialog is opened or while the dialog is showing. If an item has inherent properties, this method should be called with those properties before showing the dialog.

When using **Save As**, the application should provide the properties of the item being saved to the **Save** dialog. Those properties should be retreived from the original item by calling [GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore) with the [GPS_HANDLERPROPERTIESONLY](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) flag.

To retrieve the properties of the saved item (which may have been modified by the user) after the dialog closes, call [IFileSaveDialog::GetProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifilesavedialog-getproperties).

To turn on property collection and indicate which properties should be displayed in the **Save** dialog, use [IFileSaveDialog::SetCollectedProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifilesavedialog-setcollectedproperties).

## See also

[IFileSaveDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifilesavedialog)

[IFileSaveDialog::GetProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifilesavedialog-getproperties)

[IFileSaveDialog::SetCollectedProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifilesavedialog-setcollectedproperties)