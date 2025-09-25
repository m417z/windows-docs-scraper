# D3D12_QUERY_HEAP_DESC structure

## Description

Describes the purpose of a query heap.
A query heap contains an array of individual queries.

## Members

### `Type`

Specifies one member of [D3D12_QUERY_HEAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_query_heap_type).

### `Count`

Specifies the number of queries the heap should contain.

### `NodeMask`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the query heap applies.
Each bit in the mask corresponds to a single node.
Only 1 bit must be set.
Refer to [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

## Remarks

Use this structure with [CreateQueryHeap](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createqueryheap).

## See also

[Core Structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)