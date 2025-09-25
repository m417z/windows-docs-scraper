# D3D12DDI_VIDEO_PROCESSOR_INPUT_STREAM_DESC_0043 structure

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

Describes the minimum and maximum destination rectangle size. Video processor should allocate to handle all cases within the range.

### `EnableOrientation`

Enable all transforms specified in D3D12DDI_VIDEO_PROCESS_ORIENTATION.

### `FilterFlags`

A bitwise OR of one or more flags from the D3D12DDI_VIDEO_PROCESS_FILTER_FLAGS_0020 enumeration specifies the filters to enable.

### `StereoFormat`

Uses D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_0020 to specify whether the stream is stereo or not. If the value is D3D12DDI_VIDEO_FRAME_STEREO_FORMAT_SEPARATE, there are two sets of input textures and references (for the stereo interlaced case).

### `DeinterlaceMode`

A D3D12DDI_VIDEO_PROCESS_DEINTERLACE_FLAGS_0020 that represents the deinterlace mode to use.

### `EnableAlphaBlending`

The planar alpha for an input stream on the video processor. See D3D12DDI_VIDEO_PROCESS_ALPHA_BLENDING.

### `LumaKey`

A D3D12DDI_VIDEO_PROCESS_LUMA_KEY_0020 that represents a luma key for an input stream on the video processor.

### `NumPastFrames`

The number of past frames.

### `NumFutureFrames`

The number of future frames.

### `EnableAutoProcessing`

Enables or disables automatic processing features on the video processor.