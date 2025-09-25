# DXVAHD_INPUT_FORMAT_CAPS enumeration

## Description

Defines capabilities related to input formats for a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Constants

### `DXVAHD_INPUT_FORMAT_CAPS_RGB_INTERLACED:0x1`

The device can deinterlace an input stream that contains interlaced RGB video.

### `DXVAHD_INPUT_FORMAT_CAPS_RGB_PROCAMP:0x2`

The device can perform color adjustment on RGB video.

### `DXVAHD_INPUT_FORMAT_CAPS_RGB_LUMA_KEY:0x4`

The device can perform luma keying on RGB video.

### `DXVAHD_INPUT_FORMAT_CAPS_PALETTE_INTERLACED:0x8`

The device can deinterlace input streams with palettized color formats.

## Remarks

These flags define video processing capabilities that are usually not needed, and therefore are not required for DXVA-HD devices to support.

The first three flags relate to RGB support for functions that are normally applied to YCbCr video: deinterlacing, color adjustment, and luma keying. A DXVA-HD device that supports these functions for YCbCr is not required to support them for RGB input. Supporting RGB input for these functions is an additional capability, reflected by these constants. The driver might convert the input to another color space, perform the indicated function, and then convert the result back to RGB.

Similarly, a device that supports de-interlacing is not required to support deinterlacing of palettized formats. This capability is indicated by the **DXVAHD_INPUT_FORMAT_CAPS_PALETTE_INTERLACED** flag.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)