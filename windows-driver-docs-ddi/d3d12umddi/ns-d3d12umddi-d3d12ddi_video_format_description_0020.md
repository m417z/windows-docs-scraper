# D3D12DDI_VIDEO_FORMAT_DESCRIPTION_0020 structure

## Description

Defines the combination of a pixel format and color space for a resource content description.

## Members

### `Format`

The format of the data. For more information, see the [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration.

### `ColorSpace`

The color space of the data. For more information, see the [DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/win32/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type) enumeration.

## Remarks

Conversions exposed through the decoder must have a hardware advantage compared to a conversion that could be accomplished through the app via a decode and a video process BLT. This typically means the video hardware write the unconverted reference frame and the converted output (both outputs) without a separate step that reads the unconverted reference frame to produce the converted output.

The one exception is that all drivers are required to support a conversion to remove the D3D12DDI_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY flag where the source and destination format, color space, and size are equal. Hardware may not actually require the D3D12DDI_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY flag, but if it is used, the driver may implement this conversion with a copy operation.

## See also

[DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/win32/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type)

[DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)