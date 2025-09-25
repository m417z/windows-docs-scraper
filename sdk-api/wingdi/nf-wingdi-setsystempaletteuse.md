# SetSystemPaletteUse function

## Description

The **SetSystemPaletteUse** function allows an application to specify whether the system palette contains 2 or 20 static colors. The default system palette contains 20 static colors. (Static colors cannot be changed when an application realizes a logical palette.)

## Parameters

### `hdc` [in]

A handle to the device context. This device context must refer to a device that supports color palettes.

### `use` [in]

The new use of the system palette. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SYSPAL_NOSTATIC** | The system palette contains two static colors (black and white). |
| **SYSPAL_NOSTATIC256** | The system palette contains no static colors. |
| **SYSPAL_STATIC** | The system palette contains static colors that will not change when an application realizes its logical palette. |

## Return value

If the function succeeds, the return value is the previous system palette. It can be either SYSPAL_NOSTATIC, SYSPAL_NOSTATIC256, or SYSPAL_STATIC.

If the function fails, the return value is SYSPAL_ERROR.

## Remarks

An application can determine whether a device supports palette operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

When an application window moves to the foreground and the SYSPAL_NOSTATIC value is set, the application must call the [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) function to save the current system colors setting. It must also call [SetSysColors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setsyscolors) to set reasonable values using only black and white. When the application returns to the background or terminates, the previous system colors must be restored.

If the function returns SYSPAL_ERROR, the specified device context is invalid or does not support color palettes.

An application must call this function only when its window is maximized and has the input focus.

If an application calls **SetSystemPaletteUse** with *uUsage* set to SYSPAL_NOSTATIC, the system continues to set aside two entries in the system palette for pure white and pure black, respectively.

After calling this function with *uUsage* set to SYSPAL_NOSTATIC, an application must take the following steps:

1. Realize the logical palette.
2. Call the [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) function to save the current system-color settings.
3. Call the [SetSysColors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setsyscolors) function to set the system colors to reasonable values using black and white. For example, adjacent or overlapping items (such as window frames and borders) should be set to black and white, respectively.
4. Send the [WM_SYSCOLORCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-syscolorchange) message to other top-level windows to allow them to be redrawn with the new system colors.

When the application's window loses focus or closes, the application must perform the following steps:

1. Call **SetSystemPaletteUse** with the *uUsage* parameter set to SYSPAL_STATIC.
2. Realize the logical palette.
3. Restore the system colors to their previous values.
4. Send the [WM_SYSCOLORCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-syscolorchange) message.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor)

[GetSystemPaletteUse](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getsystempaletteuse)

[SetSysColors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setsyscolors)