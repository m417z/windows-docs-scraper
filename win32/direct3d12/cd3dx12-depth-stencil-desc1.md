# CD3DX12\_DEPTH\_STENCIL\_DESC1 structure

A helper structure to enable easy initialization of a [**D3D12\_DEPTH\_STENCIL\_DESC1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc1) structure.

## Members

**CD3DX12\_DEPTH\_STENCIL\_DESC1()**

Creates a new, uninitialized, instance of a CD3DX12\_DEPTH\_STENCIL\_DESC1.

**explicit CD3DX12\_DEPTH\_STENCIL\_DESC1(const D3D12\_DEPTH\_STENCIL\_DESC1& o)**

Creates a new instance of a CD3DX12\_DEPTH\_STENCIL\_DESC1, initialized with values copied from a [**D3D12\_DEPTH\_STENCIL\_DESC1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc1) structure.

**explicit CD3DX12\_DEPTH\_STENCIL\_DESC1(const D3D12\_DEPTH\_STENCIL\_DESC& o)**

Creates a new instance of a CD3DX12\_DEPTH\_STENCIL\_DESC1, initialized with values copied from a [**D3D12\_DEPTH\_STENCIL\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc) structure

and the additional **DepthBoundsTestEnable** member set to **FALSE**.

**explicit CD3DX12\_DEPTH\_STENCIL\_DESC1(CD3DX12\_DEFAULT)**

Creates a new instance of a CD3DX12\_DEPTH\_STENCIL\_DESC1, initialized with the default state prescribed by D3DX12:

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
    DepthBoundsTestEnable = FALSE;

```

**explicit CD3DX12\_DEPTH\_STENCIL\_DESC1(BOOL depthEnable, D3D12\_DEPTH\_WRITE\_MASK depthWriteMask, D3D12\_COMPARISON\_FUNC depthFunc, BOOL stencilEnable, UINT8 stencilReadMask, UINT8 stencilWriteMask, D3D12\_STENCIL\_OP frontStencilFailOp, D3D12\_STENCIL\_OP frontStencilDepthFailOp, D3D12\_STENCIL\_OP frontStencilPassOp, D3D12\_COMPARISON\_FUNC frontStencilFunc, D3D12\_STENCIL\_OP backStencilFailOp, D3D12\_STENCIL\_OP backStencilDepthFailOp, D3D12\_STENCIL\_OP backStencilPassOp, D3D12\_COMPARISON\_FUNC backStencilFunc, BOOL depthBoundsTestEnable)**

Creates a new instance of a CD3DX12\_DEPTH\_STENCIL\_DESC1, initialized with the values passed in the parameter list.

**~CD3DX12\_DEPTH\_STENCIL\_DESC1()**

Destroys an instance of a D3DX12\_DEPTH\_STENCIL\_DESC1.

**operator const D3D12\_DEPTH\_STENCIL\_DESC1&() const**

Implicit conversion to a D3D12\_DEPTH\_STENCIL\_DESC1 structure. Because D3D12\_DEPTH\_STENCIL\_DESC1 is the underlying type of CD3DX12\_DEPTH\_STENCIL\_DESC1, the object is simply returned as a const D3D12\_DEPTH\_STENCIL\_DESC1 reference to itself.

**operator const D3D12\_DEPTH\_STENCIL\_DESC() const**

Implicit conversion to a D3D12\_DEPTH\_STENCIL\_DESC structure value. Because D3D12\_DEPTH\_STENCIL\_DESC is not the underlying type of CD3DX12\_DEPTH\_STENCIL\_DESC1, a new D3D12\_DEPTH\_STENCIL\_DESC instance is created and returned by value. Note that D3D12\_DEPTH\_STENCIL\_DESC does not include the **DepthBoundsTestEnable** member, so this value is lost in the conversion.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**D3D12\_DEPTH\_STENCIL\_DESC1**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc1)

[**D3D12\_DEPTH\_STENCIL\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc)

