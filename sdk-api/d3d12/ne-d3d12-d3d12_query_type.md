# D3D12_QUERY_TYPE enumeration

## Description

Specifies the type of query.

## Constants

### `D3D12_QUERY_TYPE_OCCLUSION:0`

Indicates the query is for depth/stencil occlusion counts.

### `D3D12_QUERY_TYPE_BINARY_OCCLUSION:1`

Indicates the query is for a binary depth/stencil occlusion statistics.

This new query type acts like D3D12_QUERY_TYPE_OCCLUSION except that it returns simply a binary 0/1 result: 0 indicates that no samples passed depth and stencil testing, 1 indicates that at least one sample passed depth and stencil testing. This enables occlusion queries to not interfere with any GPU performance optimization associated with depth/stencil testing.

### `D3D12_QUERY_TYPE_TIMESTAMP:2`

Indicates the query is for high definition GPU and CPU timestamps.

### `D3D12_QUERY_TYPE_PIPELINE_STATISTICS:3`

Indicates the query type is for graphics pipeline statistics, refer to [D3D12_QUERY_DATA_PIPELINE_STATISTICS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_query_data_pipeline_statistics).

### `D3D12_QUERY_TYPE_SO_STATISTICS_STREAM0:4`

Stream 0 output statistics. In Direct3D 12 there is no single stream output (SO) overflow query for all the output streams. Apps need to issue multiple single-stream queries, and then correlate the results. Stream output is the ability of the GPU to write vertices to a buffer. The stream output counters monitor progress.

### `D3D12_QUERY_TYPE_SO_STATISTICS_STREAM1:5`

Stream 1 output statistics.

### `D3D12_QUERY_TYPE_SO_STATISTICS_STREAM2:6`

Stream 2 output statistics.

### `D3D12_QUERY_TYPE_SO_STATISTICS_STREAM3:7`

Stream 3 output statistics.

### `D3D12_QUERY_TYPE_VIDEO_DECODE_STATISTICS:8`

Video decode statistics. Refer to [D3D12_QUERY_DATA_VIDEO_DECODE_STATISTICS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_query_data_video_decode_statistics).

Use this query type to determine if a video was successfully decoded. If decoding fails due to insufficient BitRate or FrameRate parameters set during creation of the decode heap, then the status field of the query is set to [D3D12_VIDEO_DECODE_STATUS_RATE_EXCEEDED](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_status) and the query also contains new BitRate and FrameRate values that would succeed.

This query type can only be performed on video decode command lists [(D3D12_COMMAND_LIST_TYPE_VIDEO_DECODE)](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_command_list_type). This query type does not use [ID3D12VideoDecodeCommandList::BeginQuery](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist-beginquery), only [ID3D12VideoDecodeCommandList::EndQuery](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist-endquery). Statistics are recorded only for the most recent [ID3D12VideoDecodeCommandList::DecodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist-decodeframe) call in the same command list.

Decode status structures are defined by the codec specification.

## Remarks

This enum is used by [BeginQuery](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-beginquery), [EndQuery](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-endquery) and [ResolveQueryData.](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-resolvequerydata)

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)