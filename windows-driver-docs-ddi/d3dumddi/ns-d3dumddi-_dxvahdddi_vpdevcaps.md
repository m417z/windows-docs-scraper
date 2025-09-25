# _DXVAHDDDI_VPDEVCAPS structure

## Description

The DXVAHDDDI_VPDEVCAPS structure describes the video processor capabilities that the decode device supports.

## Members

### `Reserved` [in]

Reserved. Must be zero.

### `DeviceCaps` [out]

A bitwise OR of the following values from the DXVAHDDDI_DEVICE_CAPS enumeration to indicate device-specific capabilities.

#### DXVAHDDDI_DEVICE_CAPS_LINEAR_SPACE (0x1)

The driver can blend video content in linear space. Because the video content is traditionally in non-linear space and gamma 2.2 corrected ([sRGB](https://go.microsoft.com/fwlink/p/?linkid=10112)), the driver can convert the video content to linear space before performing blending operations to achieve better results.

#### DXVAHDDDI_DEVICE_CAPS_xvYCC (0x2)

The driver can perform video processing while retaining the extended gamut color when the driver inputs from and outputs to the YCbCr format type.

#### DXVAHDDDI_DEVICE_CAPS_RGB_RANGE_CONVERSION (0x4)

The driver can perform the range conversion when both input and output are RGB color space but the range is different (for example, the input is full range RGB and the output is limited range RGB). If this value is not set, the driver ignores the RGB range and composes the RGB input stream to the RGB output without changing the range.

#### DXVAHDDDI_DEVICE_CAPS_YCbCr_MATRIX_CONVERSION (0x8)

The driver can perform the matrix conversion when both input and output are YCbCr color space but the matrix is different (for example, the input is BT.601 and the output is BT.709). If this value is not set, the driver ignores the YCbCr matrix and composes the YCbCr input stream to the YCbCr output without changing the matrix.

#### DXVAHDDDI_DEVICE_CAPS_NOMINAL_RANGE (0x10)

The video processor can convert between luminance ranges when the input and output use different luminance ranges.

For more information on luminance range, see [YUV format ranges in Windows 8.1](https://learn.microsoft.com/windows-hardware/drivers/display/yuv-format-ranges).

Supported starting with Windows 8.1.

The driver determines that the XR_BIAS, FP16, and FP32 formats (wide gamut formats) are in linear space and so can retain the extended gamut color regardless of whether the preceding capability values are set.

### `FeatureCaps` [out]

A bitwise OR of the following values from the DXVAHDDDI_FEATURE_CAPS enumeration to indicate feature-specific capabilities.

#### DXVAHDDDI_FEATURE_CAPS_ALPHA_FILL (0x1)

The driver can set the alpha values inside the target rectangle on the output surface as specified for the alpha-fill mode. For more information about this operation, see [DXVAHDDDI_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_alpha_fill_data).

#### DXVAHDDDI_FEATURE_CAPS_CONSTRICTION (0x2)

The driver can down-sample the composed target rectangle. For more information about this operation, see [DXVAHDDDI_BLT_STATE_CONSTRICTION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_constriction_data).

#### DXVAHDDDI_FEATURE_CAPS_LUMA_KEY (0x4)

The driver can make pixels within a luma-key range transparent. For more information about this operation, see [DXVAHDDDI_STREAM_STATE_LUMA_KEY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_luma_key_data).

#### DXVAHDDDI_FEATURE_CAPS_ALPHA_PALETTE (0x8)

The driver can apply the alpha value of the palette entry. For more information about alpha blending, see [DXVAHDDDI_STREAM_STATE_ALPHA_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_alpha_data).

#### DXVAHDDDI_FEATURE_CAPS_ROTATION (0x10)

The driver can apply discrete display rotation values to the display output surface. For more information about this operation, see [DXVAHDDDI_STREAM_STATE_ROTATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_rotation_data).

Supported starting with Windows 8.

### `FilterCaps` [out]

A bitwise OR of the following values from the DXVAHDDDI_FILTER_CAPS enumeration to indicate filter-specific capabilities.

#### DXVAHDDDI_FILTER_CAPS_BRIGHTNESS (0x1)

The driver supports brightness ProcAmp.

#### DXVAHDDDI_FILTER_CAPS_CONTRAST (0x2)

The driver supports contrast ProcAmp.

#### DXVAHDDDI_FILTER_CAPS_HUE (0x4)

The driver supports hue ProcAmp.

#### DXVAHDDDI_FILTER_CAPS_SATURATION (0x8)

The driver supports saturation ProcAmp.

#### DXVAHDDDI_FILTER_CAPS_NOISE_REDUCTION (0x10)

The driver supports noise-reduction filter.

#### DXVAHDDDI_FILTER_CAPS_EDGE_ENHANCEMENT (0x20)

The driver supports edge-enhancement filter.

#### DXVAHDDDI_FILTER_CAPS_ANAMORPHIC_SCALING (0x40)

The driver can scale from the source rectangle to the destination rectangle linearly or nonlinearly. If the driver has this capability, it can stretch 4:3 standard video content to 16:9 widescreen.

### `InputFormatCaps` [out]

A bitwise OR of the following values from the DXVAHDDDI_INPUT_FORMAT_CAPS enumeration to indicate input-format-specific capabilities.

#### DXVAHDDDI_INPUT_FORMAT_CAPS_RGB_INTERLACED (0x1)

The driver can deinterlace the input stream with RGB format type.

#### DXVAHDDDI_INPUT_FORMAT_CAPS_RGB_PROCAMP (0x2)

The driver can apply a ProcAmp filter to the input stream with RGB format type.

#### DXVAHDDDI_INPUT_FORMAT_CAPS_RGB_LUMA_KEY (0x4)

The driver can luma-key the input stream with RGB format type.

#### DXVAHDDDI_INPUT_FORMAT_CAPS_PALETTE_INTERLACED (0x8)

The driver can deinterlace the input stream with palettized format type.

The driver can support the preceding capabilities rather than supporting rarely used video processing to the input frames. Because supporting these capabilities requires extra steps in the video processor pipeline, the driver might not support them.

If the driver supports these capabilities, the driver might require a certain color space to perform the processing to the input stream. For example, ProcAmp and the luma keying are performed in YCbCr color space. The driver refers the color space of the stream state to perform the intermediate color conversion.

For example, when the driver sets the **RGB_Range** and **YCbCr_Matrix** members of [DXVAHDDDI_STREAM_STATE_INPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_input_color_space_data) to 0 and 1 respectively, the driver converts from full range RGB to BT.709 YCbCr before the driver applies ProcAmp, and then converts the input stream back to full range RGB.

### `InputPool` [out]

A [D3DDDI_POOL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_pool)-typed value that indicates the memory pool from which the input surfaces should be allocated.

### `OutputFormatCount` [out]

The number of supported output formats. The driver returns an array of [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration types for the output formats that the decode device supports when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPOUTPUTFORMATS value set.

### `InputFormatCount` [out]

The number of supported input formats. The driver returns an array of [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration types for the input formats that the decode device supports when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPINPUTFORMATS value set.

### `VideoProcessorCount` [out]

The number of supported video processors. The driver returns an array of [DXVAHDDDI_VPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpcaps) structures for the capabilities for each video processor that the decode device supports when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPCAPS value set.

### `MaxInputStreams` [out]

The driver can enable the maximum number of input streams at a time.

### `MaxStreamStates` [out]

The maximum number of stream states.

## Remarks

The user-mode display driver returns a pointer to a populated DXVAHDDDI_VPDEVCAPS structure in the **pData** member of the [D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure when its [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPDEVCAPS value set in the **Type** member of D3DDDIARG_GETCAPS.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DDDI_POOL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_pool)

[DXVAHDDDI_VPCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpcaps)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)