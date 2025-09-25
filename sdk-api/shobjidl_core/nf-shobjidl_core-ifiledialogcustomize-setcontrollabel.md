# IFileDialogCustomize::SetControlLabel

## Description

Sets the text associated with a control, such as button text or an edit box label.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the control whose text is to be changed.

### `pszLabel` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the text as a null-terminated Unicode string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Control labels can be changed at any time, including when the dialog is visible.