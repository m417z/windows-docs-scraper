# IFileDialogCustomize::GetControlState

## Description

Gets the current visibility and enabled states of a given control.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the control in question.

### `pdwState` [out]

Type: **CDCONTROLSTATEF***

A pointer to a variable that receives one or more values from the [CDCONTROLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb762483(v=vs.85)) enumeration that indicate the current state of the control.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.