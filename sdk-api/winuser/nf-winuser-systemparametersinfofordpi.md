# SystemParametersInfoForDpi function

## Description

Retrieves the value of one of the system-wide parameters, taking into account the provided DPI value.

## Parameters

### `uiAction` [in]

The system-wide parameter to be retrieved. This function is only intended for use with **SPI_GETICONTITLELOGFONT**, **SPI_GETICONMETRICS**, or **SPI_GETNONCLIENTMETRICS**. See [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) for more information on these values.

### `uiParam` [in]

A parameter whose usage and format depends on the system parameter being queried. For more information about system-wide parameters, see the *uiAction* parameter. If not otherwise indicated, you must specify zero for this parameter.

### `pvParam` [in, out]

A parameter whose usage and format depends on the system parameter being queried. For more information about system-wide parameters, see the *uiAction* parameter. If not otherwise indicated, you must specify **NULL** for this parameter. For information on the **PVOID** datatype, see [Windows Data Types](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types).

### `fWinIni` [in]

Has no effect for with this API. This parameter only has an effect if you're setting parameter.

### `dpi` [in]

The DPI to use for scaling the metric.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function returns a similar result as [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa), but scales it according to an arbitrary DPI you provide (if appropriate). It only scales with the following possible values for *uiAction*: **SPI_GETICONTITLELOGFONT**, **SPI_GETICONMETRICS**, **SPI_GETNONCLIENTMETRICS**. Other possible *uiAction* values do not provide ForDPI behavior, and therefore this function returns 0 if called with them.

For *uiAction* values that contain strings within their associated structures, only Unicode ([LOGFONTW](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)) strings are supported in this function.