# D3D12DDI_QUERY_DATA_VIDEO_DECODE_STATISTICS_0022 structure

## Description

Video decode statistics for a query.

## Members

### `Status`

Specifies the status of an operation as a [D3D12DDI_VIDEO_DECODE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_status_0020) value. This value is extended to 64bits to accommodate predication.

### `NumMacroblocksAffected`

The number of blocks affected. If the **Status** value is not 0, this member contains an estimate from the accelerator of the number of super-blocks in the decoded frame that were adversely affected by the reported problem. If the accelerator does not provide an estimate, the value is `0xFFFFFFFFFFFFFFFF`.

### `FrameRate`

The frame rate.

### `BitRate`

When the **Status** value returned is **D3D12DDI_VIDEO_DECODE_STATUS_RATE_EXCEEDED**, this member reports the required bit rate. This value may be used to recreate the decode stream and try again. The updated value is relative to the frame rate with which the stream was created. A value of zero (0) is valid to indicate that the worst case bit rate should be assumed.
For all other **Status** values, **BitRate** is not used and is set to zero.

## See also

[D3D12DDI_VIDEO_DECODE_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_decode_status_0020)