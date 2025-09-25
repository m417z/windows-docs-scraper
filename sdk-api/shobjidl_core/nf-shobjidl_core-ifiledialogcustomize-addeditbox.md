# IFileDialogCustomize::AddEditBox

## Description

Adds an edit box control to the dialog.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the edit box to add.

### `pszText` [in]

Type: **LPCWSTR**

A pointer to a null-terminated Unicode string that provides the default text displayed in the edit box.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default state for this control is enabled and visible.

To add a label next to the edit box, place it in a visual group with [IFileDialogCustomize::StartVisualGroup](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogcustomize-startvisualgroup).