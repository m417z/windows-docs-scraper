# FLASHWINFO structure

## Description

Contains the flash status for a window and the number of times the system should flash the window.

## Members

### `cbSize`

The size of the structure, in bytes.

### `hwnd`

A handle to the window to be flashed. The window can be either opened or minimized.

### `dwFlags`

The flash status. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **FLASHW_ALL**<br><br>0x00000003 | Flash both the window caption and taskbar button. This is equivalent to setting the FLASHW_CAPTION | FLASHW_TRAY flags. |
| **FLASHW_CAPTION**<br><br>0x00000001 | Flash the window caption. |
| **FLASHW_STOP**<br><br>0 | Stop flashing. The system restores the window to its original state. |
| **FLASHW_TIMER**<br><br>0x00000004 | Flash continuously, until the FLASHW_STOP flag is set. |
| **FLASHW_TIMERNOFG**<br><br>0x0000000C | Flash continuously until the window comes to the foreground. |
| **FLASHW_TRAY**<br><br>0x00000002 | Flash the taskbar button. |

### `uCount`

The number of times to flash the window.

### `dwTimeout`

The rate at which the window is to be flashed, in milliseconds. If **dwTimeout** is zero, the function uses the default caret blink rate.

## See also

[FlashWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-flashwindowex)