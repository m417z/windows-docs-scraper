# IDirect3DSurface9::GetContainer

## Description

Provides access to the parent cube texture or texture (mipmap) object, if this surface is a child level of a cube texture or a mipmap. This method can also provide access to the parent swap chain if the surface is a back-buffer child.

## Parameters

### `riid` [in]

Type: **REFIID**

Reference identifier of the container being requested.

### `ppContainer` [out]

Type: **void****

Address of a pointer to fill with the container pointer if the query succeeds. See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, the return value can be D3DERR_INVALIDCALL.

## Remarks

If the surface is created using [CreateRenderTarget](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createrendertarget) or [CreateOffscreenPlainSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createoffscreenplainsurface) or [CreateDepthStencilSurface](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-createdepthstencilsurface), the surface is considered stand alone. In this case, **GetContainer** will return the Direct3D device used to create the surface.

If the call succeeds, the reference count of the container is increased by one.

Here's an example getting the parent texture of a mip surface.

```

// Assumes pSurface is a valid IDirect3DSurface9 pointer
void *pContainer = NULL;
IDirect3DTexture9 *pTexture = NULL;
HRESULT hr = pSurface->GetContainer(IID_IDirect3DTexture9, &pContainer);
if (SUCCEEDED(hr) && pContainer)
{
    pTexture = (IDirect3DTexture9 *)pContainer;
}

```

## See also

[IDirect3DSurface9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dsurface9)