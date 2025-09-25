# DXVAHD_DEVICE_TYPE enumeration

## Description

Specifies the type of Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Constants

### `DXVAHD_DEVICE_TYPE_HARDWARE:0`

Hardware device. Video processing is performed in the GPU by the driver.

### `DXVAHD_DEVICE_TYPE_SOFTWARE:1`

Software device. Video processing is performed in the CPU by a software plug-in.

### `DXVAHD_DEVICE_TYPE_REFERENCE:2`

Reference device. Video processing is performed in the CPU by a software plug-in.

### `DXVAHD_DEVICE_TYPE_OTHER:3`

Other. The device is neither a hardware device nor a software plug-in.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)