## Description

Specifies a resource binding described by a range of bytes in a Direct3D 12 buffer, represented by an offset and size into an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource).

## Members

### `Buffer`

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)***

An optional pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) interface representing a buffer. The resource must have dimension [D3D12_RESOURCE_DIMENSION_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension), and the
range described by this struct must lie within the bounds of the buffer. You may supply **nullptr** for this member to indicate 'no binding'.

### `Offset`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The offset, in bytes, from the start of the buffer where the range begins. This offset must be aligned to a
multiple of [DML_MINIMUM_BUFFER_TENSOR_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-directml-constants) or the **GuaranteedBaseOffsetAlignment** supplied as part of the
[DML_BUFFER_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_buffer_tensor_desc).

### `SizeInBytes`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the range, in bytes.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)