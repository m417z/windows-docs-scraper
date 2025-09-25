# ID3D11VideoContext::VideoProcessorSetStreamAlpha

## Description

Sets the planar alpha for an input stream on the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `Enable` [in]

Specifies whether alpha blending is enabled.

### `Alpha` [in]

The planar alpha value. The value can range from 0.0 (transparent) to 1.0 (opaque).
If *Enable* is **FALSE**, this parameter is ignored.

## Remarks

To use this feature, the driver must support stereo video, indicated by the [D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_ALHPA_STREAM](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_caps) capability flag. To query for this capability, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps).

Alpha blending is disabled by default.

For each pixel, the destination color value is computed as follows:

`Cd = Cs * (As * Ap * Ae) + Cd * (1.0 - As * Ap * Ae)`

where:

* `Cd` = The color value of the destination pixel
* `Cs` = The color value of the source pixel
* `As` = The per-pixel source alpha
* `Ap` = The planar alpha value
* `Ae` = The palette-entry alpha value, or 1.0 (see Note)

**Note** Palette-entry alpha values apply only to palettized color formats, and only when the device supports the **D3D11_VIDEO_PROCESSOR_FEATURE_CAPS_ALPHA_PALETTE** capability. Otherwise, this factor equals 1.0.

The destination alpha value is computed according to the alpha fill mode. For more information, see [ID3D11VideoContext::VideoProcessorSetOutputAlphaFillMode](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-videoprocessorsetoutputalphafillmode).

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)