## Description

Describes a [ID3D12VideoEncoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoderheap). Pass this structure into [ID3D12VideoDevice3::CreateVideoEncoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice3-createvideoencoderheap) to create an instance of **ID3D12VideoEncoderHeap**.

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

## Remarks

If support for resolution dynamic reconfiguration is not supported, specify only one resolution in *pResolutionList*, denoting the desired target resolution.

## See also

[ID3D12VideoDecoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videodecoderheap)

[ID3D12VideoDevice3::CreateVideoEncoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice3-createvideoencoderheap)