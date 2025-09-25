# IFileDialogCustomize::RemoveControlItem

## Description

Removes an item from a container control in the dialog.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the container control from which the item is to be removed.

### `dwIDItem` [in]

Type: **DWORD**

The ID of the item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Container controls include option button groups, combo boxes, drop-down lists on the **Open** or **Save** button, and menus.