# IFileDialogCustomize::AddControlItem

## Description

Adds an item to a container control in the dialog.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

 The ID of the container control to which the item is to be added.

### `dwIDItem` [in]

Type: **DWORD**

The ID of the item.

### `pszLabel` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the item's text, which can be either a label or, in the case of a drop-down list, the item itself. This text is a null-terminated Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default state for this item is enabled and visible. Items in control groups cannot be changed after they have been created, with the exception of their enabled and visible states.

Container controls include option button groups, combo boxes, drop-down lists on the **Open** or **Save** button, and menus.