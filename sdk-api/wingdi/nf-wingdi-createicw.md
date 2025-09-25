# CreateICW function

## Description

The **CreateIC** function creates an information context for the specified device. The information context provides a fast way to get information about the device without creating a device context (DC). However, GDI drawing functions cannot accept a handle to an information context.

## Parameters

### `pszDriver` [in]

A pointer to a null-terminated character string that specifies the name of the device driver (for example, Epson).

### `pszDevice` [in]

A pointer to a null-terminated character string that specifies the name of the specific output device being used, as shown by the Print Manager (for example, Epson FX-80). It is not the printer model name. The *lpszDevice* parameter must be used.

### `pszPort`

This parameter is ignored and should be set to **NULL**. It is provided only for compatibility with 16-bit Windows.

### `pdm` [in]

A pointer to a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure containing device-specific initialization data for the device driver. The [DocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/documentproperties) function retrieves this structure filled in for a specified device. The *lpdvmInit* parameter must be **NULL** if the device driver is to use the default initialization (if any) specified by the user.

## Return value

If the function succeeds, the return value is the handle to an information context.

If the function fails, the return value is **NULL**.

## Remarks

When you no longer need the information DC, call the [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc) function.

> [!NOTE]
> The wingdi.h header defines CreateIC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[DocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/documentproperties)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)