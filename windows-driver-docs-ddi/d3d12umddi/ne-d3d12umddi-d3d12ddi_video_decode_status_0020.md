# D3D12DDI_VIDEO_DECODE_STATUS_0020 enumeration

## Description

Contains status values for video decode.

## Constants

### `D3D12DDI_VIDEO_DECODE_STATUS_0020_OK`

Operation succeeded.

### `D3D12DDI_VIDEO_DECODE_STATUS_0020_CONTINUE`

There was a minor problem in the data format, but the host decoder should continue processing.

### `D3D12DDI_VIDEO_DECODE_STATUS_0020_CONTINUE_SKIP_DISPLAY`

There was a significant problem in the data format. The host decoder should continue processing, but should skip display.

### `D3D12DDI_VIDEO_DECODE_STATUS_0020_RESTART`

There was a severe problem in the data format. The host decoder should restart the entire decoding process, starting at a sequence or random-access entry point.

### `D3D12DDI_VIDEO_DECODE_STATUS_0020_RATE_EXCEEDED`

The bit rate or frame rate supplied to decode stream creation was insufficient for this frame. When this status is reported, the **BitRate** member of the [D3D12DDI_QUERY_DATA_VIDEO_DECODE_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_query_data_video_decode_statistics_0022) structure reports a value that can be used to recreate the decode stream at the same frame rate and succeed decoding the failed frames. Subsequent frames may still fail if those frames exceed the new value. The reported bit rate is calculated with the frame rate with which the stream was created.

## See also

[D3D12DDI_QUERY_DATA_VIDEO_DECODE_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_query_data_video_decode_statistics_0022)