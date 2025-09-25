# CD3D11_RASTERIZER_DESC::CD3D11_RASTERIZER_DESC(const D3D11_RASTERIZER_DESC &)

## Description

Instantiates a new instance of a [CD3D11_RASTERIZER_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151654(v=vs.85)) structure that is initialized with a **D3D11_RASTERIZER_DESC** structure.

## Parameters

### `o`

Address of the **D3D11_RASTERIZER_DESC** structure that initializes the **D3D11_RASTERIZER_DESC** structure.

## Remarks

Here are the default rasterizer-state values for the members of [D3D11_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc):

```
FillMode = D3D11_FILL_SOLID;
        CullMode = D3D11_CULL_BACK;
        FrontCounterClockwise = FALSE;
        DepthBias = D3D11_DEFAULT_DEPTH_BIAS;
        DepthBiasClamp = D3D11_DEFAULT_DEPTH_BIAS_CLAMP;
        SlopeScaledDepthBias = D3D11_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
        DepthClipEnable = TRUE;
        ScissorEnable = FALSE;
        MultisampleEnable = FALSE;
        AntialiasedLineEnable = FALSE;

```

## See also

[CD3D11_RASTERIZER_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151654(v=vs.85))