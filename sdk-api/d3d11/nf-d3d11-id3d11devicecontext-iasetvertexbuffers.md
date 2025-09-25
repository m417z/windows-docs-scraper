# ID3D11DeviceContext::IASetVertexBuffers

## Description

Bind an array of vertex buffers to the [input-assembler stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage).

## Parameters

### `StartSlot` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The first input slot for binding. The first vertex buffer is explicitly bound to the start slot; this causes each additional vertex buffer in the array to be implicitly bound to each subsequent input slot. The maximum of 16 or 32 input slots (ranges from 0 to D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1) are available; the [maximum number of input slots depends on the feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro).

### `NumBuffers` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of vertex buffers in the array. The number of buffers (plus the starting slot) can't exceed the total number of IA-stage input slots (ranges from 0 to D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot).

### `ppVertexBuffers` [in, optional]

Type: **[ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)***

A pointer to an array of vertex buffers (see [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer)). The vertex buffers must have been created with the [D3D11_BIND_VERTEX_BUFFER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) flag.

### `pStrides` [in, optional]

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to an array of stride values; one stride value for each buffer in the vertex-buffer array. Each stride is the size (in bytes) of the elements that are to be used from that vertex buffer.

### `pOffsets` [in, optional]

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to an array of offset values; one offset value for each buffer in the vertex-buffer array. Each offset is the number of bytes between the first element of a vertex buffer and the first element that will be used.

## Remarks

For info about creating vertex buffers, see [How to: Create a Vertex Buffer](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-buffers-vertex-how-to).

Calling this method using a buffer that is currently bound for writing (that is, bound to the stream output pipeline stage) will effectively bind **NULL** instead because a buffer can't be bound as both an input and an output at the same time.

The debug layer will generate a warning whenever a resource is prevented from being bound simultaneously as an input and an output, but this will not prevent invalid data from being used by the runtime.

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)