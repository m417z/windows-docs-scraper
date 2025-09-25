# _KEYBOARD_SCAN_STATE enumeration

## Description

The KEYBOARD_SCAN_STATE enumeration type indicates the scan state of an input byte from a keyboard.

## Constants

### `Normal`

Indicates that the current byte is a **Normal** scan code (a nonextended code).

### `GotE0`

Indicates that the current byte is an E0 extended scan code.

### `GotE1`

Indicates that the current byte is an E1 extended scan code.

## Remarks

This enumeration type is used as input to an optional [KbFilter_IsrHook](https://learn.microsoft.com/previous-versions/ff542294(v=vs.85)) routine, which can be supplied by a vendor-supplied keyboard filter driver.

## See also

[KbFilter_IsrHook](https://learn.microsoft.com/previous-versions/ff542294(v=vs.85))

[PI8042_KEYBOARD_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_isr)