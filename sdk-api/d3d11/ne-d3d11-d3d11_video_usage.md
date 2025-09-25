# D3D11_VIDEO_USAGE enumeration

## Description

Specifies the intended use for a video processor.

## Constants

### `D3D11_VIDEO_USAGE_PLAYBACK_NORMAL:0`

Normal video playback. The graphics driver should expose a set of capabilities that are appropriate for real-time video playback.

### `D3D11_VIDEO_USAGE_OPTIMAL_SPEED:1`

Optimal speed. The graphics driver should expose a minimal set of capabilities that are optimized for performance.

Use this setting if you want better performance and can accept some reduction in video quality. For example, you might use this setting in power-saving mode or to play video thumbnails.

### `D3D11_VIDEO_USAGE_OPTIMAL_QUALITY:2`

Optimal quality. The graphics driver should expose its maximum set of capabilities.

Specify this setting to get the best video quality possible. It is appropriate for tasks such as video editing, when quality is more important than speed. It is not appropriate for real-time playback.

## See also

[D3D11_VIDEO_PROCESSOR_CONTENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_content_desc)

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)