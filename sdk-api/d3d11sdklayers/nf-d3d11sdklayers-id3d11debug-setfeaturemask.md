# ID3D11Debug::SetFeatureMask

## Description

Set a bit field of flags that will turn debug features on and off.

## Parameters

### `Mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of feature-mask flags that are combined by using a bitwise OR operation. If a flag is present, that feature will be set to on, otherwise the feature will be set to off. For descriptions of the feature-mask flags, see Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**Note** If you call this API in a Session 0 process, it returns [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

Setting one of the following feature-mask flags will cause a rendering-operation method (listed below) to do some extra task when called.

|  |  |
| --- | --- |
| D3D11_DEBUG_FEATURE_FINISH_PER_RENDER_OP (0x2) | Application will wait for the GPU to finish processing the rendering operation before continuing. |
| D3D11_DEBUG_FEATURE_FLUSH_PER_RENDER_OP (0x1) | Runtime will additionally call [ID3D11DeviceContext::Flush](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-flush). |
| D3D11_DEBUG_FEATURE_PRESENT_PER_RENDER_OP (0x4) | Runtime will call [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present). Presentation of render buffers will occur according to the settings established by prior calls to [ID3D11Debug::SetSwapChain](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11debug-setswapchain) and [ID3D11Debug::SetPresentPerRenderOpDelay](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nf-d3d11sdklayers-id3d11debug-setpresentperrenderopdelay). |

These feature-mask flags apply to the following rendering-operation methods:

* [ID3D11DeviceContext::Draw](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-draw)
* [ID3D11DeviceContext::DrawIndexed](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawindexed)
* [ID3D11DeviceContext::DrawInstanced](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawinstanced)
* [ID3D11DeviceContext::DrawIndexedInstanced](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawindexedinstanced)
* [ID3D11DeviceContext::DrawAuto](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-drawauto)
* [ID3D11DeviceContext::ClearRenderTargetView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearrendertargetview)
* [ID3D11DeviceContext::ClearDepthStencilView](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-cleardepthstencilview)
* [ID3D11DeviceContext::CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copysubresourceregion)
* [ID3D11DeviceContext::CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copyresource)
* [ID3D11DeviceContext::UpdateSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-updatesubresource)
* [ID3D11DeviceContext::GenerateMips](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-generatemips)
* [ID3D11DeviceContext::ResolveSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-resolvesubresource)

By setting one of the following feature-mask flags, you can control the behavior of the [IDXGIDevice2::OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources) and [IDXGIDevice2::ReclaimResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-reclaimresources) methods to aid in testing and debugging.

**Note** These flags are supported by the Direct3D 11.1 runtime, which is available starting with Windows 8.

|  |  |
| --- | --- |
| D3D11_DEBUG_FEATURE_ALWAYS_DISCARD_OFFERED_RESOURCE (0x8) | When you call [IDXGIDevice2::OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources) to offer resources while this flag is enabled, their content is always discarded. Use this flag to test code paths that regenerate resource content on reclaim. You cannot use this flag in combination with D3D11_DEBUG_FEATURE_NEVER_DISCARD_OFFERED_RESOURCE. |
| D3D11_DEBUG_FEATURE_NEVER_DISCARD_OFFERED_RESOURCE (0x10) | When you call [IDXGIDevice2::OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources) to offer resources while this flag is enabled, their content is never discarded. Use this flag to test code paths that do not need to regenerate resource content on reclaim. You cannot use this flag in combination with D3D11_DEBUG_FEATURE_ALWAYS_DISCARD_OFFERED_RESOURCE. |

The behavior of the [IDXGIDevice2::OfferResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-offerresources) and [IDXGIDevice2::ReclaimResources](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidevice2-reclaimresources) methods depends on system-wide memory pressure. Therefore, the scenario where content is lost and must be regenerated is uncommon for most applications. The preceding new options in the Direct3D debug layer let you simulate that scenario consistently and test code paths.

The following flag is supported by the Direct3D 11.1 runtime.

|  |  |
| --- | --- |
| D3D11_DEBUG_FEATURE_AVOID_BEHAVIOR_CHANGING_DEBUG_AIDS (0x40) | Disables the following default debugging behavior. |

When the debug layer is enabled, it performs certain actions to reveal application problems. By setting the D3D11_DEBUG_FEATURE_AVOID_BEHAVIOR_CHANGING_DEBUG_AIDS feature-mask flag, you can enable the debug layer without getting the following default debugging behavior:

* If an application calls [ID3D11DeviceContext1::DiscardView](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-discardview), the runtime fills in the resource with a random color.
* If an application calls [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) with partial presentation parameters, the runtime ignores the partial presentation information.

The following flag is supported by the Direct3D 11.2 runtime.

|  |  |
| --- | --- |
| D3D11_DEBUG_FEATURE_DISABLE_TILED_RESOURCE_MAPPING_TRACKING_AND_VALIDATION (0x80) | Disables the following default debugging behavior. |

By default (that is, without D3D11_DEBUG_FEATURE_DISABLE_TILED_RESOURCE_MAPPING_TRACKING_AND_VALIDATION set), the debug layer validates the proper usage of all tile mappings for [tiled resources](https://learn.microsoft.com/windows/desktop/direct3d11/direct3d-11-2-features) for bound resources for every operation performed on the device context (for example, draw, copy, and so on). Depending on the size of the tiled resources used (if any), this validation can be processor intensive and slow. Apps might want to initially run with tiled resource tile mapping validation on; then, when they determine that the calling pattern is safe, they can disable the validation by setting D3D11_DEBUG_FEATURE_DISABLE_TILED_RESOURCE_MAPPING_TRACKING_AND_VALIDATION.

If D3D11_DEBUG_FEATURE_DISABLE_TILED_RESOURCE_MAPPING_TRACKING_AND_VALIDATION is set when a tiled resource is created, the debug layer never performs the tracking of tile mapping for that resource for its entire lifetime. Alternatively, if D3D11_DEBUG_FEATURE_DISABLE_TILED_RESOURCE_MAPPING_TRACKING_AND_VALIDATION is set for any given device context method call (like draw or copy calls) involving tiled resources, the debug layer skips all tile mapping validation for the call.

## See also

[ID3D11Debug Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11debug)