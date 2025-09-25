# _D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES structure

## Description

The D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES contains values that indicate the dynamic range of each color channel of a video present target or a monitor.

## Members

### `FirstChannel`

The bit depth of the first color channel.

### `SecondChannel`

The bit depth of the second color channel.

### `ThirdChannel`

The bit depth of the third color channel.

### `FourthChannel`

Reserved.

## Remarks

The **VidPnTargetColorCoeffDynamicRanges** member of the [D3DKMDT_VIDPN_PRESENT_PATH](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_present_path) structure is a D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES structure.

## See also

[D3DKMDT_COLOR_BASIS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_color_basis)