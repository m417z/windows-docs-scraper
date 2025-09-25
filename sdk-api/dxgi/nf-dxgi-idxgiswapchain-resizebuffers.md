# IDXGISwapChain::ResizeBuffers

## Description

Changes the swap chain's back buffer size, format, and number of buffers.
This should be called when the application window is resized.

## Parameters

### `BufferCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of buffers in the swap chain (including all back and front buffers).
This number can be different from the number of buffers with which you created the swap chain.
This number can't be greater than **DXGI_MAX_SWAP_CHAIN_BUFFERS**.
Set this number to zero to preserve the existing number of buffers in the swap chain.
You can't specify less than two buffers for the flip presentation model.

### `Width`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The new width of the back buffer.
If you specify zero, DXGI will use the width of the client area of the target window.
You can't specify the width as zero if you called the [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition) method to create the swap chain for a composition surface.

### `Height`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The new height of the back buffer.
If you specify zero, DXGI will use the height of the client area of the target window.
You can't specify the height as zero if you called the [IDXGIFactory2::CreateSwapChainForComposition](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgifactory2-createswapchainforcomposition) method to create the swap chain for a composition surface.

### `NewFormat`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value for the new format of the back buffer.
Set this value to [DXGI_FORMAT_UNKNOWN](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) to preserve the existing format of the back buffer.
The flip presentation model supports a more restricted set of formats than the bit-block transfer (bitblt) model.

### `SwapChainFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [DXGI_SWAP_CHAIN_FLAG](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag)-typed values that are combined by using a bitwise OR operation.
The resulting value specifies options for swap-chain behavior.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; an error code otherwise.
For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

You can't resize a swap chain unless you release all outstanding references to its back buffers.
You must release all of its direct and indirect references on the back buffers in order for **ResizeBuffers** to succeed.

Direct references are held by the application after it calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on a resource.

Indirect references are held by views to a resource, binding a view of the resource to a device context,
a command list that used the resource, a command list that used a view to that resource, a command list that executed another command list that used the
resource, and so on.

Before you call **ResizeBuffers**, ensure that the application releases all references
(by calling the appropriate number of [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) invocations) on the resources, any views to the resource, and any command lists that use either the resources or views,
and ensure that neither the resource nor a view is still bound to a device context.
You can use [ID3D11DeviceContext::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearstate) to ensure that all references are released.
If a view is bound to a deferred context, you must discard the partially built command list as well (by calling
**ID3D11DeviceContext::ClearState**, then
[ID3D11DeviceContext::FinishCommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-finishcommandlist), then
**Release** on the command list).
After you call **ResizeBuffers**, you can re-query interfaces via [IDXGISwapChain::GetBuffer](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-getbuffer).

For swap chains that you created with [DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_chain_flag),
before you call **ResizeBuffers**, also call [IDXGISurface1::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgisurface1-releasedc) on the swap chain's back-buffer surface
to ensure that you have no outstanding GDI device contexts (DCs) open.

We recommend that you call **ResizeBuffers** when a client window is resized (that is, when an application receives a WM_SIZE message).

The only difference between **IDXGISwapChain::ResizeBuffers** in Windows 8 versus Windows 7 is with
flip presentation model swap chains that you create with the [DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL](https://learn.microsoft.com/windows/desktop/api/dxgi/ne-dxgi-dxgi_swap_effect) or DXGI_SWAP_EFFECT_FLIP_DISCARD value set.
In Windows 8, you must call **ResizeBuffers** to realize a transition between full-screen mode and windowed mode;
otherwise, your next call to the [IDXGISwapChain::Present](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiswapchain-present) method fails.

## See also

[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)