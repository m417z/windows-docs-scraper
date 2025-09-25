# D3D11_RASTERIZER_DESC1 structure

## Description

**Note** This structure is supported by the Direct3D 11.1 runtime, which is available on Windows 8 and later operating systems.

Describes rasterizer state.

## Members

### `FillMode`

Type: **[D3D11_FILL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_fill_mode)**

Determines the fill mode to use when rendering.

### `CullMode`

Type: **[D3D11_CULL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cull_mode)**

Indicates that triangles facing the specified direction are not drawn.

### `FrontCounterClockwise`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether a triangle is front- or back-facing. If **TRUE**, a triangle will be considered front-facing if its vertices are counter-clockwise on the render target and considered back-facing if they are clockwise. If **FALSE**, the opposite is true.

### `DepthBias`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Depth value added to a given pixel. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `DepthBiasClamp`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum depth bias of a pixel. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `SlopeScaledDepthBias`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Scalar on a given pixel's slope. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `DepthClipEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether to enable clipping based on distance.

The hardware always performs x and y clipping of rasterized coordinates. When **DepthClipEnable** is set to the default–**TRUE**, the hardware also clips the z value (that is, the hardware performs the last step of the following algorithm).

``` syntax

0 < w
-w <= x <= w (or arbitrarily wider range if implementation uses a guard band to reduce clipping burden)
-w <= y <= w (or arbitrarily wider range if implementation uses a guard band to reduce clipping burden)
0 <= z <= w

```

When you set **DepthClipEnable** to **FALSE**, the hardware skips the z clipping (that is, the last step in the preceding algorithm). However, the hardware still performs the "0 < w" clipping. When z clipping is disabled, improper depth ordering at the pixel level might result. However, when z clipping is disabled, stencil shadow implementations are simplified. In other words, you can avoid complex special-case handling for geometry that goes beyond the back clipping plane.

### `ScissorEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether to enable scissor-rectangle culling. All pixels outside an active scissor rectangle are culled.

### `MultisampleEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether to use the quadrilateral or alpha line anti-aliasing algorithm on multisample antialiasing (MSAA) render targets. Set to **TRUE** to use the quadrilateral line anti-aliasing algorithm and to **FALSE** to use the alpha line anti-aliasing algorithm. For more info about this member, see Remarks.

### `AntialiasedLineEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether to enable line antialiasing; only applies if doing line drawing and **MultisampleEnable** is **FALSE**. For more info about this member, see Remarks.

### `ForcedSampleCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The sample count that is forced while UAV rendering or rasterizing. Valid values are 0, 1, 2, 4, 8, and optionally 16. 0 indicates that the sample count is not forced.

**Note** If you want to render with **ForcedSampleCount** set to 1 or greater, you must follow these guidelines:

* Don't bind depth-stencil views.
* Disable depth testing.
* Ensure the shader doesn't output depth.
* If you have any render-target views bound ([D3D11_BIND_RENDER_TARGET](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag)) and **ForcedSampleCount** is greater than 1, ensure that every render target has only a single sample.
* Don't operate the shader at sample frequency. Therefore, [ID3D11ShaderReflection::IsSampleFrequencyShader](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflection-issamplefrequencyshader) returns **FALSE**.

Otherwise, rendering behavior is undefined. For info about how to configure depth-stencil, see [Configuring Depth-Stencil Functionality](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-depth-stencil).

## Remarks

Rasterizer state defines the behavior of the rasterizer stage. To create a rasterizer-state object, call [ID3D11Device1::CreateRasterizerState1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-createrasterizerstate1). To set rasterizer state, call [ID3D11DeviceContext::RSSetState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-rssetstate).

If you do not specify some rasterizer state, the Direct3D runtime uses the following default values for rasterizer state.

| State | Default Value |
| --- | --- |
| **FillMode** | Solid |
| **CullMode** | Back |
| **FrontCounterClockwise** | **FALSE** |
| **DepthBias** | 0 |
| **SlopeScaledDepthBias** | 0.0f |
| **DepthBiasClamp** | 0.0f |
| **DepthClipEnable** | **TRUE** |
| **ScissorEnable** | **FALSE** |
| **MultisampleEnable** | **FALSE** |
| **AntialiasedLineEnable** | **FALSE** |
| **ForcedSampleCount** | 0 |

**Note** For [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, 9.3, and 10.0, if you set **MultisampleEnable** to **FALSE**, the runtime renders all points, lines, and triangles without anti-aliasing even for render targets with a sample count greater than 1. For feature levels 10.1 and higher, the setting of **MultisampleEnable** has no effect on points and triangles with regard to MSAA and impacts only the selection of the line-rendering algorithm as shown in this table:

| Line-rendering algorithm | **MultisampleEnable** | **AntialiasedLineEnable** |
| --- | --- | --- |
| Aliased | **FALSE** | **FALSE** |
| Alpha antialiased | **FALSE** | **TRUE** |
| Quadrilateral | **TRUE** | **FALSE** |
| Quadrilateral | **TRUE** | **TRUE** |

The settings of the **MultisampleEnable** and **AntialiasedLineEnable** members apply only to multisample antialiasing (MSAA) render targets (that is, render targets with sample counts greater than 1). Because of the differences in [feature-level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) behavior and as long as you aren’t performing any line drawing or don’t mind that lines render as quadrilaterals, we recommend that you always set **MultisampleEnable** to **TRUE** whenever you render on MSAA render targets.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)