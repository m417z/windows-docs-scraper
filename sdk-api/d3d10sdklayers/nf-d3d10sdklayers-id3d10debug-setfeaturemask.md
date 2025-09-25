# ID3D10Debug::SetFeatureMask

## Description

Set a bitfield of flags that will turn debug features on and off.

## Parameters

### `Mask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Feature-mask flags bitwise ORed together. If a flag is present, then that feature will be set to on, otherwise the feature will be set to off. See remarks for a list of flags.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

**Note** If you call this API in a Session 0 process, it returns [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

Setting a feature-mask flag will cause a rendering-operation method (listed below) to do some extra task when called. The possible feature flags are:

|  |  |
| --- | --- |
| D3D10_DEBUG_FEATURE_FINISH_PER_RENDER_OP | Application will wait for the GPU to finish processing the rendering operation before continuing. |
| D3D10_DEBUG_FEATURE_FLUSH_PER_RENDER_OP | Runtime will additionally call [ID3D10Device::Flush](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-flush). |
| D3D10_DEBUG_FEATURE_PRESENT_PER_RENDER_OP | Runtime will call [Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present). Presentation of render buffers will occur according to the settings established by prior calls to [ID3D10Debug::SetSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10debug-setswapchain) and [ID3D10Debug::SetPresentPerRenderOpDelay](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10debug-setpresentperrenderopdelay). |

These feature-mask flags apply to the following rendering-operation methods:

* [ID3D10Device::Draw](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-draw)
* [ID3D10Device::DrawIndexed](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-drawindexed)
* [ID3D10Device::DrawInstanced](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-drawinstanced)
* [ID3D10Device::DrawIndexedInstanced](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-drawindexedinstanced)
* [ID3D10Device::DrawAuto](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-drawauto)
* [ID3D10Device::ClearRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-clearrendertargetview)
* [ID3D10Device::ClearDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-cleardepthstencilview)
* [ID3D10Device::CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copysubresourceregion)
* [ID3D10Device::CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-copyresource)
* [ID3D10Device::UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-updatesubresource)
* [ID3D10Device::GenerateMips](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-generatemips)
* [ID3D10Device::ResolveSubresource](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-resolvesubresource)

## See also

[ID3D10Debug Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10debug)