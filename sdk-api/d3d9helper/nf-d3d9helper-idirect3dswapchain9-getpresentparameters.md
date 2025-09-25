# IDirect3DSwapChain9::GetPresentParameters

## Description

Retrieves the presentation parameters associated with a swap chain.

## Parameters

### `pPresentationParameters` [out, retval]

Type: **[D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters)***

Pointer to the presentation parameters. See [D3DPRESENT_PARAMETERS](https://learn.microsoft.com/windows/desktop/direct3d9/d3dpresent-parameters).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

This method can be used to see the presentation parameters of the parent swap chain of a surface (a back buffer, for instance). The parent swap chain can be retrieved with [IDirect3DSurface9::GetContainer](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3dsurface9-getcontainer).

## See also

[IDirect3DSwapChain9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dswapchain9)