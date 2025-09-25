# IDXGISwapChain::GetFullscreenState

## Description

Get the state associated with full-screen mode.

## Parameters

### `pFullscreen` [out, optional]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a boolean whose value is either:

* **TRUE** if the swap chain is in full-screen mode
* **FALSE** if the swap chain is in windowed mode

### `ppTarget` [out, optional]

Type: **[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)****

A pointer to the output target (see [IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)) when the mode is full screen; otherwise **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

When the swap chain is in full-screen mode, a pointer to the target output will be returned and its reference count will be incremented.

## See also

[IDXGISwapChain](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiswapchain)