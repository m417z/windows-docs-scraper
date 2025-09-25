# D3D12_STREAM_OUTPUT_DESC structure

## Description

Describes a streaming output buffer.

## Members

### `pSODeclaration`

An array of [D3D12_SO_DECLARATION_ENTRY](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_so_declaration_entry) structures. Can't be **NULL** if **NumEntries** > 0.

### `NumEntries`

The number of entries in the stream output declaration array that the **pSODeclaration** member points to.

### `pBufferStrides`

An array of buffer strides; each stride is the size of an element for that buffer.

### `NumStrides`

The number of strides (or buffers) that the **pBufferStrides** member points to.

### `RasterizedStream`

The index number of the stream to be sent to the rasterizer stage.

## Remarks

A [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) object contains a **D3D12_STREAM_OUTPUT_DESC** structure.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)