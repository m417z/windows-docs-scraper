# CreateDCA function

## Description

The **CreateDC** function creates a device context (DC) for a device using the specified name.

## Parameters

### `pwszDriver`

A pointer to a null-terminated character string that specifies either DISPLAY or the name of a specific display device. For printing, we recommend that you pass **NULL** to *lpszDriver* because GDI ignores *lpszDriver* for printer devices.

### `pwszDevice` [in]

A pointer to a null-terminated character string that specifies the name of the specific output device being used, as shown by the Print Manager (for example, Epson FX-80). It is not the printer model name. The *lpszDevice* parameter must be used.

To obtain valid names for displays, call [EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa).

If *lpszDriver* is DISPLAY or the device name of a specific display device, then *lpszDevice* must be **NULL** or that same device name. If *lpszDevice* is **NULL**, then a DC is created for the primary display device.

If there are multiple monitors on the system, calling `CreateDC(TEXT("DISPLAY"),NULL,NULL,NULL)` will create a DC covering all the monitors.

### `pszPort`

This parameter is ignored and should be set to **NULL**. It is provided only for compatibility with 16-bit Windows.

### `pdm` [in]

A pointer to a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure containing device-specific initialization data for the device driver. The [DocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/documentproperties) function retrieves this structure filled in for a specified device. The *pdm* parameter must be **NULL** if the device driver is to use the default initialization (if any) specified by the user.

If *lpszDriver* is DISPLAY, *pdm* must be **NULL**; GDI then uses the display device's current [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea).

## Return value

If the function succeeds, the return value is the handle to a DC for the specified device.

If the function fails, the return value is **NULL**.

## Remarks

Note that the handle to the DC can only be used by a single thread at any one time.

For parameters *lpszDriver* and *lpszDevice*, call [EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa) to obtain valid names for displays.

When you no longer need the DC, call the [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc) function.

If *lpszDriver* or *lpszDevice* is DISPLAY, the thread that calls **CreateDC** owns the **HDC** that is created. When this thread is destroyed, the **HDC** is no longer valid. Thus, if you create the **HDC** and pass it to another thread, then exit the first thread, the second thread will not be able to use the **HDC**.

When you call **CreateDC** to create the **HDC** for a display device, you must pass to *pdm* either **NULL** or a pointer to [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) that matches the current **DEVMODE** of the display device that *lpszDevice* specifies. We recommend to pass **NULL** and not to try to exactly match the **DEVMODE** for the current display device.

When you call **CreateDC** to create the **HDC** for a printer device, the printer driver validates the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea). If the printer driver determines that the **DEVMODE** is invalid (that is, printer driver can’t convert or consume the DEVMODE), the printer driver provides a default **DEVMODE** to create the HDC for the printer device.

**ICM:** To enable ICM, set the **dmICMMethod** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure (pointed to by the *pInitData* parameter) to the appropriate value.

#### Examples

For an example, see [Capturing an Image](https://learn.microsoft.com/windows/desktop/gdi/capturing-an-image).

> [!NOTE]
> The wingdi.h header defines CreateDC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[DOCINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-docinfoa)

[DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[DocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/documentproperties)

[EnumDisplayDevices](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaydevicesa)

[Multiple Display Monitors](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors)

[StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca)