# ID3D12VideoDecodeCommandList::SetPredication

## Description

Specifies that subsequent commands should not be performed if the predicate value passes the specified operation.

## Parameters

### `pBuffer`

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) representing the buffer from which to read the 64-bit predication value.

### `AlignedBufferOffset`

The UINT64-aligned buffer offset.

### `Operation`

A member of the [D3D12_PREDICATION_OP](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_predication_op) enumeration specifying the predicate operation.

## Remarks

## See also