# DXVAHD_BLT_STATE_ALPHA_FILL_DATA structure

## Description

Specifies how the output alpha values are calculated for blit operations when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `Mode`

Specifies the alpha fill mode, as a member of the [DXVAHD_ALPHA_FILL_MODE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_alpha_fill_mode) enumeration.

If the **FeatureCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure does not contain the **DXVAHD_FEATURE_CAPS_ALPHA_FILL** flag, the alpha fill mode must be set to **DXVAHD_ALPHA_FILL_MODE_OPAQUE**.

The default state value is **DXVAHD_ALPHA_FILL_MODE_OPAQUE**.

### `StreamNumber`

Zero-based index of the input stream to use for the alpha values. This member is used when the alpha fill mode is **DXVAHD_ALPHA_FILL_MODE_SOURCE_STREAM**; otherwise, the value is ignored.

To get the maximum number of streams, call [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps) and check the **MaxStreamStates** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_BLT_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_blt_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessbltstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)