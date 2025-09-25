# D3D12_QUERY_HEAP_TYPE enumeration

## Description

Specifies the type of query heap to create.

## Constants

### `D3D12_QUERY_HEAP_TYPE_OCCLUSION:0`

This returns a binary 0/1 result: 0 indicates that no samples passed depth and stencil testing, 1 indicates that at least one sample passed depth and stencil testing. This enables occlusion queries to not interfere with any GPU performance optimization associated with depth/stencil testing.

### `D3D12_QUERY_HEAP_TYPE_TIMESTAMP:1`

Indicates that the heap is for high-performance timing data.

### `D3D12_QUERY_HEAP_TYPE_PIPELINE_STATISTICS:2`

Indicates the heap is to contain pipeline data. Refer to [D3D12_QUERY_DATA_PIPELINE_STATISTICS](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_query_data_pipeline_statistics).

### `D3D12_QUERY_HEAP_TYPE_SO_STATISTICS:3`

Indicates the heap is to contain stream output data. Refer to [D3D12_QUERY_DATA_SO_STATISTICS](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_query_data_so_statistics).

### `D3D12_QUERY_HEAP_TYPE_VIDEO_DECODE_STATISTICS:4`

Indicates the heap is to contain video decode statistics data. Refer to [D3D12_QUERY_DATA_VIDEO_DECODE_STATISTICS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_query_data_video_decode_statistics).

Video decode statistics can only be queried from video decode command lists ([D3D12_COMMAND_LIST_TYPE_VIDEO_DECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_command_list_type)). See [D3D12_QUERY_TYPE_DECODE_STATISTICS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_query_type) for more details.

### `D3D12_QUERY_HEAP_TYPE_COPY_QUEUE_TIMESTAMP:5`

Indicates the heap is to contain timestamp queries emitted exclusively by copy command lists. Copy queue timestamps can only be queried from a copy command list, and a copy command list can not emit to a regular timestamp query Heap.

Support for this query heap type is not universal. You must use [CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport) with [D3D12_FEATURE_D3D12_OPTIONS3](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_feature) to determine whether the adapter supports copy queue timestamp queries.

## Remarks

This enum is used by the [D3D12_QUERY_HEAP_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_query_heap_desc) structure.

## See also

[Core enumerations](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-enumerations)