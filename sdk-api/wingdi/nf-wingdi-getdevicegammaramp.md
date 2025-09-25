# GetDeviceGammaRamp function

## Description

The **GetDeviceGammaRamp** function gets the [gamma ramp](https://learn.microsoft.com/windows/win32/wcs/g) on direct color display boards having drivers that support downloadable gamma ramps in hardware.

> [!IMPORTANT]
> We strongly recommend that you don't use this API. Use of this API is subject to major limitations. See [SetDeviceGammaRamp](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-setdevicegammaramp) for more information.

## Parameters

### `hdc`

Specifies the device context of the direct color display board in question.

### `lpRamp`

Points to a buffer where the function can place the current gamma ramp of the color display board. The gamma ramp is specified in three arrays of 256 **WORD** elements each, which contain the mapping between RGB values in the frame buffer and digital-analog-converter (DAC) values. The sequence of the arrays is red, green, blue.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**.

## Example

```cpp
WORD gArray[3][256];
GetDeviceGammaRamp(handle, gArray);
// `handle` is the device context. See GetDC for more details.
// `gArray` will hold the gamma array values in a 2-D array
```

## Remarks

Direct color display modes do not use color lookup tables and are usually 16, 24, or 32 bit. Not all direct color video boards support loadable gamma ramps. **GetDeviceGammaRamp** succeeds only for devices with drivers that support downloadable gamma ramps in hardware.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)