# D3D11_VIDEO_PROCESSOR_CONTENT_DESC structure

## Description

Describes a video stream for a video processor.

## Members

### `InputFrameFormat`

A member of the [D3D11_VIDEO_FRAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_frame_format) enumeration that describes how the video stream is interlaced.

### `InputFrameRate`

The frame rate of the input video stream, specified as a [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure.

### `InputWidth`

The width of the input frames, in pixels.

### `InputHeight`

The height of the input frames, in pixels.

### `OutputFrameRate`

The frame rate of the output video stream, specified as a [DXGI_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure.

### `OutputWidth`

The width of the output frames, in pixels.

### `OutputHeight`

The height of the output frames, in pixels.

### `Usage`

A member of the [D3D11_VIDEO_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_usage) enumeration that describes how the video processor will be used. The value indicates the desired trade-off between speed and video quality. The driver uses this flag as a hint when it creates the video processor.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)

[ID3D11VideoDevice::CreateVideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessorenumerator)