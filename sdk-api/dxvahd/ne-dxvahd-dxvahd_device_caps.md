# DXVAHD_DEVICE_CAPS enumeration

## Description

Defines video processing capabilities for a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Constants

### `DXVAHD_DEVICE_CAPS_LINEAR_SPACE:0x1`

The device can blend video content in linear color space. Most video content is gamma corrected, resulting in nonlinear values. If the DXVA-HD device sets this flag, it means the device converts colors to linear space before blending, which produces better results.

### `DXVAHD_DEVICE_CAPS_xvYCC:0x2`

The device supports the xvYCC color space for YCbCr data.

### `DXVAHD_DEVICE_CAPS_RGB_RANGE_CONVERSION:0x4`

The device can perform range conversion when the input and output are both RGB but use different color ranges (0-255 or 16-235, for 8-bit RGB).

### `DXVAHD_DEVICE_CAPS_YCbCr_MATRIX_CONVERSION:0x8`

The device can apply a matrix conversion to YCbCr values when the input and output are both YCbCr. For example, the driver can convert colors from BT.601 to BT.709.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)