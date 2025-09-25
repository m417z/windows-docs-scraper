# ID3D10Device::IAGetVertexBuffers

## Description

Get the [vertex buffers](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) bound to the [input-assembler](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage) stage.

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The [input slot](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started) of the first vertex buffer to get. The first vertex buffer is explicitly bound to the start slot; this causes each additional vertex buffer in the array to be implicitly bound to each subsequent input slot. A maximum of 16 or 32 input slots (ranges from 0 to either D3D10_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1 or D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1) are available; the [maximum number of input slots depends on the feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro).

### `NumBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of vertex buffers to get starting at the offset. The number of buffers (plus the starting slot) cannot exceed the total number of IA-stage input slots.

### `ppVertexBuffers` [out]

Type: **[ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)****

A pointer to an array of vertex buffers returned by the method (see [ID3D10Buffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)).

### `pStrides` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to an array of stride values returned by the method; one stride value for each buffer in the vertex-buffer array. Each stride value is the size (in bytes) of the elements that are to be used from that vertex buffer.

### `pOffsets` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to an array of offset values returned by the method; one offset value for each buffer in the vertex-buffer array. Each offset is the number of bytes between the first element of a vertex buffer and the first element that will be used.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)