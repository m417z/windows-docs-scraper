# IFileDialogCustomize::AddMenu

## Description

Adds a menu to the dialog.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the menu to add.

### `pszLabel` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the menu name as a null-terminated Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default state for this control is enabled and visible.

To add items to this control, use [IFileDialogCustomize::AddControlItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogcustomize-addcontrolitem).