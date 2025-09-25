# IFileDialogCustomize::GetSelectedControlItem

## Description

Gets a particular item from specified container controls in the dialog.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the container control.

### `pdwIDItem` [out]

Type: **DWORD***

 The ID of the item that the user selected in the control.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To determine the user's final choice, this method can be called on option button groups, combo boxes, and drop-down lists on the **Open** or **Save** button after the dialog has closed. This method cannot be called on menus.

For option button groups and combo boxes, this method can also be called while the dialog is showing, to determine the current choice.