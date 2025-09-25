# IDirect3DDevice9::GetRenderTarget

## Description

Retrieves a render-target surface.

## Parameters

### `RenderTargetIndex` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the render target. See Remarks.

### `ppRenderTarget` [out]

Type: **[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)****

Address of a pointer to an [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface, representing the returned render-target surface for this device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL if one of the arguments is invalid, or D3DERR_NOTFOUND if there's no render target available for the given index.

## Remarks

Typically, methods that return state will not work on a device that is created using D3DCREATE_PUREDEVICE. This method however, will work even on a pure device because it returns an interface.

The device can now support multiple render targets. The number of render targets supported by a device is contained in the NumSimultaneousRTs member of [D3DCAPS9](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcaps9). See [Multiple Render Targets (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/multiple-render-targets).

Calling this method will increase the internal reference count on the [IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9) interface. Failure to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when finished using the **IDirect3DSurface9** interface results in a memory leak.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::SetRenderTarget](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-setrendertarget)