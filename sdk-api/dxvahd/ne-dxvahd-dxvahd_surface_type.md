# DXVAHD_SURFACE_TYPE enumeration

## Description

Specifies the type of video surface created by a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Constants

### `DXVAHD_SURFACE_TYPE_VIDEO_INPUT:0`

A surface for an input stream. This surface type is equivalent to an off-screen plain surface in Microsoft Direct3D. The application can use the surface in Direct3D calls.

### `DXVAHD_SURFACE_TYPE_VIDEO_INPUT_PRIVATE:1`

A private surface for an input stream. This surface type is equivalent to an off-screen plain surface, except that the application cannot use the surface in Direct3D calls.

### `DXVAHD_SURFACE_TYPE_VIDEO_OUTPUT:2`

A surface for an output stream. This surface type is equivalent to an off-screen plain surface in Direct3D. The application can use the surface in Direct3D calls.

This surface type is recommended for video processing applications that need to lock the surface and access the surface memory. For video playback with optimal performance, a render-target surface or swap chain is recommended instead.

## Remarks

If the DXVA-HD device is a software plug-in and the surface type is **DXVAHD_SURFACE_TYPE_VIDEO_INPUT_PRIVATE**, the device can support format types that are not supported natively by the graphics driver. For example, if the application requests an AYUV surface, the device could allocate a surface with a surface type of **D3DFMT_A8R8G8B8**.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[IDXVAHD_Device::CreateVideoSurface](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-createvideosurface)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)