# IFileDialog::AddPlace

## Description

Adds a folder to the list of places available for the user to open or save items.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that represents the folder to be made available to the user. This can only be a folder.

### `fdap` [in]

Type: **[FDAP](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-fdap)**

Specifies where the folder is placed within the list. See [FDAP](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-fdap).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[SHSetTemporaryPropertyForItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shsettemporarypropertyforitem) can be used to set a temporary [PKEY_ItemNameDisplay](https://learn.microsoft.com/windows/desktop/properties/props-system-itemnamedisplay) property on the item represented by the *psi* parameter. The value for this property will be used in place of the item's UI name.