## Description

Describes the blend state that you use in a call to [**D3D11Device1::CreateBlendState1**](https://learn.microsoft.com/windows/win32/api/d3d11_1/nf-d3d11_1-id3d11device1-createblendstate1) to create a blend-state object.

> [!NOTE]
> This structure is supported by the Direct3D 11.1 runtime, which is available on Windows 8 and later operating systems.

## Members

### `AlphaToCoverageEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether to use alpha-to-coverage as a multisampling technique when setting a pixel to a render target. For more info about using alpha-to-coverage, see [Alpha-To-Coverage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state).

### `IndependentBlendEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether to enable independent blending in simultaneous render targets. Set to **TRUE** to enable independent blending. If set to **FALSE**, only the **RenderTarget**[0] members are used; **RenderTarget**[1..7] are ignored.

See the **Remarks** section for restrictions.

### `RenderTarget`

Type: **[D3D11_RENDER_TARGET_BLEND_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_render_target_blend_desc1)[8]**

An array of [D3D11_RENDER_TARGET_BLEND_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_render_target_blend_desc1) structures that describe the blend states for render targets; these correspond to the eight render targets that can be bound to the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) at one time.

## Remarks

Here are the default values for blend state.

| State | Default Value |
| --- | --- |
| AlphaToCoverageEnable | **FALSE** |
| IndependentBlendEnable | **FALSE** |
| RenderTarget[0].BlendEnable | **FALSE** |
| RenderTarget[0].LogicOpEnable | **FALSE** |
| RenderTarget[0].SrcBlend | D3D11_BLEND_ONE |
| RenderTarget[0].DestBlend | D3D11_BLEND_ZERO |
| RenderTarget[0].BlendOp | D3D11_BLEND_OP_ADD |
| RenderTarget[0].SrcBlendAlpha | D3D11_BLEND_ONE |
| RenderTarget[0].DestBlendAlpha | D3D11_BLEND_ZERO |
| RenderTarget[0].BlendOpAlpha | D3D11_BLEND_OP_ADD |
| RenderTarget[0].LogicOp | D3D11_LOGIC_OP_NOOP |
| RenderTarget[0].RenderTargetWriteMask | D3D11_COLOR_WRITE_ENABLE_ALL |

If the driver type is set to [D3D_DRIVER_TYPE_HARDWARE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type), the feature level is set to less than or equal to [D3D_FEATURE_LEVEL_9_3](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level), and the pixel format of the render target is set to [DXGI_FORMAT_R8G8B8A8_UNORM_SRGB](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), **DXGI_FORMAT_B8G8R8A8_UNORM_SRGB**, or **DXGI_FORMAT_B8G8R8X8_UNORM_SRGB**, the display device performs the blend in standard RGB (sRGB) space and not in linear space. However, if the feature level is set to greater than **D3D_FEATURE_LEVEL_9_3**, the display device performs the blend in linear space, which is ideal.

When you set the **LogicOpEnable** member of the first element of the **RenderTarget** array (**RenderTarget**[0]) to **TRUE**, you must also set the **BlendEnable** member of **RenderTarget**[0] to **FALSE**, and the **IndependentBlendEnable** member of this **D3D11_BLEND_DESC1** to **FALSE**. This reflects the limitation in hardware that you can't mix logic operations with blending across multiple render targets, and that when you use a logic operation, you must apply the same logic operation to all render targets.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[D3D11_RENDER_TARGET_BLEND_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_render_target_blend_desc1)

[ID3D11BlendState1::GetDesc1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11blendstate1-getdesc1)