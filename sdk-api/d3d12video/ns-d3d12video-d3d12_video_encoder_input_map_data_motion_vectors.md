## Description

Contains motion vectors input map data for the GPU texture input path of [ID3D12VideoEncodeCommandList4::ResolveInputParamLayout](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveinputparamlayout).

## Members

### `MotionSearchModeConfiguration`

A [D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_CONFIG](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_frame_motion_search_mode_config) specifying how the motion input vectors will be used.

### `NumHintsPerPixel`

Number of motion vector hint maps. Each map provides an additional motion vector hint for each (x, y) pixel position.

### `ppMotionVectorMaps`

Pointer to an array of [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) textures. Each texture in *ppMotionVectorMaps*[i] represents the i-th motion vector hint for each (x, y) pixel position. The dimension must match the input texture frame. Each element is **DXGI_FORMAT_R16G16_SINT** where R16 is the horizontal component and G16 is the vertical component.

### `pMotionVectorMapsSubresources`

Subresource indices for when *ppMotionVectorMaps* is a texture array. NULL otherwise.

### `ppMotionVectorMapsMetadata`

Pointer to an array of **ID3D12Resource** textures. Each texture in *ppMotionVectorMapsMetadata*[i] represents the metadata for the i-th motion vector hint. Each element is **DXGI_FORMAT_R8_UINT** where R8 holds the reference frame index in the DPB. A value of 255 indicates the motion vector must be ignored by the driver.

### `pMotionVectorMapsMetadataSubresources`

Subresource indices for when *ppMotionVectorMapsMetadata* is a texture array. NULL otherwise.

### `MotionUnitPrecision`

A [D3D12_VIDEO_ENCODER_FRAME_INPUT_MOTION_UNIT_PRECISION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_input_motion_unit_precision) defining the numerical unit used in the motion vector values.

### `PictureControlConfiguration`

A [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_codec_data) providing information to the driver about picture control associated with the frame that will be encoded with this motion info, such as reference lists and reordering depending on the codec.

## Remarks

## See also