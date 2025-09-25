# IFileDialogCustomize::AddText

## Description

Adds text content to the dialog.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the text to add.

### `pszText` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the text as a null-terminated Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default state for this control is enabled and visible.