# D3D12DDI_QUERY_TYPE enumeration

## Description

A **D3D12DDI_QUERY_TYPE** enum value identifies the type of a query.

## Constants

### `D3D12DDI_QUERY_TYPE_OCCLUSION:0`

The query is for depth/stencil occlusion counts.

### `D3D12DDI_QUERY_TYPE_BINARY_OCCLUSION:1`

The query is for a binary depth/stencil occlusion statistics.

This query type acts like D3D12DDI_QUERY_TYPE_OCCLUSION except that it returns simply a binary 0/1 result: 0 indicates that no samples passed depth and stencil testing, 1 indicates that at least one sample passed depth and stencil testing. This enables occlusion queries to not interfere with any GPU performance optimization associated with depth/stencil testing.

### `D3D12DDI_QUERY_TYPE_TIMESTAMP:2`

The query is for high definition GPU and CPU timestamps.

### `D3D12DDI_QUERY_TYPE_PIPELINE_STATISTICS:3`

The query type is for pre-D3D12 graphics pipeline statistics. See [**D3D11_DDI_QUERY_DATA_PIPELINE_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_ddi_query_data_pipeline_statistics).

### `D3D12DDI_QUERY_TYPE_SO_STATISTICS_STREAM0:4`

The query type is for stream output (SO) statistics for Stream0. Stream output is the ability of the GPU to write vertices to a buffer. The stream output counters monitor progress. See [**D3D10_DDI_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_query_data_so_statistics)

### `D3D12DDI_QUERY_TYPE_SO_STATISTICS_STREAM1:5`

The query type is for SO statistics for Stream1.

### `D3D12DDI_QUERY_TYPE_SO_STATISTICS_STREAM2:6`

The query type is for SO statistics for Stream2.

### `D3D12DDI_QUERY_TYPE_SO_STATISTICS_STREAM3:7`

The query type is for SO statistics for Stream3.

### `D3D12DDI_QUERY_TYPE_0020_VIDEO_DECODE_STATISTICS:8`

The query type is for video decode statistics. See [**D3D12DDI_QUERY_DATA_VIDEO_DECODE_STATISTICS_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_query_data_video_decode_statistics_0022).

### `D3D12DDI_QUERY_TYPE_PIPELINE_STATISTICS1:10`

The query type is for graphics pipeline statistics. See [**D3D12DDI_QUERY_DATA_PIPELINE_STATISTICS1 **](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_query_data_pipeline_statistics1).

## Remarks

Queries are used to capture information from the GPU, such as statistics and status codes which can later be consumed directly on the GPU or on CPU.

## See also

[**pfnBeginEndQuery**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_begin_end_query)

[**pfnResolveQueryData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_resolve_query_data)