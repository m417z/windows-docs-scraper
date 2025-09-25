# D3D12DDI_VIDEO_PROCESSOR_INPUT_STREAM_DESC_0032 structure

## Description

Describes input stream properties for the video processor.

## Members

### `Format`

The DXGI format of the input texture and references.

### `ColorSpace`

A DXGI_COLOR_SPACE_TYPE value that specifies the color space for the video processor input and reference surfaces.

### `SourceAspectRatio`

The source aspect ratio.

### `DestinationAspectRatio`

The destination aspect ratio.

### `FrameRate`

The frame rate of the input video stream, specified as a DXGI_RATIONAL structure.

### `SourceSizeRange`

Describes the minimum and maximum source rectangle size. Video processor should allocate to handle all cases within the range.

### `DestinationSizeRange`

Describes the minimum and maximum destination rectangle size. Video processor should allocate sizes to handle all cases within the range.

### `EnableOrientation`

Enable all transforms specified in [D3D12DDI_VIDEO_PROCESS_ORIENTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_orientation_0020). If rotation implies an intermediate, it should be allocated to handle 90 degree rotation.

### `FilterFlags`

A bitwise OR of one or more flags from the [D3D12DDI_VIDEO_PROCESS_FILTER_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_filter_flags_0020) enumeration, that specifies the filters to enable.

### `StereoFormat`

Specifies whether the stream is stereo or not. If the value is [D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_SEPARATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_frame_stereo_format_0020), there are two sets of input textures and references (for the stereo interlaced case).

### `FieldType`

Specifies the frame format as progressive or interlaced for the input stream. See [D3D12DDI_VIDEO_FIELD_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_field_type_0020).

### `DeinterlaceMode`

The deinterlace mode to use. See [D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_process_deinterlace_flags_0020).

### `EnableAlphaBlending`

The planar alpha for an input stream on the video processor. See [D3D12DDI_VIDEO_PROCESS_ALPHA_BLENDING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_alpha_blending_0020).

### `LumaKey`

The Luma key for an input stream on the video processor. See [D3D12DDI_VIDEO_PROCESS_LUMA_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_luma_key_0020) for more details.

### `NumPastFrames`

The number of past frames.

### `NumFutureFrames`

The number of future frames.

### `EnableAutoProcessing`

Enables or disables automatic processing features on the video processor.