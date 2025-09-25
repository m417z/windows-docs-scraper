# D3D10_RASTERIZER_DESC structure

## Description

Describes the rasterizer state.

## Members

### `FillMode`

Type: **[D3D10_FILL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_fill_mode)**

A member of the [D3D10_FILL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_fill_mode) enumerated type that determines the fill mode to use when rendering. The default value is **D3D10_FILL_SOLID**.

### `CullMode`

Type: **[D3D10_CULL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_cull_mode)**

A member of the [D3D10_CULL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_cull_mode) enumerated type that indicates whether triangles facing the specified direction are drawn. The default value is **D3D10_CULL_BACK**.

### `FrontCounterClockwise`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Determines if a triangle is front-facing or back-facing. If this parameter is **TRUE**, then a triangle is considered front-facing if its vertices are counter-clockwise on the render target, and considered back-facing if they are clockwise. If this parameter is **FALSE**, then the opposite is true. The default value is **FALSE**.

### `DepthBias`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the depth value added to a given pixel. The default value is 0. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `DepthBiasClamp`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the maximum depth bias of a pixel. The default value is 0.0f. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `SlopeScaledDepthBias`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies a scalar on a given pixel's slope. The default value is 0.0f. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `DepthClipEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Enables or disables clipping based on distance. The default value is **TRUE**.

The hardware always performs x and y clipping of rasterized coordinates. When **DepthClipEnable** is set to the default value, the hardware also clips the z value (that is, the hardware performs the last step of the following algorithm).

``` syntax

0 < w
-w <= x <= w (or arbitrarily wider range if implementation uses a guard band to reduce clipping burden)
-w <= y <= w (or arbitrarily wider range if implementation uses a guard band to reduce clipping burden)
0 <= z <= w

```

When you set **DepthClipEnable** to FALSE, the hardware skips the z clipping (that is, the last step in the preceding algorithm). However, the hardware still performs the "0 < w" clipping. When z clipping is disabled, improper depth ordering at the pixel level might result. However, when z clipping is disabled, stencil shadow implementations are simplified. In other words, you can avoid complex special-case handling for geometry that goes beyond the back clipping plane.

### `ScissorEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Enable or disables scissor-rectangle culling. All pixels outside an active scissor rectangle are culled. The default value is **FALSE**. For more information, see [Set the Scissor Rectangle](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage-getting-started).

### `MultisampleEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether to use the quadrilateral or alpha line anti-aliasing algorithm on multisample antialiasing (MSAA) render targets. The default value is **FALSE**. Set to **TRUE** to use the quadrilateral line anti-aliasing algorithm and to **FALSE** to use the alpha line anti-aliasing algorithm. For more info about this member, see Remarks.

### `AntialiasedLineEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether to enable line antialiasing; only applies when alpha blending is enabled, you are drawing lines, and the **MultisampleEnable** member is **FALSE**. The default value is **FALSE**. For more info about this member, see Remarks.

## Remarks

Rasterizer state defines the behavior of the [rasterizer stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage). To create a rasterizer-state object, call [ID3D10Device::CreateRasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createrasterizerstate). To set rasterizer state, call [ID3D10Device::RSSetState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-rssetstate).

**Note** For [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, 9.3, and 10.0, if you set **MultisampleEnable** to **FALSE**, the runtime renders all points, lines, and triangles without anti-aliasing even for render targets with a sample count greater than 1. For feature level 10.1, the setting of **MultisampleEnable** has no effect on points and triangles with regard to MSAA and impacts only the selection of the line-rendering algorithm as shown in this table:

| Line-rendering algorithm | **MultisampleEnable** | **AntialiasedLineEnable** |
| --- | --- | --- |
| Aliased | **FALSE** | **FALSE** |
| Alpha antialiased | **FALSE** | **TRUE** |
| Quadrilateral | **TRUE** | **FALSE** |
| Quadrilateral | **TRUE** | **TRUE** |

The settings of the **MultisampleEnable** and **AntialiasedLineEnable** members apply only to multisample antialiasing (MSAA) render targets (that is, render targets with sample counts greater than 1). Because of the differences in [feature-level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) behavior and as long as you aren’t performing any line drawing or don’t mind that lines render as quadrilaterals, we recommend that you always set **MultisampleEnable** to **TRUE** whenever you render on MSAA render targets.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)