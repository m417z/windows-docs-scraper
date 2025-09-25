# D3D12DDI_QUERY_HEAP_TYPE enumeration

## Description

A **D3D12DDI_QUERY_HEAP_TYPE** enum value identifies the type of a query heap, which is an array of query results.

## Constants

### `D3D12DDI_QUERY_HEAP_TYPE_OCCLUSION:0`

Returns a binary 0/1 result: 0 indicates that no samples passed depth and stencil testing, 1 indicates that at least one sample passed depth and stencil testing. This enables occlusion queries to not interfere with any GPU performance optimization associated with depth/stencil testing.

### `D3D12DDI_QUERY_HEAP_TYPE_TIMESTAMP:1`

The heap is for high-performance timing data.

### `D3D12DDI_QUERY_HEAP_TYPE_PIPELINE_STATISTICS:2`

The heap is to contain pre-D3D12 graphics pipeline data. See [**D3D11_DDI_QUERY_DATA_PIPELINE_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_ddi_query_data_pipeline_statistics).

### `D3D12DDI_QUERY_HEAP_TYPE_SO_STATISTICS:3`

The heap is to contain stream output data. See [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics)

### `D3D12DDI_QUERY_HEAP_TYPE_0020_VIDEO_DECODE_STATISTICS:4`

The heap is to contain video decode data. See [**D3D12DDI_QUERY_DATA_VIDEO_DECODE_STATISTICS_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_query_data_video_decode_statistics_0022).

### `D3D12DDI_QUERY_HEAP_TYPE_0032_COPY_QUEUE_TIMESTAMP:5`

The heap is to contain timestamp queries emitted exclusively by copy command lists. Copy queue timestamps can only be queried from a copy command list, and a copy command list can't emit to a regular timestamp query Heap.

### `D3D12DDI_QUERY_HEAP_TYPE_PIPELINE_STATISTICS1:7`

The heap is to contain pipeline data. See [**D3D12DDI_QUERY_DATA_PIPELINE_STATISTICS1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_query_data_pipeline_statistics1).

## Remarks

Queries are used to capture information from the GPU, such as statistics and status codes which can later be consumed directly on the GPU or on CPU. Status structures associated with the query heap type define the resolved data that is returned.

## See also

[**pfnd3d12ddiCreateQueryHeap0001**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_query_heap_0001)