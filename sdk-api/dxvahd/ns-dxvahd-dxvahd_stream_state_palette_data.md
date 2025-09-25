# DXVAHD_STREAM_STATE_PALETTE_DATA structure

## Description

Contains the color palette entries for an input stream, when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `Count`

The number of palette entries. The default state value is 0.

### `pEntries`

A pointer to an array of **D3DCOLOR** values. For RGB streams, the palette entries use a D3DFMT_A8R8G8B8 (ARGB-32) representation. For YCbCr streams, the palette entries use an AYUV representation. The alpha channel is used for alpha blending; see [DXVAHD_STREAM_STATE_ALPHA_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_alpha_data).

## Remarks

This stream state is used for input streams that have a palettized color format. Palettized formats with 4 bits per pixel (bpp) use the first 16 entries in the list. Formats with 8 bpp use the first 256 entries.

If a pixel has a palette index greater than the number of entries, the device treats the pixel as being white with opaque alpha. For full-range RGB, this value will be (255, 255, 255, 255); for YCbCr the value will be (255, 235, 128, 128).

The caller allocates the **pEntries** array. Set the **Count** member to the number of elements in the array. When retrieving the state data, you can set the **pEntries** member to **NULL** to get the number of palette entries. The device will return the count in the **Count** member.

If the DXVA-HD device does not have the **DXVAHD_FEATURE_CAPS_ALPHA_PALETTE** capability, every palette entry must have an alpha value of 0xFF (opaque). Otherwise, an error is returned from [IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate).

To get the device capabilities, call [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps) and check the **FeatureCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)