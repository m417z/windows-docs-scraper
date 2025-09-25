# D3D12_STREAM_OUTPUT_BUFFER_VIEW structure

## Description

Describes a stream output buffer.

## Members

### `BufferLocation`

A D3D12_GPU_VIRTUAL_ADDRESS (a UINT64) that points to the stream output buffer.
If **SizeInBytes** is 0, this member isn't used and can be any value.

### `SizeInBytes`

The size of the stream output buffer in bytes.

### `BufferFilledSizeLocation`

The location of the value of how much data has been filled into the buffer, as a D3D12_GPU_VIRTUAL_ADDRESS (a UINT64).
This member can't be NULL; a filled size location must be supplied (which the hardware will increment as data is output).
If **SizeInBytes** is 0, this member isn't used and can be any value.

## Remarks

Use this structure with [SOSetTargets](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-sosettargets).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)