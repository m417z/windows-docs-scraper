# D3D11_1DDI_VIDEO_PROCESSOR_DEVICE_CAPS enumeration

## Description

Defines video processing capabilities for a Microsoft Direct3D 11 video processor.

## Constants

### `D3D11_1DDI_VIDEO_PROCESSOR_DEVICE_CAPS_LINEAR_SPACE`

The video processor can blend video content in linear color space. Most video content is gamma corrected, resulting in nonlinear values. This capability flag means that the video processor converts colors to linear space before blending, which produces better results.

### `D3D11_1DDI_VIDEO_PROCESSOR_DEVICE_CAPS_xvYCC`

The video processor supports the xvYCC color space for YCbCr data.

### `D3D11_1DDI_VIDEO_PROCESSOR_DEVICE_CAPS_RGB_RANGE_CONVERSION`

The video processor can perform range conversion when the input and output are both RGB but use different color ranges (0–255 or 16–235, for 8-bit RGB).

### `D3D11_1DDI_VIDEO_PROCESSOR_DEVICE_CAPS_YCbCr_MATRIX_CONVERSION`

The video processor can apply a matrix conversion to YCbCr values when the input and output are both YCbCr. For example, the driver can convert colors from BT.601 to BT.709.

### `D3D11_1DDI_VIDEO_PROCESSOR_DEVICE_CAPS_NOMINAL_RANGE`

The video processor can convert between luminance ranges when the input and output use different luminance ranges.

Supported starting with Windows 8.1.