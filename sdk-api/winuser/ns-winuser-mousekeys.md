# MOUSEKEYS structure

## Description

Contains information about the MouseKeys accessibility feature. When the MouseKeys feature is active, the user can use the numeric keypad to control the mouse pointer, and to click, double-click, drag, and drop. By pressing NUMLOCK, the user can toggle the numeric keypad between mouse control mode and normal operation.

## Members

### `cbSize`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the size, in bytes, of this structure.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of bit-flags that specify properties of the FilterKeys feature. The following bit-flag values are defined:

| Value | Meaning |
| --- | --- |
| **MKF_AVAILABLE**<br><br>0x00000002 | If this flag is set, the MouseKeys feature is available. |
| **MKF_CONFIRMHOTKEY**<br><br>0x00000008 | **Windows 95/98, Windows 2000:** A confirmation dialog box appears when the MouseKeys feature is activated by using the hot key. |
| **MKF_HOTKEYACTIVE**<br><br>0x00000004 | If this flag is set, the user can turn the MouseKeys feature on and off by using the hot key, which is LEFT ALT+LEFT SHIFT+NUM LOCK. |
| **MKF_HOTKEYSOUND**<br><br>0x00000010 | If this flag is set, the system plays a siren sound when the user turns the MouseKeys feature on or off by using the hot key. |
| **MKF_INDICATOR**<br><br>0x00000020 | **Windows 95/98, Windows 2000:** A visual indicator is displayed when the MouseKeys feature is on. |
| **MKF_LEFTBUTTONDOWN**<br><br>0x01000000 | **Windows 95/98, Windows 2000:** The left button is in the "down" state. |
| **MKF_LEFTBUTTONSEL**<br><br>0x10000000 | **Windows 95/98, Windows 2000:** The user has selected the left button for mouse-button actions. |
| **MKF_MODIFIERS**<br><br>0x00000040 | **Windows 95/98, Windows 2000:** The CTRL key increases cursor speed by the value specified by the **iCtrlSpeed** member, and the SHIFT key causes the cursor to delay briefly after moving a single pixel, allowing fine positioning of the cursor. If this value is not specified, the CTRL and SHIFT keys are ignored while the user moves the mouse cursor using the arrow keys. |
| **MKF_MOUSEKEYSON**<br><br>0x00000001 | If this flag is set, the MouseKeys feature is on. |
| **MKF_MOUSEMODE**<br><br>0x80000000 | **Windows 95/98, Windows 2000:** The system is processing numeric keypad input as mouse commands. |
| **MKF_REPLACENUMBERS**<br><br>0x00000080 | **Windows 95/98, Windows 2000:** The numeric keypad moves the mouse when the NUM LOCK key is on. If this flag is not specified, the numeric keypad moves the mouse cursor when the NUM LOCK key is off. |
| **MKF_RIGHTBUTTONDOWN**<br><br>0x02000000 | **Windows 95/98, Windows 2000:** The right button is in the "down" state. |
| **MKF_RIGHTBUTTONSEL**<br><br>0x20000000 | **Windows 95/98, Windows 2000:** The user has selected the right button for mouse-button actions. |

### `iMaxSpeed`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the maximum speed the mouse cursor attains when an arrow key is held down.

**Windows 95/98:** Range checking is not performed.

**Windows NT/2000:** Valid values are from 10 to 360.

### `iTimeToMaxSpeed`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the length of time, in milliseconds, that it takes for the mouse cursor to reach maximum speed when an arrow key is held down. Valid values are from 1000 to 5000.

### `iCtrlSpeed`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the multiplier to apply to the mouse cursor speed when the user holds down the CTRL key while using the arrow keys to move the cursor. this value is ignored if MKF_MODIFIERS is not set.

### `dwReserved1`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This member is reserved for future use. It must be set to zero.

### `dwReserved2`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This member is reserved for future use. It must be set to zero.

## Remarks

An application uses a **MOUSEKEYS** structure when calling the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function with the *uiAction* parameter set to the **SPI_GETMOUSEKEYS** or **SPI_SETMOUSEKEYS** value. When using **SPI_GETMOUSEKEYS**, an application must specify the **cbSize** member of the **MOUSEKEYS** structure; the **SystemParametersInfo** function fills the remaining members. An application must specify all structure members when using the **SPI_SETMOUSEKEYS** value.

If you call [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) with the **SPI_SETMOUSEKEYS** value, the following flags are ignored:

* **MKF_LEFTBUTTONDOWN**
* **MKF_LEFTBUTTONSEL**
* **MKF_MOUSEMODE**
* **MKF_RIGHTBUTTONDOWN**
* **MKF_RIGHTBUTTONSEL**

## See also

[Accessibility Structures](https://learn.microsoft.com/windows/desktop/WinAuto/accessibility-structures)

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)