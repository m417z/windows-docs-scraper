# IFileDialogCustomize::SetControlItemText

## Description

Sets the text of a control item. For example, the text that accompanies a radio button or an item in a menu.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the container control.

### `dwIDItem` [in]

Type: **DWORD**

The ID of the item.

### `pszLabel` [in]

Type: **LPCWSTR**

A pointer to a null-terminated buffer that contains a Unicode string with the text.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default state of a control item is enabled and visible. Items in control groups cannot be changed after they have been created, with the exception of their enabled and visible states.

Container controls include option button groups, combo boxes, drop-down lists on the **Open** or **Save** button, and menus.