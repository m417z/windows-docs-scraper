# IFileDialogCustomize::GetControlItemState

## Description

Gets the current state of an item in a container control found in the dialog.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the container control.

### `dwIDItem` [in]

Type: **DWORD**

The ID of the item.

### `pdwState` [out]

Type: **CDCONTROLSTATEF***

A pointer to a variable that receives one of more values from the [CDCONTROLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb762483(v=vs.85)) enumeration that indicate the current state of the control.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default state of a control item is enabled and visible. Items in control groups cannot be changed after they have been created, with the exception of their enabled and visible states.

Container controls include option button groups, combo boxes, drop-down lists on the **Open** or **Save** button, and menus.