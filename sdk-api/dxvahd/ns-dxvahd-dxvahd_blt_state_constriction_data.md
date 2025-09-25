# DXVAHD_BLT_STATE_CONSTRICTION_DATA structure

## Description

Specifies whether the output is downsampled in a blit operation, when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `Enable`

If **TRUE**, downsampling is enabled. Otherwise, downsampling is disabled and the **Size** member is ignored. The default state value is **FALSE** (downsampling is disabled).

### `Size`

The sampling size. The default value is (1,1).

## Remarks

If the **Enable** member is **TRUE**, the device downsamples the composed target rectangle to the size given in the **Size** member, and then scales it back to the size of the target rectangle.

The width and height of **Size** must be greater than zero. If the size is larger than the target rectangle, downsampling does not occur.

To use this state, the device must support downsampling, indicated by the **DXVAHD_FEATURE_CAPS_CONSTRICTION** capability flag. To query for this capability, call [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps). If the device supports downsampling, it sets the **DXVAHD_FEATURE_CAPS_CONSTRICTION** flag in the **FeatureCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure.

If the device does not support downsampling, the [IDXVAHD_VideoProcessor::SetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessbltstate) method fails for this state.

Downsampling is sometimes used to reduce the quality of premium content when other forms of content protection are not available.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_BLT_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_blt_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessbltstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)