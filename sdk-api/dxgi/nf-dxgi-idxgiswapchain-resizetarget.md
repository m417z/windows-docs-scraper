# IDXGISwapChain::ResizeTarget

## Description

Resizes the output target.

## Parameters

### `pNewTargetParameters` [in]

Type: **const [DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85))***

A pointer to a [DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85)) structure that describes the mode, which specifies the new width, height, format, and refresh rate of the target.
If the format is [DXGI_FORMAT_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), **ResizeTarget** uses the existing format. We only recommend that you use **DXGI_FORMAT_UNKNOWN** when the swap chain is in full-screen
mode as this method is not thread safe.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns a code that indicates success or failure. **DXGI_STATUS_MODE_CHANGE_IN_PROGRESS** is returned if a full-screen/windowed mode transition is occurring
when this API is called. See [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) for additional DXGI error codes.

## Remarks

**ResizeTarget** resizes the target window when the swap chain is in windowed mode, and changes the display mode on the target output when the swap
chain is in full-screen mode. Therefore, apps can call **ResizeTarget** to resize the target window (rather than a Microsoft Win32API such as [SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos))
without knowledge of the swap chain display mode.

If a Windows Store app calls **ResizeTarget**, it fails with [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

You cannot call **ResizeTarget** on a swap chain that you created with [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition).

Apps must still call [IDXGISwapChain::ResizeBuffers](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-resizebuffers) after they call **ResizeTarget** because only **ResizeBuffers** can change the back buffers. But, if those apps have implemented window resize processing to call **ResizeBuffers**, they don't need to explicitly call **ResizeBuffers** after they call **ResizeTarget** because the window resize processing will achieve what the app requires.

## See also

[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)