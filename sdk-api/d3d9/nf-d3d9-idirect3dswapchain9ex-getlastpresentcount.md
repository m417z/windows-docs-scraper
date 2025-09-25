# IDirect3DSwapChain9Ex::GetLastPresentCount

## Description

Returns the number of times the swapchain has been processed.

## Parameters

### `pLastPresentCount` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a UINT to be filled with the number of times the [IDirect3DDevice9Ex::PresentEx](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-presentex) method has been called. The count will also be incremented by calling some other APIs such as [IDirect3DDevice9::SetDialogBoxMode](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-setdialogboxmode).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

S_OK the method was successful.

## See also

[IDirect3DSwapChain9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dswapchain9ex)