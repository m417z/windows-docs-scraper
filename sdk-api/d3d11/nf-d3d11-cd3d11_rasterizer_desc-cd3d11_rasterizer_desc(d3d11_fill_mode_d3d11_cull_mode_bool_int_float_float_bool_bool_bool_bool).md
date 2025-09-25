# CD3D11_RASTERIZER_DESC::CD3D11_RASTERIZER_DESC(D3D11_FILL_MODE,D3D11_CULL_MODE,BOOL,INT,FLOAT,FLOAT,BOOL,BOOL,BOOL,BOOL)

## Description

Instantiates a new instance of a [CD3D11_RASTERIZER_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151654(v=vs.85)) structure that is initialized with [D3D11_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc) values.

## Parameters

### `fillMode`

Type: **[D3D11_FILL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_fill_mode)**

A [D3D11_FILL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_fill_mode)-typed value that determines the fill mode to use when rendering.

### `cullMode`

Type: **[D3D11_CULL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cull_mode)**

A [D3D11_CULL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cull_mode)-typed value that indicates triangles facing the specified direction are not drawn.

### `frontCounterClockwise`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean value that specifies whether a triangle is front- or back-facing. If this parameter is **TRUE**, a triangle will be considered front-facing if its vertices are counter-clockwise on the render target and considered back-facing if they are clockwise. If this parameter is **FALSE**, the opposite is true.

### `depthBias`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Depth value added to a given pixel. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `depthBiasClamp`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum depth bias of a pixel. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `slopeScaledDepthBias`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Scalar on a given pixel's slope. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `depthClipEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean value that specifies whether to enable clipping based on distance.

The hardware always performs x and y clipping of rasterized coordinates. When *depthClipEnable* is set to the default–**TRUE**, the hardware also clips the z value (that is, the hardware performs the last step of the following algorithm).

``` syntax

0 < w
-w <= x <= w (or arbitrarily wider range if implementation uses a guard band to reduce clipping burden)
-w <= y <= w (or arbitrarily wider range if implementation uses a guard band to reduce clipping burden)
0 <= z <= w

```

When you set *depthClipEnable* to **FALSE**, the hardware skips the z clipping (that is, the last step in the preceding algorithm). However, the hardware still performs the "0 < w" clipping. When z clipping is disabled, improper depth ordering at the pixel level might result. However, when z clipping is disabled, stencil shadow implementations are simplified. In other words, you can avoid complex special-case handling for geometry that goes beyond the back clipping plane.

### `scissorEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean value that specifies whether to enable scissor-rectangle culling. All pixels outside an active scissor rectangle are culled.

### `multisampleEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean value that specifies whether to use the quadrilateral or alpha line anti-aliasing algorithm on multisample antialiasing (MSAA) render targets. Set to **TRUE** to use the quadrilateral line anti-aliasing algorithm and to **FALSE** to use the alpha line anti-aliasing algorithm.

### `antialiasedLineEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A Boolean value that specifies whether to enable line antialiasing; only applies if doing line drawing and *multisampleEnable* is **FALSE**.

## Remarks

Here is how CD3D11_RASTERIZER_DESC assigns the provided values to the members of [D3D11_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc):

```
FillMode = fillMode;
        CullMode = cullMode;
        FrontCounterClockwise = frontCounterClockwise;
        DepthBias = depthBias;
        DepthBiasClamp = depthBiasClamp;
        SlopeScaledDepthBias = slopeScaledDepthBias;
        DepthClipEnable = depthClipEnable;
        ScissorEnable = scissorEnable;
        MultisampleEnable = multisampleEnable;
        AntialiasedLineEnable = antialiasedLineEnable;

```

## See also

[CD3D11_RASTERIZER_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151654(v=vs.85))