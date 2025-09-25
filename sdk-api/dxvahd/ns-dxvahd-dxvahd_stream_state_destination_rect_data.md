# DXVAHD_STREAM_STATE_DESTINATION_RECT_DATA structure

## Description

Specifies the destination rectangle for an input stream, when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `Enable`

Specifies whether to use the destination rectangle, or use the entire output surface. The default state value is **FALSE**.

| Value | Meaning |
| --- | --- |
| **TRUE** | Use the destination rectangle given in the **DestinationRect** member. |
| **FALSE** | Use the entire output surface as the destination rectangle. |

### `DestinationRect`

The *destination rectangle*, which defines the portion of the output surface where the source rectangle is blitted. The destination rectangle is given in pixel coordinates, relative to the output surface. The default value is an empty rectangle, (0, 0, 0, 0).

If the **Enable** member is **FALSE**, the **DestinationRect** member is ignored.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)