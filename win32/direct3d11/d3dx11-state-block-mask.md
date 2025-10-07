# D3DX11\_STATE\_BLOCK\_MASK structure

Indicates the device state.

## Members

**VS**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the vertex shader state.

**VSSamplers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of vertex-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.

**VSShaderResources**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of vertex-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.

**VSConstantBuffers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of vertex-shader constant buffers. The array is a multi-byte bitmask where each bit represents one constant buffer slot.

**VSInterfaces**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of vertex-shader interfaces. The array is a multi-byte bitmask where each bit represents one interface slot.

**HS**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the hull shader state.

**HSSamplers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of hull-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.

**HSShaderResources**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of hull-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.

**HSConstantBuffers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of hull-shader constant buffers. The array is a multi-byte bitmask where each bit represents one constant buffer slot.

**HSInterfaces**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of hull-shader interfaces. The array is a multi-byte bitmask where each bit represents one interface slot.

**DS**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the domain shader state.

**DSSamplers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of domain-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.

**DSShaderResources**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of domain-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.

**DSConstantBuffers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of domain-shader constant buffers. The array is a multi-byte bitmask where each bit represents one buffer slot.

**DSInterfaces**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of domain-shader interfaces. The array is a multi-byte bitmask where each bit represents one interface slot.

**GS**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the geometry shader state.

**GSSamplers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of geometry-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.

**GSShaderResources**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of geometry-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.

**GSConstantBuffers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of geometry-shader constant buffers. The array is a multi-byte bitmask where each bit represents one buffer slot.

**GSInterfaces**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of geometry-shader interfaces. The array is a multi-byte bitmask where each bit represents one interface slot.

**PS**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the pixel shader state.

**PSSamplers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of pixel-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.

**PSShaderResources**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of pixel-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.

**PSConstantBuffers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of pixel-shader constant buffers. The array is a multi-byte bitmask where each bit represents one constant buffer slot.

**PSInterfaces**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of pixel-shader interfaces. The array is a multi-byte bitmask where each bit represents one interface slot.

**PSUnorderedAccessViews**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the pixel shader unordered access views.

**CS**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the compute shader state.

**CSSamplers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of compute-shader samplers. The array is a multi-byte bitmask where each bit represents one sampler slot.

**CSShaderResources**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of compute-shader resources. The array is a multi-byte bitmask where each bit represents one resource slot.

**CSConstantBuffers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of compute-shader constant buffers. The array is a multi-byte bitmask where each bit represents one constant buffer slot.

**CSInterfaces**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of compute-shader interfaces. The array is a multi-byte bitmask where each bit represents one interface slot.

**CSUnorderedAccessViews**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the compute shader unordered access views.

**IAVertexBuffers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of vertex buffers. The array is a multi-byte bitmask where each bit represents one resource slot.

**IAIndexBuffer**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the index buffer state.

**IAInputLayout**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the input layout state.

**IAPrimitiveTopology**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the primitive topology state.

**OMRenderTargets**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the render targets states.

**OMDepthStencilState**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the depth-stencil state.

**OMBlendState**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the blend state.

**RSViewports**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the viewports states.

**RSScissorRects**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the scissor rectangles states.

**RSRasterizerState**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the rasterizer state.

**SOBuffers**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the stream-out buffers states.

**Predication**

Type: **[**BYTE**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Boolean value indicating whether to save the predication state.

## Remarks

A state-block mask indicates the device states that a pass or a technique changes.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------------|
| Header<br> | D3dx11effect.h |

## See also

[Effects 11 Structures](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-effects11-structures)

