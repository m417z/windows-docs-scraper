# PFND3D10DDI_SETTEXTFILTERSIZE callback function

## Description

The *SetTextFilterSize* function sets the width and height of the monochrome convolution filter.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*Width* [in]

The width of the monochrome convolution filter. The width can be from 1 to 7 texels.

### `unnamedParam3`

*Height* [in]

The height of the monochrome convolution filter. The height can be from 1 to 7 texels.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The number of samples that are required from a kernel's dimensions is actually (*Width* + 1) x (*Height* + 1), which can come out to from 4 to 64 samples. These settings apply across all samplers that are configured to use the D3D10_DDI_FILTER_TEXT_1BIT filter from the [D3D10_DDI_FILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_filter) enumeration.

*SetTextFilterSize* ensures that values that are supplied in the *Width* and *Height* parameters are in range. The default values for *Width* and *Height* are both 1, initially. The driver must set these default values during device creation.

The driver should not encounter any error, except for D3DDDIERR_DEVICEREMOVED. Therefore, if the driver passes any error, except for D3DDDIERR_DEVICEREMOVED, in a call to the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) function, the Direct3D runtime will determine that the error is critical. Even if the device was removed, the driver is not required to return D3DDDIERR_DEVICEREMOVED. However, if device removal interfered with the operation of *SetTextFilterSize* (which typically should not happen), the driver can return D3DDDIERR_DEVICEREMOVED.

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[D3D10_DDI_FILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_filter)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)