## Description

Describes the downscaled input frame and reference frames for two pass frame analysis in a video encode operation.

## Members

### `pDownscaledFrame`

Pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) containing the downscaled input texture to perform two pass frame analysis. The downscaling factor is indicated by [D3D12_VIDEO_ENCODER_HEAP_DESC1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_heap_desc1).*Pow2DownscaleFactor*. When the 1st pass is skipped, *pDownscaledFrame* is not necessary and NULL can be passed.

### `Subresource`

Subresource index for *pDownscaledFrame*.

### `DownscaledReferences`

A D3D12_VIDEO_ENCODE_REFERENCE_FRAMES containing the downscaled reference frame textures to perform two pass frame analysis. The downscaling factor is indicated by [D3D12_VIDEO_ENCODER_HEAP_DESC1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_heap_desc1).*Pow2DownscaleFactor*.

## Remarks

The DPB snapshot and reference lists must be always mirrored for the parallel streams (full and downscaled resolution passes). *DownscaledReferences* and the corresponding full resolution reference frames must always have entries mirroring the same frames in the DPB, just in different resolutions.

## See also

[D3D12_VIDEO_ENCODER_HEAP_DESC1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_heap_desc1)