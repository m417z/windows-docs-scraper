# CD3D11_DEPTH_STENCIL_DESC::CD3D11_DEPTH_STENCIL_DESC(CD3D11_DEFAULT)

## Description

Instantiates a new instance of a [CD3D11_DEPTH_STENCIL_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151632(v=vs.85)) structure that is initialized with default depth-stencil-state values.

## Parameters

### `unnamedParam1`

Default depth-stencil-state values.

## Remarks

Here are the default depth-stencil-state values for the members of [D3D11_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_desc):

```
DepthEnable = TRUE;
        DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
        DepthFunc = D3D11_COMPARISON_LESS;
        StencilEnable = FALSE;
        StencilReadMask = D3D11_DEFAULT_STENCIL_READ_MASK;
        StencilWriteMask = D3D11_DEFAULT_STENCIL_WRITE_MASK;
        const D3D11_DEPTH_STENCILOP_DESC defaultStencilOp =
        { D3D11_STENCIL_OP_KEEP, D3D11_STENCIL_OP_KEEP, D3D11_STENCIL_OP_KEEP, D3D11_COMPARISON_ALWAYS };
        FrontFace = defaultStencilOp;
        BackFace = defaultStencilOp;

```

## See also

[CD3D11_DEPTH_STENCIL_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151632(v=vs.85))