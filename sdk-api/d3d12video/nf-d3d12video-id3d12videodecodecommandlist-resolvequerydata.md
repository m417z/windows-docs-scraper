# ID3D12VideoDecodeCommandList::ResolveQueryData

## Description

Extracts data from a query.

## Parameters

### `pQueryHeap`

A pointer to an [ID3D12QueryHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12queryheap) specifying the storage containing the queries to resolve.

### `Type`

A member of the [D3D12_QUERY_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_query_type) enumeration specifying the type of the query.

### `StartIndex`

The index of the first query to resolve.

### `NumQueries`

The number of queries to resolve.

### `pDestinationBuffer`

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) representing the destination buffer. The resource must be in the state [D3D12_RESOURCE_STATE_COPY_DEST](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

### `AlignedDestinationBufferOffset`

The alignment offset into the destination buffer. This must be a multiple of 8 bytes.

## Remarks

## See also