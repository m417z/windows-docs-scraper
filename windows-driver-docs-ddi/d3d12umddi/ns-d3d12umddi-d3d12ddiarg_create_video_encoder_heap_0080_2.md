## Description

The **D3D12DDIARG_CREATE_VIDEO_ENCODER_HEAP_0080_2** structure specifies video encoder heap parameters.

## Members

### `NodeMask`

For a single GPU operation, set **NodeMask** to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only one bit can be set.

### `Flags`

A [**D3D12DDI_VIDEO_ENCODER_HEAP_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_heap_flags_0080) value that specifies the video encoder heap creation flags.

### `EncodeCodec`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_0080) value that identifies the codec of the associated encoder object.

### `EncodeProfile`

A [**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_profile_desc_0080_2) structure that identifies the codec's profile.

### `EncodeLevel`

A [**D3D12DDI_VIDEO_ENCODER_LEVEL_SETTING_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_level_setting_0080_2) structure that indicates the level for the specified codec and the profile in the associated encoder object.

### `ResolutionsListCount`

Number of lists that **pResolutionList** points to.

### `pResolutionList`

Pointer to a list of [**D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_resolution_desc_0080) structures that contain picture resolutions requested to be supported.

## Remarks

If support for resolution dynamic reconfiguration is not supported, only one resolution is passed to denote the desired target resolution.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDICAPS_VIDEO_ENCODER_HEAP_SIZE_DATA_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_heap_size_data_0080_2)

[**PFND3D12DDI_CALCPRIVATEVIDEOENCODERHEAPSIZE_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideoencoderheapsize_0080_2)

[**PFND3D12DDI_CREATEVIDEOENCODERHEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoderheap_0080_2)