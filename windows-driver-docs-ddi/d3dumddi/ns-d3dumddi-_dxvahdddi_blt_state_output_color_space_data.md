# _DXVAHDDDI_BLT_STATE_OUTPUT_COLOR_SPACE_DATA structure

## Description

The DXVAHDDDI_BLT_STATE_OUTPUT_COLOR_SPACE_DATA structure describes data that specifies the color space of the output.

## Members

### `Usage` [in]

A UINT value that specifies whether the decode device should perform video playback (for example, presenting to the screen) or video processing (for example, video editing or authoring). The driver can perform the optimal color conversion based on the output device context. The default value is zero, which indicates video playback.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `RGB_Range` [in]

A UINT value that specifies whether the output is full range RGB (that is, 0 to 255) or limited range RGB (that is, 16 to 235). The default value is zero, which indicates full range RGB.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

### `YCbCr_Matrix` [in]

A UINT value that specifies whether the output is BT.601 (for standard digital television) or BT.709 (for high-definition television). The default value is zero, which indicates BT.601.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `YCbCr_xvYCC` [in]

A UINT value that specifies whether the output is conventional YCbCr or extended YCbCr (xvYCC). The default is zero, which indicates conventional YCbCr.

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

A 32-bit value that describes the color space of the output.

## Remarks

If the driver does not set the DXVAHDDDI_DEVICE_CAPS_xvYCC value in the **DeviceCaps** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPDEVCAPS value set, the output ignores the **YCbCr_xvYCC** member.

Either RGB or YCbCr flags that correspond to the color space of the output format are referred. However, the driver might have to perform the color space conversion to the background color, in which case both RGB and YCbCr flags are referred.

An application should set the **Usage** member such that the driver can perform the optimal color conversion. If usage is set to video playback (**Usage**=0), the driver can use a sophisticated algorithm to maximize the presentation experience (for example, auto gain control or dynamic gamma mapping is used to maximize the dynamic range while the super white is preserved). If the usage is set to video processing (**Usage**=1), the driver should accept the values that are set in the other members of DXVAHDDDI_BLT_STATE_OUTPUT_COLOR_SPACE_DATA and perform the conversion exactly as specified in the other members.

RGB output can be out of [0.0, 1.0] range ([0, 255], when 8-bit presentation is used) in the event that the output RGB type is a wide range format (for example, XR_BIAS, FP16, or FP32 format). Especially when the input stream is extended YCbCr (xvYCC), the RGB output range becomes wider than sRGB color space.

## See also

[DXVAHDDDI_NOMINAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_nominal_range)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)