# CD3DX12\_BLEND\_DESC structure

A helper structure to enable easy initialization of a [**D3D12\_BLEND\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_blend_desc) structure.

## Members

**CD3DX12\_BLEND\_DESC()**

Creates a new, uninitialized, instance of a CD3DX12\_BLEND\_DESC.

**explicit CD3DX12\_BLEND\_DESC(const D3D12\_BLEND\_DESC& o)**

Creates a new instance of a CD3DX12\_BLEND\_DESC, initialized with the contents of another [**D3D12\_BLEND\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_blend_desc) structure.

**explicit CD3DX12\_BLEND\_DESC(CD3DX12\_DEFAULT)**

Creates a new instance of a CD3DX12\_BLEND\_DESC, initialized with default parameters.

| State | Default Value |
|-----------------------------------------|----------------------------------|
| AlphaToCoverageEnable | **FALSE** |
| IndependentBlendEnable | **FALSE** |
| RenderTarget\[0\].BlendEnable | **FALSE** |
| RenderTarget\[0\].LogicOpEnable | **FALSE** |
| RenderTarget\[0\].SrcBlend | D3D12\_BLEND\_ONE |
| RenderTarget\[0\].DestBlend | D3D12\_BLEND\_ZERO |
| RenderTarget\[0\].BlendOp | D3D12\_BLEND\_OP\_ADD |
| RenderTarget\[0\].SrcBlendAlpha | D3D12\_BLEND\_ONE |
| RenderTarget\[0\].DestBlendAlpha | D3D12\_BLEND\_ZERO |
| RenderTarget\[0\].BlendOpAlpha | D3D12\_BLEND\_OP\_ADD |
| RenderTarget\[0\].LogicOp | D3D12\_LOGIC\_OP\_NOOP |
| RenderTarget\[0\].RenderTargetWriteMask | D3D12\_COLOR\_WRITE\_ENABLE\_ALL |

**~CD3DX12\_BLEND\_DESC()**

Destroys an instance of a CD3DX12\_BLEND\_DESC.

**operator const D3D12\_BLEND\_DESC&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_BLEND\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_blend_desc)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

