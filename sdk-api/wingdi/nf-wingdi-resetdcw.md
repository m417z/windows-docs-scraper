# ResetDCW function

## Description

The **ResetDC** function updates the specified printer or plotter device context (DC) using the specified information.

## Parameters

### `hdc` [in]

A handle to the DC to update.

### `lpdm` [in]

A pointer to a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure containing information about the new DC.

## Return value

If the function succeeds, the return value is a handle to the original DC.

If the function fails, the return value is **NULL**.

## Remarks

An application will typically use the **ResetDC** function when a window receives a [WM_DEVMODECHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-devmodechange) message. **ResetDC** can also be used to change the paper orientation or paper bins while printing a document.

The **ResetDC** function cannot be used to change the driver name, device name, or the output port. When the user changes the port connection or device name, the application must delete the original DC and create a new DC with the new information.

An application can pass an information DC to the **ResetDC** function. In that situation, **ResetDC** will always return a printer DC.

**ICM:** The color profile of the DC specified by the *hdc* parameter will be reset based on the information contained in the **lpInitData** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure.

> [!NOTE]
> The wingdi.h header defines ResetDC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[DeviceCapabilities](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-devicecapabilitiesa)

[Escape](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-escape)