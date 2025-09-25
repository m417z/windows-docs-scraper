# DrvIcmSetDeviceGammaRamp function

## Description

The **DrvIcmSetDeviceGammaRamp** function sets the hardware [gamma ramp](https://learn.microsoft.com/windows-hardware/drivers/) of the specified display device.

## Parameters

### `dhpdev`

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/). This identifies the physical device whose gamma ramp is to be set.

### `iFormat`

Specifies the data format of the buffer to which *lpRamp* points. This parameter is always IGRF_RGB_256WORDS.

### `lpRamp`

Pointer to the buffer containing the gamma ramp to be set on the device. The format of the data in this buffer is determined by *iFormat*.

When *iFormat* is IGRF_RGB_256WORDS, *lpRamp* points to a [GAMMARAMP](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gammaramp) structure that defines the 256-entry ramps to be set for each of the red, blue, and green color channels. Each value is described using 16-bit precision. If the hardware has fewer bits of precision, it should downshift and use the most significant bits, without rounding.

## Return value

**DrvIcmSetDeviceGammaRamp** returns **TRUE** upon success. Otherwise, it returns **FALSE**.

## Remarks

Drivers for display devices with loadable hardware gamma ramps should implement this function.

**DrvIcmSetDeviceGammaRamp** should fail if it is called with any other value besides IGRF_RGB_256WORDS in *iFormat*.

The driver hooks this function by setting the GCAPS2_CHANGEGAMMARAMP flag in the **flGraphicsCaps2** field of the DEVINFO structure passed to [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev). If the driver is running in a palettized 8bpp mode, this capability is optional.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)