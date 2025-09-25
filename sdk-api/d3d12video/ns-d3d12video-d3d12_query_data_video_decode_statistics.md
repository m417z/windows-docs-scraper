# D3D12_QUERY_DATA_VIDEO_DECODE_STATISTICS structure

## Description

Represents data for a video decode statistics query invoked by calling [ID3D12VideoDecodeCommandList::EndQuery](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist-endquery).

## Members

### `Status`

A member of the [D3D12_VIDEO_DECODE_STATUS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_status) enumeration indicating the video decoding status.

### `NumMacroblocksAffected`

If **Status** is not 0, this member contains the accelerator's estimate of the number of super-blocks in the decoded frame that were adversely affected by the reported problem. If the accelerator does not provide an estimate, the value is **D3D12\_VIDEO\_DECODE\_MACROBLOCKS\_AFFECTED\_UNKNOWN** (0xFFFFFFFFFFFFFFFF).

### `FrameRate`

The decode frame rate.

### `BitRate`

When the **Status** returned is [D3D12_VIDEO_DECODE_STATUS_RATE_EXCEEDED](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_status), this field reports the bitrate that would succeed. This value may be used to recreate the decoder and try again. A value of zero here is valid to indicate that the worst case bit rate should be assumed.

For all other **Status** values, **BitRate** is set to zero.

## Remarks

## See also