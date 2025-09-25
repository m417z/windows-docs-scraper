# DXVAHD_DEVICE_USAGE enumeration

## Description

Specifies the intended use for a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Constants

### `DXVAHD_DEVICE_USAGE_PLAYBACK_NORMAL:0`

Normal video playback. The graphics driver should expose a set of capabilities that are appropriate for real-time video playback.

### `DXVAHD_DEVICE_USAGE_OPTIMAL_SPEED:1`

Optimal speed. The graphics driver should expose a minimal set of capabilities that are optimized for performance.

Use this setting if you want better performance and can accept some reduction in video quality. For example, you might use this setting in power-saving mode or to play video thumbnails.

### `DXVAHD_DEVICE_USAGE_OPTIMAL_QUALITY:2`

Optimal quality. The graphics driver should expose its maximum set of capabilities.

Specify this setting to get the best video quality possible. It is appropriate for tasks such as video editing, when quality is more important than speed. It is not appropriate for real-time playback.

## Remarks

The graphics driver uses one of these enumeration constants as a hint when it creates the DXVA-HD device.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_CreateDevice](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-dxvahd_createdevice)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)