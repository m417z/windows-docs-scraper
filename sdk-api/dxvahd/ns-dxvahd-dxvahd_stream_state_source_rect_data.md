# DXVAHD_STREAM_STATE_SOURCE_RECT_DATA structure

## Description

Specifies the source rectangle for an input stream when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD)

## Members

### `Enable`

Specifies whether to blit the entire input surface or just the source rectangle. The default state value is **FALSE**.

| Value | Meaning |
| --- | --- |
| **TRUE** | Use the source rectangle specified in the **SourceRect** member. |
| **FALSE** | Blit the entire input surface. Ignore the **SourceRect** member. |

### `SourceRect`

The *source rectangle*, which defines the portion of the input sample that is blitted to the destination surface. The source rectangle is given in pixel coordinates, relative to the input surface. The default state value is an empty rectangle, (0, 0, 0, 0).

If the **Enable** member is **FALSE**, the **SourceRect** member is ignored.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)