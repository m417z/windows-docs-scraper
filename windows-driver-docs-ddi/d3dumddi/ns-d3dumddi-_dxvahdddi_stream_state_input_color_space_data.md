# _DXVAHDDDI_STREAM_STATE_INPUT_COLOR_SPACE_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_INPUT_COLOR_SPACE_DATA structure describes stream-state data that specifies the color space of the input stream.

## Members

### `Type` [in]

A UINT value that specifies whether the input stream is video or graphics. The driver can optimize the processing and the filtering based on the stream type. The default value is 0, which indicates a video stream.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `RGB_Range` [in]

A UINT value that specifies whether the input stream is full range RGB (that is, 0 to 255) or limited range RGB (that is, 16 to 235). The default value is 0, which indicates full range RGB.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `YCbCr_Matrix` [in]

A UINT value that specifies whether the input stream is BT.601 (for standard digital television) or BT.709 (for high-definition television). The default value is 0, which indicates BT.601.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `YCbCr_xvYCC` [in]

A UINT value that specifies whether the input stream is conventional YCbCr or extended YCbCr (xvYCC). The default is 0, which indicates conventional YCbCr.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

### `Nominal_Range` [in]

A UINT value that specifies that the luminance range of YUV data is described by the [DXVAHDDDI_NOMINAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_nominal_range) enumeration. The default is zero, which indicates the studio luminance range of 16 to 255, inclusive [16, 235].

For more information on luminance range, see [YUV format ranges in Windows 8.1](https://learn.microsoft.com/windows-hardware/drivers/display/yuv-format-ranges).

Setting this member is equivalent to setting the fifth and sixth bits of the 32-bit **Value** member (0x00000030).

Supported starting with Windows 8.1.

### `Reserved` [in]

Reserved. Must be zero.

This member is equivalent to the remaining 26 bits (0xFFFFFFC0) of the 32-bit **Value** member.

### `Value` [in]

A 32-bit value that describes stream-state data that specifies the color space of the input stream.

## Remarks

If the driver does not set the DXVAHDDDI_DEVICE_CAPS_xvYCC value in the **DeviceCaps** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPDEVCAPS value set, the driver ignores the **YCbCr_xvYCC** member.

Either RGB or YCbCr flags that correspond to the color space of the input format are referred. However, the driver might have to perform the intermediate color space conversion, in which case both RGB and YCbCr flags are referred.

For more information about the intermediate color space conversion, see the **InputFormatCaps** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure.

For more information about color space, see [DXVAHDDDI_BLT_STATE_OUTPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_output_color_space_data).

## See also

[DXVAHDDDI_BLT_STATE_OUTPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_output_color_space_data)

[DXVAHDDDI_NOMINAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_nominal_range)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)