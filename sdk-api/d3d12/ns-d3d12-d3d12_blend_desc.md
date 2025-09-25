## Description

Describes the blend state.

## Members

### `AlphaToCoverageEnable`

Specifies whether to use alpha-to-coverage as a multisampling technique when setting a pixel to a render target. For more info about using alpha-to-coverage, see [Alpha-To-Coverage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state).

### `IndependentBlendEnable`

Specifies whether to enable independent blending in simultaneous render targets. Set to **TRUE** to enable independent blending. If set to **FALSE**, only the **RenderTarget**[0] members are used; **RenderTarget**[1..7] are ignored.

See the **Remarks** section for restrictions.

### `RenderTarget`

An array of [D3D12_RENDER_TARGET_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_blend_desc) structures that describe the blend states for render targets; these correspond to the eight render targets that can be bound to the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) at one time.

## Remarks

A [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) object contains a blend-state structure that controls blending by the output-merger stage.

Here are the default values for blend state.

| State | Default Value |
| --- | --- |
| AlphaToCoverageEnable | **FALSE** |
| IndependentBlendEnable | **FALSE** |
| RenderTarget[0].BlendEnable | **FALSE** |
| RenderTarget[0].LogicOpEnable | **FALSE** |
| RenderTarget[0].SrcBlend | D3D12_BLEND_ONE |
| RenderTarget[0].DestBlend | D3D12_BLEND_ZERO |
| RenderTarget[0].BlendOp | D3D12_BLEND_OP_ADD |
| RenderTarget[0].SrcBlendAlpha | D3D12_BLEND_ONE |
| RenderTarget[0].DestBlendAlpha | D3D12_BLEND_ZERO |
| RenderTarget[0].BlendOpAlpha | D3D12_BLEND_OP_ADD |
| RenderTarget[0].LogicOp | D3D12_LOGIC_OP_NOOP |
| RenderTarget[0].RenderTargetWriteMask | D3D12_COLOR_WRITE_ENABLE_ALL |

When you set the **LogicOpEnable** member of the first element of the **RenderTarget** array (**RenderTarget**[0]) to **TRUE**, you must also set the **BlendEnable** member of **RenderTarget**[0] to **FALSE**, and the **IndependentBlendEnable** member of this structure to **FALSE**. This reflects the limitation in hardware that you can't mix logic operations with blending across multiple render targets, and that when you use a logic operation, you must apply the same logic operation to all render targets.

Note the helper structure, [CD3DX12_BLEND_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-blend-desc).

## See also

[Core structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)