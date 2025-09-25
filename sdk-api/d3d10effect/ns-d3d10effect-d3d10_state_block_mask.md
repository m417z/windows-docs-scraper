## Description

Indicates the device state.

## Members

### `VS`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the vertex shader state.

### `GS`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the geometry shader state.

### `PS`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the pixel shader state.

### `IAIndexBuffer`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the index buffer state.

### `IAInputLayout`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the input layout state.

### `IAPrimitiveTopology`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the primitive topology state.

### `OMRenderTargets`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the render targets states.

### `OMDepthStencilState`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the depth-stencil state.

### `OMBlendState`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the blend state.

### `RSViewports`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the viewports states.

### `RSScissorRects`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the scissor rectangles states.

### `RSRasterizerState`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the rasterizer state.

### `SOBuffers`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the stream-out buffers states.

### `Predication`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the predication state.

### `GSConstantBuffers`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of geometry-shader constant buffers. The array is a multi-byte bitmask where each bit represents one buffer slot.

### `GSSamplers`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of geometry-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.

### `GSShaderResources`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of geometry-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.

### `IAVertexBuffers`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of vertex buffers. The array is a multi-byte bitmask where each bit represents one resource slot.

### `PSConstantBuffers`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of pixel-shader constant buffers. The array is a multi-byte bitmask where each bit represents one constant buffer slot.

### `PSSamplers`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of pixel-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.

### `PSShaderResources`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of pixel-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.

### `VSConstantBuffers`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of vertex-shader constant buffers. The array is a multi-byte bitmask where each bit represents one constant buffer slot.

### `VSSamplers`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of vertex-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.

### `VSShaderResources`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of vertex-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.

## Remarks

A state-block mask indicates the device states that a pass or a technique changes. The [D3D10StateBlockMaskEnableCapture](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-d3d10stateblockmaskenablecapture) function provides a convenient way of setting a range of bitmasks for the array members of **D3D10_STATE_BLOCK_MASK**.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)