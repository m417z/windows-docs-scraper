# GetSystemPaletteUse function

## Description

The **GetSystemPaletteUse** function retrieves the current state of the system (physical) palette for the specified device context (DC).

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

If the function succeeds, the return value is the current state of the system palette. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| SYSPAL_NOSTATIC | The system palette contains no static colors except black and white. |
| SYSPAL_STATIC | The system palette contains static colors that will not change when an application realizes its logical palette. |
| SYSPAL_ERROR | The given device context is invalid or does not support a color palette. |

## Remarks

By default, the system palette contains 20 static colors that are not changed when an application realizes its logical palette. An application can gain access to most of these colors by calling the [SetSystemPaletteUse](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setsystempaletteuse) function.

The device context identified by the *hdc* parameter must represent a device that supports color palettes.

An application can determine whether a device supports color palettes by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[SetSystemPaletteUse](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setsystempaletteuse)