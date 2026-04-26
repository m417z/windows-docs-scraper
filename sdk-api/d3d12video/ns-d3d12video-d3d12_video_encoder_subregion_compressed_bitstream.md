## Description

Describes the output buffers and fences used for subregion notification during video encoding.

## Members

### `BufferMode`

A [D3D12_VIDEO_ENCODER_SUBREGION_COMPRESSED_BITSTREAM_BUFFER_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_subregion_compressed_bitstream_buffer_mode) value indicating how the output buffers in **ppSubregionBitstreams** are interpreted and used.

### `ExpectedSubregionCount`

The number of expected subregions. All array members of this struct have this many entries. When the exact number of subregions is not known before execution (for example, max bytes per slice), set this to the maximum number of subregions expected.

### `pSubregionBitstreamsBaseOffsets`

An array of **ExpectedSubregionCount** UINT64 values indicating base offsets where the driver begins writing at each **ppSubregionBitstreams[i]**. Values must be aligned to the **CompressedBitstreamBufferAccessAlignment** value reported in [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resource_requirements).

### `ppSubregionBitstreams`

An array of **ExpectedSubregionCount** [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) buffers for the driver to write subregion bitstream data into.

### `ppSubregionSizes`

An array of **ExpectedSubregionCount** [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) buffers. On each subregion completion, the driver writes the byte size of the i-th packed subregion as a UINT64.

### `ppSubregionOffsets`

An array of **ExpectedSubregionCount** [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) buffers. On each subregion completion, the driver writes the absolute byte offset into **ppSubregionBitstreams[i]** as a UINT64, where the i-th subregion first byte starts.

### `ppSubregionFences`

An array of **ExpectedSubregionCount** [ID3D12Fence](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12fence) objects. The driver signals **ppSubregionFences[i]** when the associated subregion output is complete and accessible.

### `pSubregionFenceValues`

An array of **ExpectedSubregionCount** UINT64 values. **pSubregionFenceValues[i]** is the value the driver uses to signal **ppSubregionFences[i]**.

## Remarks

When **ppSubregionFences[i]** is signaled, all pending writes and cache flushes to the associated **ppSubregionBitstreams[i]**, **ppSubregionSizes[i]**, and **ppSubregionOffsets[i]** are guaranteed to be complete.

The driver may write subregions out of order. The application must wait on fences without assuming a specific notification order.

## See also

[D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_compressed_bitstream1)