## Description

Describes an [ID3D12VideoEncoderHeap1](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoderheap1). Extends [D3D12_VIDEO_ENCODER_HEAP_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_heap_desc) with a power-of-two downscale factor for lower resolution frame analysis.

## Members

### `NodeMask`

The node mask specifying the physical adapter on which the video processor will be used. For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node, i.e. the device's physical adapter, to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Flags`

A bitwise or combination of values from the [D3D12_VIDEO_ENCODER_HEAP_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_heap_flags) enumeration specifying encoder heap creation options.

### `EncodeCodec`

A [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) specifying the codec of the associated encoder object.

### `EncodeProfile`

A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) specifying the profile for the selected codec in the associated encoder object.

### `EncodeLevel`

A [D3D12_VIDEO_ENCODER_LEVEL_SETTING](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_level_setting) specifying the level for the selected codec in the associated encoder object.

### `ResolutionsListCount`

The count of resolutions requested to be supported present in the *pResolutionList* field.

### `pResolutionList`

Pointer to an array of [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) specifying the list of resolutions requested to be supported.

### `Pow2DownscaleFactor`

When [D3D12_VIDEO_ENCODER_HEAP_FLAG_ALLOW_RATE_CONTROL_FRAME_ANALYSIS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_heap_flags) is set, indicates to the driver the downscaling factor for the 1st pass. The downscaled dimensions are calculated as InputWidth / 2^*Pow2DownscaleFactor* and InputHeight / 2^*Pow2DownscaleFactor*. When *Pow2DownscaleFactor* is 0 and the flag is set, the 1st pass is performed at full resolution.

## Remarks

If [D3D12_VIDEO_ENCODER_SUPPORT_FLAG_RESOLUTION_RECONFIGURATION_AVAILABLE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_support_flags) is supported, *Pow2DownscaleFactor* applies to all possible resolutions that can be dynamically switched between or used with this [ID3D12VideoEncoderHeap1](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoderheap1), listed in *pResolutionList*. When dynamically switching between resolutions, the 1st pass lower resolution is also adjusted accordingly.

## See also

[D3D12_VIDEO_ENCODER_HEAP_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_heap_desc)

[ID3D12VideoEncoderHeap1](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoderheap1)