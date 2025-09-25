# CONTROLINFO structure

## Description

Contains parameters that describe a control's keyboard mnemonics and keyboard behavior. The structure is populated during the [IOleControl::GetControlInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrol-getcontrolinfo) method.

## Members

### `cb`

The size of the structure, in bytes.

### `hAccel`

A handle to an array of [ACCEL](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-accel) structures, each structure describing a keyboard mnemonic. The array is created with the [CreateAcceleratorTable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createacceleratortablea) function. The control always maintains the memory for this array; the caller of [IOleControl::GetControlInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrol-getcontrolinfo) should not attempt to free the memory.

### `cAccel`

The number of mnemonics described in the **hAccel** field. This value can be zero to indicate no mnemonics.

### `dwFlags`

Flags that indicate the keyboard behavior of the control. The possible values are:

* CTRLINFO_EATS_RETURN: When the control has the focus, it will process the Return key.
* CTRLINFO_EATS_ESCAPE: When the control has the focus, it will process the Escape key.

When the control has the focus, the dialog box containing the control cannot use the Return or Escape keys as mnemonics for the default and cancel buttons.

## See also

[IOleControl::GetControlInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iolecontrol-getcontrolinfo)