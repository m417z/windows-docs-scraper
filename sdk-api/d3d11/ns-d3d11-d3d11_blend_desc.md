# D3D11_BLEND_DESC structure

## Description

Describes the blend state that you use in a call to [ID3D11Device::CreateBlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createblendstate) to create a blend-state object.

## Members

### `AlphaToCoverageEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether to use alpha-to-coverage as a multisampling technique when setting a pixel to a render target. For more info about using alpha-to-coverage, see [Alpha-To-Coverage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state).

### `IndependentBlendEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether to enable independent blending in simultaneous render targets. Set to **TRUE** to enable independent blending. If set to **FALSE**, only the RenderTarget[0] members are used; RenderTarget[1..7] are ignored.

### `RenderTarget`

Type: **[D3D11_RENDER_TARGET_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_render_target_blend_desc)[8]**

An array of [D3D11_RENDER_TARGET_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_render_target_blend_desc) structures that describe the blend states for render targets; these correspond to the eight render targets
that can be bound to the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) at one time.

## Remarks

Here are the default values for blend state.

| State | Default Value |
| --- | --- |
| AlphaToCoverageEnable | **FALSE** |
| IndependentBlendEnable | **FALSE** |
| RenderTarget[0].BlendEnable | **FALSE** |
| RenderTarget[0].SrcBlend | D3D11_BLEND_ONE |
| RenderTarget[0].DestBlend | D3D11_BLEND_ZERO |
| RenderTarget[0].BlendOp | D3D11_BLEND_OP_ADD |
| RenderTarget[0].SrcBlendAlpha | D3D11_BLEND_ONE |
| RenderTarget[0].DestBlendAlpha | D3D11_BLEND_ZERO |
| RenderTarget[0].BlendOpAlpha | D3D11_BLEND_OP_ADD |
| RenderTarget[0].RenderTargetWriteMask | D3D11_COLOR_WRITE_ENABLE_ALL |

**Note** **D3D11_BLEND_DESC** is identical to [D3D10_BLEND_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ns-d3d10_1-d3d10_blend_desc1).

If the driver type is set to [D3D_DRIVER_TYPE_HARDWARE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type), the feature level is set to less than or equal to [D3D_FEATURE_LEVEL_9_3](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level), and the pixel format of the render target is set to [DXGI_FORMAT_R8G8B8A8_UNORM_SRGB](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), **DXGI_FORMAT_B8G8R8A8_UNORM_SRGB**, or **DXGI_FORMAT_B8G8R8X8_UNORM_SRGB**, the display device performs the blend in standard RGB (sRGB) space and not in linear space. However, if the feature level is set to greater than **D3D_FEATURE_LEVEL_9_3**, the display device performs the blend in linear space, which is ideal.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)