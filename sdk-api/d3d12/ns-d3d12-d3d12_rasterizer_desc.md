# D3D12_RASTERIZER_DESC structure

## Description

Describes rasterizer state.

## Members

### `FillMode`

A [D3D12_FILL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_fill_mode)-typed value that specifies the fill mode to use when rendering.

### `CullMode`

A [D3D12_CULL_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_cull_mode)-typed value that specifies that triangles facing the specified direction are not drawn.

### `FrontCounterClockwise`

Determines if a triangle is front- or back-facing. If this member is **TRUE**, a triangle will be considered front-facing if its vertices are counter-clockwise on the render target and considered back-facing if they are clockwise. If this parameter is **FALSE**, the opposite is true.

### `DepthBias`

Depth value added to a given pixel. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `DepthBiasClamp`

Maximum depth bias of a pixel. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `SlopeScaledDepthBias`

Scalar on a given pixel's slope. For info about depth bias, see [Depth Bias](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage-depth-bias).

### `DepthClipEnable`

Specifies whether to enable clipping based on distance.

The hardware always performs x and y clipping of rasterized coordinates. When **DepthClipEnable** is set to the default–**TRUE**, the hardware also clips the z value (that is, the hardware performs the last step of the following algorithm).

``` syntax

0 < w
-w <= x <= w (or arbitrarily wider range if implementation uses a guard band to reduce clipping burden)
-w <= y <= w (or arbitrarily wider range if implementation uses a guard band to reduce clipping burden)
0 <= z <= w

```

When you set **DepthClipEnable** to **FALSE**, the hardware skips the z clipping (that is, the last step in the preceding algorithm). However, the hardware still performs the "0 < w" clipping. When z clipping is disabled, improper depth ordering at the pixel level might result. However, when z clipping is disabled, stencil shadow implementations are simplified. In other words, you can avoid complex special-case handling for geometry that goes beyond the back clipping plane.

### `MultisampleEnable`

Specifies whether to use the quadrilateral or alpha line anti-aliasing algorithm on multisample antialiasing (MSAA) render targets. Set to **TRUE** to use the quadrilateral line anti-aliasing algorithm and to **FALSE** to use the alpha line anti-aliasing algorithm. For more info about this member, see Remarks.

### `AntialiasedLineEnable`

Specifies whether to enable line antialiasing; only applies if doing line drawing and **MultisampleEnable** is **FALSE**. For more info about this member, see Remarks.

### `ForcedSampleCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The sample count that is forced while UAV rendering or rasterizing. Valid values are 0, 1, 4, 8, and optionally 16. 0 indicates that the sample count is not forced.

**Note** If you want to render with **ForcedSampleCount** set to 1 or greater, you must follow these guidelines:

* Don't bind depth-stencil views.
* Disable depth testing.
* Ensure the shader doesn't output depth.
* If you have any render-target views bound ([D3D12_DESCRIPTOR_HEAP_TYPE_RTV](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_descriptor_heap_type)) and **ForcedSampleCount** is greater than 1, ensure that every render target has only a single sample.
* Don't operate the shader at sample frequency. Therefore, [ID3D12ShaderReflection::IsSampleFrequencyShader](https://learn.microsoft.com/windows/win32/api/d3d12shader/nf-d3d12shader-id3d12shaderreflection-issamplefrequencyshader) returns **FALSE**.

Otherwise, rendering behavior is undefined.

### `ConservativeRaster`

A [D3D12_CONSERVATIVE_RASTERIZATION_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_conservative_rasterization_mode)-typed value that identifies whether conservative rasterization is on or off.

## Remarks

A [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) contains a rasterizer-state structure.

Rasterizer state defines the behavior of the rasterizer stage.

If you do not specify some rasterizer state, the Direct3D runtime uses the following default values for rasterizer state.

| State | Default Value |
| --- | --- |
| **FillMode** | D3D12_FILL_MODE_SOLID |
| **CullMode** | D3D12_CULL_MODE_BACK |
| **FrontCounterClockwise** | **FALSE** |
| **DepthBias** | 0 |
| **DepthBiasClamp** | 0.0f |
| **SlopeScaledDepthBias** | 0.0f |
| **DepthClipEnable** | **TRUE** |
| **MultisampleEnable** | **FALSE** |
| **AntialiasedLineEnable** | **FALSE** |
| **ForcedSampleCount** | 0 |
| **ConservativeRaster** | **D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF** |

**Note** For [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1, 9.2, 9.3, and 10.0, if you set **MultisampleEnable** to **FALSE**, the runtime renders all points, lines, and triangles without anti-aliasing even for render targets with a sample count greater than 1. For feature levels 10.1 and higher, the setting of **MultisampleEnable** has no effect on points and triangles with regard to MSAA and impacts only the selection of the line-rendering algorithm as shown in this table:

| Line-rendering algorithm | **MultisampleEnable** | **AntialiasedLineEnable** |
| --- | --- | --- |
| Aliased | **FALSE** | **FALSE** |
| Alpha antialiased | **FALSE** | **TRUE** |
| Quadrilateral | **TRUE** | **FALSE** |
| Quadrilateral | **TRUE** | **TRUE** |

The settings of the **MultisampleEnable** and **AntialiasedLineEnable** members apply only to multisample antialiasing (MSAA) render targets (that is, render targets with sample counts greater than 1). Because of the differences in [feature-level](https://learn.microsoft.com/windows/win32/direct3d12/hardware-feature-levels) behavior and as long as you aren’t performing any line drawing or don’t mind that lines render as quadrilaterals, we recommend that you always set **MultisampleEnable** to **TRUE** whenever you render on MSAA render targets.

## See also

[CD3DX12_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-rasterizer-desc)

[Conservative Rasterization](https://learn.microsoft.com/windows/desktop/direct3d12/conservative-rasterization)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Rasterizer Ordered Views](https://learn.microsoft.com/windows/desktop/direct3d12/rasterizer-order-views)