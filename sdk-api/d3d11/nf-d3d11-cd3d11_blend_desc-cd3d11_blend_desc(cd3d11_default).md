# CD3D11_BLEND_DESC::CD3D11_BLEND_DESC(CD3D11_DEFAULT)

## Description

Instantiates a new instance of a [CD3D11_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-cd3d11_blend_desc) structure that is initialized with default blend-state values.

## Parameters

### `unnamedParam1`

TBD

## Remarks

Here are the default depth-stencil-state values for the members of [D3D11_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_blend_desc):

```
AlphaToCoverageEnable = FALSE;
        IndependentBlendEnable = FALSE;
        const D3D11_RENDER_TARGET_BLEND_DESC defaultRenderTargetBlendDesc =
        {
            FALSE,
            D3D11_BLEND_ONE, D3D11_BLEND_ZERO, D3D11_BLEND_OP_ADD,
            D3D11_BLEND_ONE, D3D11_BLEND_ZERO, D3D11_BLEND_OP_ADD,
            D3D11_COLOR_WRITE_ENABLE_ALL,
        };
        for (UINT i = 0; i < D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT; ++i)
            RenderTarget[ i ] = defaultRenderTargetBlendDesc;

```

## See also

[CD3D11_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-cd3d11_blend_desc)