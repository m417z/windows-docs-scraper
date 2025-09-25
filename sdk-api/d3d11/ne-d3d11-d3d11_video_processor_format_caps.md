# D3D11_VIDEO_PROCESSOR_FORMAT_CAPS enumeration

## Description

Defines capabilities related to input formats for a Microsoft Direct3D 11 video processor.

## Constants

### `D3D11_VIDEO_PROCESSOR_FORMAT_CAPS_RGB_INTERLACED:0x1`

The video processor can deinterlace an input stream that contains interlaced RGB video.

### `D3D11_VIDEO_PROCESSOR_FORMAT_CAPS_RGB_PROCAMP:0x2`

The video processor can perform color adjustment on RGB video.

### `D3D11_VIDEO_PROCESSOR_FORMAT_CAPS_RGB_LUMA_KEY:0x4`

The video processor can perform luma keying on RGB video.

### `D3D11_VIDEO_PROCESSOR_FORMAT_CAPS_PALETTE_INTERLACED:0x8`

The video processor can deinterlace input streams with palettized color formats.

## Remarks

These flags define video processing capabilities that usually are not needed, and that video devices are therefore not required to support.

The first three flags relate to RGB support for functions that are normally applied to YCbCr video: deinterlacing, color adjustment, and luma keying. A device that supports these functions for YCbCr is not required to support them for RGB input. Supporting RGB input for these functions is an additional capability, reflected by these constants. Note that the driver might convert the input to another color space, perform the indicated function, and then convert the result back to RGB.

Similarly, a device that supports deinterlacing is not required to support deinterlacing of palettized formats. This capability is indicated by the **D3D11_VIDEO_PROCESSOR_FORMAT_CAPS_PALETTE_INTERLACED** flag.

## See also

[D3D11_VIDEO_PROCESSOR_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_caps)

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)