# ID3D11DeviceContext::OMSetBlendState

## Description

Set the blend state of the output-merger stage.

## Parameters

### `pBlendState` [in, optional]

Type: **[ID3D11BlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11blendstate)***

Pointer to a blend-state interface (see [ID3D11BlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11blendstate)). Pass **NULL** for a default blend state. For more info about default blend state, see Remarks.

### `BlendFactor` [in, optional]

Type: **const [FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[4]**

Array of blend factors, one for each RGBA component. The blend factors modulate values for the pixel shader, render target, or both. If you created the blend-state object with [D3D11_BLEND_BLEND_FACTOR](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend) or [D3D11_BLEND_INV_BLEND_FACTOR](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend), the blending stage uses the non-NULL array of blend factors. If you didn't create the blend-state object with **D3D11_BLEND_BLEND_FACTOR** or **D3D11_BLEND_INV_BLEND_FACTOR**, the blending stage does not use the non-NULL array of blend factors; the runtime stores the blend factors, and you can later call [ID3D11DeviceContext::OMGetBlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omgetblendstate) to retrieve the blend factors. If you pass **NULL**, the runtime uses or stores a blend factor equal to { 1, 1, 1, 1 }.

### `SampleMask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

32-bit sample coverage. The default value is 0xffffffff. See remarks.

## Remarks

Blend state is used by the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) to determine how to blend together two RGB pixel values and two alpha values. The two RGB pixel values and two alpha values are the RGB pixel value and alpha value that the pixel shader outputs and the RGB pixel value and alpha value already in the output render target. The [blend option](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend) controls the data source that the blending stage uses to modulate values for the pixel shader, render target, or both. The [blend operation](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_blend_op) controls how the blending stage mathematically combines these modulated values.

To create a blend-state interface, call [ID3D11Device::CreateBlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createblendstate).

Passing in **NULL** for the blend-state interface indicates to the runtime to set a default blending state. The following table indicates the default blending parameters.

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

A sample mask determines which samples get updated in all the active render targets. The mapping of bits in a sample mask to samples in a multisample render target is the responsibility of an individual application. A sample mask is always applied; it is independent of whether multisampling is enabled, and does not depend on whether an application uses multisample render targets.

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)