# DwmIsCompositionEnabled function

## Description

Obtains a value that indicates whether Desktop Window Manager (DWM) composition is enabled. Applications on machines running Windows 7 or earlier can listen for composition state changes by handling the [WM_DWMCOMPOSITIONCHANGED](https://learn.microsoft.com/windows/desktop/dwm/wm-dwmcompositionchanged) notification.

## Parameters

### `pfEnabled` [out]

A pointer to a value that, when this function returns successfully, receives **TRUE** if DWM composition is enabled; otherwise, **FALSE**.

**Note** As of Windows 8, DWM composition is always enabled. If an app declares Windows 8 compatibility in their manifest, this function will receive a value of **TRUE** through *pfEnabled*. If no such manifest entry is found, Windows 8 compatibility is not assumed and this function receives a value of **FALSE** through *pfEnabled*. This is done so that older programs that interpret a value of **TRUE** to imply that high contrast mode is off can continue to make the correct decisions about rendering their images. (Note that this is a bad practice—you should use the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function with the **SPI_GETHIGHCONTRAST** flag to determine the state of high contrast mode.)

For more information, see [Supporting High Contrast Themes](https://learn.microsoft.com/windows/win32/controls/supporting-high-contrast-themes).

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.