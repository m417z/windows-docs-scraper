# ID3D10Device::OMSetBlendState

## Description

Set the [blend state](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) of the output-merger stage.

## Parameters

### `pBlendState` [in]

Type: **[ID3D10BlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10blendstate)***

Pointer to a blend-state interface (see [ID3D10BlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10blendstate)). Passing in **NULL** implies a default blend state. See remarks for further details.

### `BlendFactor` [in]

Type: **const [FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of blend factors, one for each RGBA component. The blend factors modulate values for the pixel shader, render target, or both. If you created the blend-state object with [D3D10_BLEND_BLEND_FACTOR](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend) or [D3D10_BLEND_INV_BLEND_FACTOR](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend), the blending stage uses the non-NULL array of blend factors. If you didn't create the blend-state object with **D3D10_BLEND_BLEND_FACTOR** or **D3D10_BLEND_INV_BLEND_FACTOR**, the blending stage does not use the non-NULL array of blend factors; the runtime stores the blend factors, and you can later call [ID3D11DeviceContext::OMGetBlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omgetblendstate) to retrieve the blend factors. If you pass **NULL**, the runtime uses or stores a blend factor equal to { 1, 1, 1, 1 }.

### `SampleMask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

32-bit sample coverage. The default value is 0xffffffff. See remarks.

## Remarks

Blend state is used by the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) to determine how to blend together two RGB pixel values and two alpha values. The two RGB pixel values and two alpha values are the RGB pixel value and alpha value that the pixel shader outputs and the RGB pixel value and alpha value already in the output render target. The [blend option](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend) controls the data source that the blending stage uses to modulate values for the pixel shader, render target, or both. The [blend operation](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend_op) controls how the blending stage mathematically combines these modulated values.

To create a blend-state interface, call [ID3D10Device::CreateBlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createblendstate).

Passing in **NULL** for the blend-state interface indicates to the runtime to set a default blending state. The following table indicates the default blending parameters.

| State | Default Value |
| --- | --- |
| AlphaToCoverageEnable | **FALSE** |
| BlendEnable | **FALSE**[8] |
| SrcBlend | D3D10_BLEND_ONE |
| DstBlend | D3D10_BLEND_ZERO |
| BlendOp | D3D10_BLEND_OP_ADD |
| SrcBlendAlpha | D3D10_BLEND_ONE |
| DstBlendAlpha | D3D10_BLEND_ZERO |
| BlendOpAlpha | D3D10_BLEND_OP_ADD |
| RenderTargetWriteMask[8] | D3D10_COLOR_WRITE_ENABLE_ALL[8] |

A sample mask determines which samples get updated in all the active render targets. The mapping of bits in a sample mask to samples in a multisample render target is the responsibility of an individual application. A sample mask is always applied; it is independent of whether multisampling is enabled, and does not depend on whether an application uses multisample render targets.

The method will not hold a reference to the interfaces passed in. For that reason, applications should be careful not to release an interface currently in use by the device.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)