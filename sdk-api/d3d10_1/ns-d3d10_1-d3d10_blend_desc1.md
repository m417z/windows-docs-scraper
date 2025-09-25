# D3D10_BLEND_DESC1 structure

## Description

Describes the blend state for a Direct3D 10.1 device.

## Members

### `AlphaToCoverageEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Determines whether or not to use the [alpha-to-coverage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-blend-state) multisampling technique when setting a render-target pixel.

### `IndependentBlendEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set to **TRUE** to enable independent blending in simultaneous render targets. If set to **FALSE**, only the RenderTarget[0] members are used. RenderTarget[1..7] are ignored.

### `RenderTarget`

Type: **[D3D10_RENDER_TARGET_BLEND_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ns-d3d10_1-d3d10_render_target_blend_desc1)**

An array of render-target-blend descriptions (see [D3D10_RENDER_TARGET_BLEND_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ns-d3d10_1-d3d10_render_target_blend_desc1)); these correspond to the eight rendertargets
that can be set to the output-merger stage at one time.

## Remarks

To see how blending is done, see [Output-Merger Stage (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage).

These are the default values for the blend description.

| State | Default Value |
| --- | --- |
| AlphaToCoverageEnable | **FALSE** |
| IndependentBlendEnable | **FALSE** |
| RenderTarget[0].BlendEnable | **FALSE** |
| RenderTarget[0].SrcBlend | D3D10_BLEND_ONE |
| RenderTarget[0].DestBlend | D3D10_BLEND_ZERO |
| RenderTarget[0].BlendOp | D3D10_BLEND_OP_ADD |
| RenderTarget[0].SrcBlendAlpha | D3D10_BLEND_ONE |
| RenderTarget[0].DestBlendAlpha | D3D10_BLEND_ZERO |
| RenderTarget[0].BlendOpAlpha | D3D10_BLEND_OP_ADD |
| RenderTarget[0].RenderTargetWriteMask | D3D10_COLOR_WRITE_ENABLE_ALL |

This structure requires Windows Vista Service Pack 1.

If the driver type is set to [D3D_DRIVER_TYPE_HARDWARE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type), the feature level is set to less than or equal to [D3D_FEATURE_LEVEL_9_3](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level), and the pixel format of the render target is set to [DXGI_FORMAT_R8G8B8A8_UNORM_SRGB](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), **DXGI_FORMAT_B8G8R8A8_UNORM_SRGB**, or **DXGI_FORMAT_B8G8R8X8_UNORM_SRGB**, the device performs the blend in standard RGB (sRGB) space and not in linear space. However, if the feature level is set to greater than **D3D_FEATURE_LEVEL_9_3**, the device performs the blend in linear space.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)