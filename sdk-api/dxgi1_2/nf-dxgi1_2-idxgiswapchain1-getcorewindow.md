# IDXGISwapChain1::GetCoreWindow

## Description

Retrieves the underlying [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) object for this swap-chain object.

## Parameters

### `refiid` [in]

A pointer to the globally unique identifier (GUID) of the [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) object that is referenced by
the *ppUnk* parameter.

### `ppUnk` [out]

A pointer to a variable that receives a pointer to the [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) object.

## Return value

**GetCoreWindow** returns:

* S_OK if it successfully retrieved the underlying [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) object.
* [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) if *ppUnk* is **NULL**; that is, the swap chain is not associated with a [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) object.
* Any [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) that a call to [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to query for an [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) object might typically return.
* Possibly other error codes that are described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **GetCoreWindow** fails with E_NOTIMPL. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

Applications call the [IDXGIFactory2::CreateSwapChainForCoreWindow](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcorewindow) method to create a swap chain that is associated with an [CoreWindow](https://learn.microsoft.com/uwp/api/Windows.UI.Core.CoreWindow) object.

## See also

[IDXGISwapChain1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiswapchain1)