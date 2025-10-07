# CD3DX12\_DEPTH\_STENCIL\_DESC structure

A helper structure to enable easy initialization of a [**D3D12\_DEPTH\_STENCIL\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc) structure.

## Members

**CD3DX12\_DEPTH\_STENCIL\_DESC()**

Creates a new, uninitialized, instance of a D3DX12\_DEPTH\_STENCIL\_DESC.

**explicit CD3DX12\_DEPTH\_STENCIL\_DESC(const D3D12\_DEPTH\_STENCIL\_DESC& o)**

Creates a new instance of a D3DX12\_DEPTH\_STENCIL\_DESC, initialized with the contents of another [**D3D12\_DEPTH\_STENCIL\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc) structure.

**explicit CD3DX12\_DEPTH\_STENCIL\_DESC(CD3DX12\_DEFAULT)**

Creates a new instance of a D3DX12\_DEPTH\_STENCIL\_DESC, initialized with default parameters.

``` syntax
        DepthEnable = TRUE;
        DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
        DepthFunc = D3D12_COMPARISON_FUNC_LESS;
        StencilEnable = FALSE;
        StencilReadMask = D3D12_DEFAULT_STENCIL_READ_MASK;
        StencilWriteMask = D3D12_DEFAULT_STENCIL_WRITE_MASK;
        const D3D12_DEPTH_STENCILOP_DESC defaultStencilOp =
        { D3D12_STENCIL_OP_KEEP, D3D12_STENCIL_OP_KEEP, D3D12_STENCIL_OP_KEEP, D3D12_COMPARISON_FUNC_ALWAYS };
        FrontFace = defaultStencilOp;
        BackFace = defaultStencilOp;
```

**explicit CD3DX12\_DEPTH\_STENCIL\_DESC(BOOL depthEnable, D3D12\_DEPTH\_WRITE\_MASK depthWriteMask, D3D12\_COMPARISON\_FUNC depthFunc, BOOL stencilEnable, UINT8 stencilReadMask, UINT8 stencilWriteMask, D3D12\_STENCIL\_OP frontStencilFailOp, D3D12\_STENCIL\_OP frontStencilDepthFailOp, D3D12\_STENCIL\_OP frontStencilPassOp, D3D12\_COMPARISON\_FUNC frontStencilFunc, D3D12\_STENCIL\_OP backStencilFailOp, D3D12\_STENCIL\_OP backStencilDepthFailOp, D3D12\_STENCIL\_OP backStencilPassOp, D3D12\_COMPARISON\_FUNC backStencilFunc)**

Creates a new instance of a D3DX12\_DEPTH\_STENCIL\_DESC, initializing the following parameters:

BOOL depthEnable

[**D3D12\_DEPTH\_WRITE\_MASK**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_depth_write_mask) depthWriteMask

[**D3D12\_COMPARISON\_FUNC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_comparison_func) depthFunc

BOOL stencilEnable

UINT8 stencilReadMask

UINT8 stencilWriteMask

[**D3D12\_STENCIL\_OP**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_stencil_op) frontStencilFailOp

[**D3D12\_STENCIL\_OP**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_stencil_op) frontStencilDepthFailOp

[**D3D12\_STENCIL\_OP**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_stencil_op) frontStencilPassOp

[**D3D12\_COMPARISON\_FUNC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_comparison_func) frontStencilFunc

[**D3D12\_STENCIL\_OP**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_stencil_op) backStencilFailOp

[**D3D12\_STENCIL\_OP**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_stencil_op) backStencilDepthFailOp

[**D3D12\_STENCIL\_OP**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_stencil_op) backStencilPassOp

[**D3D12\_COMPARISON\_FUNC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_comparison_func) backStencilFunc

**~CD3DX12\_DEPTH\_STENCIL\_DESC()**

Destroys an instance of a CD3DX12\_DEPTH\_STENCIL\_DESC.

**operator const D3D12\_DEPTH\_STENCIL\_DESC&() const**

Defines the & pass-by-reference operator for the parent structure type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[**D3D12\_DEPTH\_STENCIL\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc)

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

