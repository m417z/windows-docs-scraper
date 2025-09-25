# D3D12_VIDEO_PROCESS_INPUT_STREAM_DESC structure

## Description

Specifies the parameters for the input stream for a video process operation.

## Members

### `Format`

A value from the [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration specifying the format of the input stream. In the case of stereo, this format is the format of both inputs.

### `ColorSpace`

A value from the [DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type) enumeration specifying the color space of the video processor input and reference surfaces.

### `SourceAspectRatio`

A [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure specifying the source aspect ratio.

### `DestinationAspectRatio`

A [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure specifying the destination aspect ratio.

### `FrameRate`

A [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure specifying the frame rate of the input video stream.

### `SourceSizeRange`

A [D3D12_VIDEO_SIZE_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_size_range) structure representing the size of the source rectangle. This argument specifies the input range size this video processor must support for [ProcessFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist-processframes). If a source size exceeds the range, the video processor must be recreated.

### `DestinationSizeRange`

A [D3D12_VIDEO_SIZE_RANGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_size_range) structure representing the size of the destination rectangle. This argument specifies the destination range size this video processor must support for [ProcessFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist-processframes). If a source size exceeds the range, the video processor must be recreated.

### `EnableOrientation`

A boolean value specifying whether the video processor should support all [D3D12_VIDEO_PROCESS_ORIENTATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_orientation) for [ProcessFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist-processframes).

### `FilterFlags`

A bitwise OR combination of one or more flags from the [D3D12_VIDEO_PROCESS_FILTER_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_filter_flags) enumeration specifying the filters to enable.

### `StereoFormat`

A value from the [D3D12_VIDEO_FRAME_STEREO_FORMAT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_frame_stereo_format) enumeration specifies whether the stream is stereo or not. A value of **D3D12_VIDEO_PROCESS_STEREO_FORMAT_SEPARATE** indicates that there will be two sets of input textures, and two sets of references for the stereo interlaced case.

### `FieldType`

A value from the [D3D12_VIDEO_FIELD_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_field_type) enumeration specfying the interlaced field type of the input source. When working with mixed content, use [ID3D12VideoProcessCommandList1::ProcessFrames1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist1-processframes1) which supports changing the field type for each call.

### `DeinterlaceMode`

A value from the [D3D12_VIDEO_PROCESS_DEINTERLACE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_deinterlace_flags) enumeration specifying the deinterlace mode to use.

### `EnableAlphaBlending`

A boolean value specifying whether alpha blending is enabled. Alpha blending settings are provided to [ProcessFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist-processframes) with *AlphaBlending* the field of the [D3D12_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_arguments) structure.

### `LumaKey`

A [D3D12_VIDEO_PROCESS_LUMA_KEY](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_luma_key) structure specifying the luma key for an input stream on the video processor.

### `NumPastFrames`

An integer specifying the number of past reference frames.

### `NumFutureFrames`

An integer specifying the number of future reference frames.

### `EnableAutoProcessing`

A boolean value specifying wither automatic processing features are enabled for the video processor.

## Remarks

## See also