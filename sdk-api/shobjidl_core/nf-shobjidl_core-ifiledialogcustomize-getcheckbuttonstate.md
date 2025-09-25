# IFileDialogCustomize::GetCheckButtonState

## Description

Gets the current state of a check button (check box) in the dialog.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the check box.

### `pbChecked` [out]

Type: **BOOL***

The address of a **BOOL** value that indicates whether the box is checked. **TRUE** means checked; **FALSE**, unchecked.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.