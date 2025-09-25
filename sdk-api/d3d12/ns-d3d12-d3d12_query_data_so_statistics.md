## Description

Describes query data about the amount of data streamed out to the stream-output buffers.

## Members

### `NumPrimitivesWritten`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of primitives (that is, points, lines, and triangles) that were actually written to the stream output resource.

### `PrimitivesStorageNeeded`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the stream output resource is large enough, then *PrimitivesStorageNeeded* represents the total number of primitives written to the stream output resource. Otherwise, it represents the total number of primitives that *would* have been written to the stream-output resource had there been enough space for them all.

## Remarks

Use this structure with [D3D12_QUERY_HEAP_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_query_heap_type) and [CreateQueryHeap](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createqueryheap).

## See also

* [Core structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)