# DXVAHD_BLT_STATE_TARGET_RECT_DATA structure

## Description

Specifies the target rectangle for blitting, when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `Enable`

Specifies whether to use the target rectangle. The default state value is **FALSE**.

| Value | Meaning |
| --- | --- |
| **TRUE** | Use the target rectangle specified by the **TargetRect** member. |
| **FALSE** | Use the entire destination surface as the target rectangle. Ignore the **TargetRect** member. |

### `TargetRect`

Specifies the *target rectangle*. The target rectangle is the area within the destination surface where the output will be drawn. The target rectangle is given in pixel coordinates, relative to the destination surface. The default state value is an empty rectangle, (0, 0, 0, 0).

If the **Enable** member is **FALSE**, the **TargetRect** member is ignored.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_BLT_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_blt_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessbltstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)