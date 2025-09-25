# IDirect3DDevice9::GetSwapChain

## Description

Gets a pointer to a swap chain.

## Parameters

### `iSwapChain` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The swap chain ordinal value. For more information, see NumberOfAdaptersInGroup in [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9).

### `pSwapChain` [in]

Type: **[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)****

Pointer to an [IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9) interface that will receive a copy of swap chain.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be one of the following: D3DERR_INVALIDCALL.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)