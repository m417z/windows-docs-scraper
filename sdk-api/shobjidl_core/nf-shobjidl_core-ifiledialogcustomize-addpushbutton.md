# IFileDialogCustomize::AddPushButton

## Description

Adds a button to the dialog.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the button to add.

### `pszLabel` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the button text as a null-terminated Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default state for this control is enabled and visible.