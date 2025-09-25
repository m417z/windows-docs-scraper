# D3D11_QUERY enumeration

## Description

Query types.

## Constants

### `D3D11_QUERY_EVENT:0`

Determines whether or not the GPU is finished processing commands. When the GPU is finished processing commands [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) will return S_OK, and pData will point to a BOOL with a value of **TRUE**. When using this type of query, [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) is disabled.

### `D3D11_QUERY_OCCLUSION`

Get the number of samples that passed the depth and stencil tests in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) returns a UINT64. If a depth or stencil test is disabled, then each of those tests will be counted as a pass.

### `D3D11_QUERY_TIMESTAMP`

Get a timestamp value where [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) returns a UINT64. This kind of query is only useful if two timestamp queries are done in the middle of a D3D11_QUERY_TIMESTAMP_DISJOINT query. The difference of two timestamps can be used to determine how many ticks have elapsed, and the D3D11_QUERY_TIMESTAMP_DISJOINT query will determine if that difference is a reliable value and also has a value that shows how to convert the number of ticks into seconds. See [D3D11_QUERY_DATA_TIMESTAMP_DISJOINT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_data_timestamp_disjoint). When using this type of query, [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) is disabled.

### `D3D11_QUERY_TIMESTAMP_DISJOINT`

Determines whether or not a D3D11_QUERY_TIMESTAMP is returning reliable values, and also gives the frequency of the processor enabling you to convert the number of elapsed ticks into seconds. [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) will return a [D3D11_QUERY_DATA_TIMESTAMP_DISJOINT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_data_timestamp_disjoint). This type of query should only be invoked once per frame or less.

### `D3D11_QUERY_PIPELINE_STATISTICS`

Get pipeline statistics, such as the number of pixel shader invocations in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) will return a [D3D11_QUERY_DATA_PIPELINE_STATISTICS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_data_pipeline_statistics).

### `D3D11_QUERY_OCCLUSION_PREDICATE`

Similar to D3D11_QUERY_OCCLUSION, except [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) returns a BOOL indicating whether or not any samples passed the depth and stencil tests - **TRUE** meaning at least one passed, **FALSE** meaning none passed.

### `D3D11_QUERY_SO_STATISTICS`

Get streaming output statistics, such as the number of primitives streamed out in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) will return a [D3D11_QUERY_DATA_SO_STATISTICS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_data_so_statistics) structure.

### `D3D11_QUERY_SO_OVERFLOW_PREDICATE`

Determines whether or not any of the streaming output buffers overflowed in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) returns a BOOL - **TRUE** meaning there was an overflow, **FALSE** meaning there was not an overflow. If streaming output writes to multiple buffers, and one of the buffers overflows, then it will stop writing to all the output buffers. When an overflow is detected by Direct3D it is prevented from happening - no memory is corrupted. This predication may be used in conjunction with an SO_STATISTICS query so that when an overflow occurs the SO_STATISTIC query will let the application know how much memory was needed to prevent an overflow.

### `D3D11_QUERY_SO_STATISTICS_STREAM0`

Get streaming output statistics for stream 0, such as the number of primitives streamed out in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) will return a [D3D11_QUERY_DATA_SO_STATISTICS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_data_so_statistics) structure.

### `D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM0`

Determines whether or not the stream 0 output buffers overflowed in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) returns a BOOL - **TRUE** meaning there was an overflow, **FALSE** meaning there was not an overflow. If streaming output writes to multiple buffers, and one of the buffers overflows, then it will stop writing to all the output buffers. When an overflow is detected by Direct3D it is prevented from happening - no memory is corrupted. This predication may be used in conjunction with an SO_STATISTICS query so that when an overflow occurs the SO_STATISTIC query will let the application know how much memory was needed to prevent an overflow.

### `D3D11_QUERY_SO_STATISTICS_STREAM1`

Get streaming output statistics for stream 1, such as the number of primitives streamed out in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) will return a [D3D11_QUERY_DATA_SO_STATISTICS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_data_so_statistics) structure.

### `D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM1`

Determines whether or not the stream 1 output buffers overflowed in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) returns a BOOL - **TRUE** meaning there was an overflow, **FALSE** meaning there was not an overflow. If streaming output writes to multiple buffers, and one of the buffers overflows, then it will stop writing to all the output buffers. When an overflow is detected by Direct3D it is prevented from happening - no memory is corrupted. This predication may be used in conjunction with an SO_STATISTICS query so that when an overflow occurs the SO_STATISTIC query will let the application know how much memory was needed to prevent an overflow.

### `D3D11_QUERY_SO_STATISTICS_STREAM2`

Get streaming output statistics for stream 2, such as the number of primitives streamed out in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) will return a [D3D11_QUERY_DATA_SO_STATISTICS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_data_so_statistics) structure.

### `D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM2`

Determines whether or not the stream 2 output buffers overflowed in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) returns a BOOL - **TRUE** meaning there was an overflow, **FALSE** meaning there was not an overflow. If streaming output writes to multiple buffers, and one of the buffers overflows, then it will stop writing to all the output buffers. When an overflow is detected by Direct3D it is prevented from happening - no memory is corrupted. This predication may be used in conjunction with an SO_STATISTICS query so that when an overflow occurs the SO_STATISTIC query will let the application know how much memory was needed to prevent an overflow.

### `D3D11_QUERY_SO_STATISTICS_STREAM3`

Get streaming output statistics for stream 3, such as the number of primitives streamed out in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) will return a [D3D11_QUERY_DATA_SO_STATISTICS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_query_data_so_statistics) structure.

### `D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM3`

Determines whether or not the stream 3 output buffers overflowed in between [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). [ID3D11DeviceContext::GetData](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-getdata) returns a BOOL - **TRUE** meaning there was an overflow, **FALSE** meaning there was not an overflow. If streaming output writes to multiple buffers, and one of the buffers overflows, then it will stop writing to all the output buffers. When an overflow is detected by Direct3D it is prevented from happening - no memory is corrupted. This predication may be used in conjunction with an SO_STATISTICS query so that when an overflow occurs the SO_STATISTIC query will let the application know how much memory was needed to prevent an overflow.

## Remarks

Create a query with [ID3D11Device::CreateQuery](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createquery).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)