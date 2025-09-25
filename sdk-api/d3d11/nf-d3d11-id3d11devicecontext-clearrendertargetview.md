# ID3D11DeviceContext::ClearRenderTargetView

## Description

Set all the elements in a render target to one value.

## Parameters

### `pRenderTargetView` [in]

Type: **[ID3D11RenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rendertargetview)***

Pointer to the render target.

### `ColorRGBA` [in]

Type: **const [FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[4]**

A 4-component array that represents the color to fill the render target with.

## Remarks

Applications that wish to clear a render target to a specific integer value bit pattern should render a screen-aligned quad instead of using this method. The reason for this is because this method accepts as input a floating point value, which may not have the same bit pattern as the original integer.

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 11/10:<br><br>Unlike Direct3D 9, the full extent of the resource view is always cleared. Viewport and scissor settings are not applied. |

When using [D3D_FEATURE_LEVEL_9_x](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level), [ClearRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-clearrendertargetview) only clears the first array slice in the render target view. This can impact (for example) cube map rendering scenarios. Applications should create a render target view for each face or array slice, then clear each view individually.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)