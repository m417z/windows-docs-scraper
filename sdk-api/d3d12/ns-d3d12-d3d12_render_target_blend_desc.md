## Description

Describes the blend state for a render target.

## Members

### `BlendEnable`

Specifies whether to enable (or disable) blending. Set to **TRUE** to enable blending.

> [!NOTE]
> It's not valid for *LogicOpEnable* and *BlendEnable* to both be **TRUE**.

### `LogicOpEnable`

Specifies whether to enable (or disable) a logical operation. Set to **TRUE** to enable a logical operation.

> [!NOTE]
> It's not valid for *LogicOpEnable* and *BlendEnable* to both be **TRUE**.

### `SrcBlend`

A [D3D12_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_blend)-typed value that specifies the operation to perform on the RGB value that the pixel shader outputs. The **BlendOp** member defines how to combine the **SrcBlend** and **DestBlend** operations.

### `DestBlend`

A [D3D12_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_blend)-typed value that specifies the operation to perform on the current RGB value in the render target. The **BlendOp** member defines how to combine the **SrcBlend** and **DestBlend** operations.

### `BlendOp`

A [D3D12_BLEND_OP](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_blend_op)-typed value that defines how to combine the **SrcBlend** and **DestBlend** operations.

### `SrcBlendAlpha`

A [D3D12_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_blend)-typed value that specifies the operation to perform on the alpha value that the pixel shader outputs. Blend options that end in _COLOR are not allowed. The **BlendOpAlpha** member defines how to combine the **SrcBlendAlpha** and **DestBlendAlpha** operations.

### `DestBlendAlpha`

A [D3D12_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_blend)-typed value that specifies the operation to perform on the current alpha value in the render target. Blend options that end in _COLOR are not allowed. The **BlendOpAlpha** member defines how to combine the **SrcBlendAlpha** and **DestBlendAlpha** operations.

### `BlendOpAlpha`

A [D3D12_BLEND_OP](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_blend_op)-typed value that defines how to combine the **SrcBlendAlpha** and **DestBlendAlpha** operations.

### `LogicOp`

A [D3D12_LOGIC_OP](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_logic_op)-typed value that specifies the logical operation to configure for the render target.

### `RenderTargetWriteMask`

A combination of [D3D12_COLOR_WRITE_ENABLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_color_write_enable)-typed values that are combined by using a bitwise OR operation. The resulting value specifies a write mask.

## Remarks

> [!NOTE]
> It's not valid for *LogicOpEnable* and *BlendEnable* to both be **TRUE**.

You specify an array of **D3D12_RENDER_TARGET_BLEND_DESC** structures in the **RenderTarget** member of the [D3D12_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_blend_desc) structure to describe the blend states for render targets; you can bind up to eight render targets to the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) at one time.

For info about how blending is done, see the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

Here are the default values for blend state.

| State | Default Value |
| --- | --- |
| BlendEnable | FALSE |
| LogicOpEnable | FALSE |
| SrcBlend | D3D12_BLEND_ONE |
| DestBlend | D3D12_BLEND_ZERO |
| BlendOp | D3D12_BLEND_OP_ADD |
| SrcBlendAlpha | D3D12_BLEND_ONE |
| DestBlendAlpha | D3D12_BLEND_ZERO |
| BlendOpAlpha | D3D12_BLEND_OP_ADD |
| LogicOp | D3D12_LOGIC_OP_NOOP |
| RenderTargetWriteMask | D3D12_COLOR_WRITE_ENABLE_ALL |

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)