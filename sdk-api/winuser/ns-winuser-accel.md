# ACCEL structure

## Description

Defines an accelerator key used in an accelerator table.

## Members

### `fVirt`

Type: **BYTE**

The accelerator behavior. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **FALT**<br><br>0x10 | The ALT key must be held down when the accelerator key is pressed. |
| **FCONTROL**<br><br>0x08 | The CTRL key must be held down when the accelerator key is pressed. |
| **FNOINVERT**<br><br>0x02 | No top-level menu item is highlighted when the accelerator is used. If this flag is not specified, a top-level menu item will be highlighted, if possible, when the accelerator is used. This attribute is obsolete and retained only for backward compatibility with resource files designed for 16-bit Windows. |
| **FSHIFT**<br><br>0x04 | The SHIFT key must be held down when the accelerator key is pressed. |
| **FVIRTKEY**<br><br>TRUE | The **key** member specifies a virtual-key code. If this flag is not specified, **key** is assumed to specify a character code. |

### `key`

Type: **WORD**

The accelerator key. This member can be either a [virtual-key code](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes) or a character code.

### `cmd`

Type: **WORD**

The accelerator identifier. This value is placed in the low-order word of the *wParam* parameter of the [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) or [WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand) message when the accelerator is pressed.

## See also

**Conceptual**

[Keyboard Accelerators](https://learn.microsoft.com/windows/desktop/menurc/keyboard-accelerators)

**Reference**

[WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command)

[WM_SYSCOMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-syscommand)