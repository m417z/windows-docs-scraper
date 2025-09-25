# IInputObject::TranslateAcceleratorIO

## Description

Enables the object to process keyboard accelerators.

## Parameters

### `pMsg`

Type: **LPMSG**

The address of an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure that contains the keyboard message that is being translated.

## Return value

Type: **HRESULT**

Returns **S_OK** if the accelerator was translated, or **S_FALSE** otherwise.