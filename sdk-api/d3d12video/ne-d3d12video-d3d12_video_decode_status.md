# D3D12_VIDEO_DECODE_STATUS enumeration

## Description

Specifies the status of a video decode operation. This enumeration is used in the status field of a [D3D12_VIDEO_DECODE_STATUS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_status) structure.

## Constants

### `D3D12_VIDEO_DECODE_STATUS_OK`

The operation succeeded.

### `D3D12_VIDEO_DECODE_STATUS_CONTINUE`

There was a minor problem in the data format, but the host decoder should continue processing.

### `D3D12_VIDEO_DECODE_STATUS_CONTINUE_SKIP_DISPLAY`

There was a significant problem in the data format. The host decoder should continue processing, but should skip display.

### `D3D12_VIDEO_DECODE_STATUS_RESTART`

There was a severe problem in the data format. The host decoder should restart the entire decoding process, starting at a sequence or random-access entry point.

## Remarks

## See also