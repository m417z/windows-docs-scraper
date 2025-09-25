# IDirect3DDevice9::SetViewport

## Description

Sets the viewport parameters for the device.

## Parameters

### `pViewport` [in]

Type: **const [D3DVIEWPORT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dviewport9)***

Pointer to a [D3DVIEWPORT9](https://learn.microsoft.com/windows/desktop/direct3d9/d3dviewport9) structure, specifying the viewport parameters to set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK. If the method fails, it will return D3DERR_INVALIDCALL. This will happen if pViewport is invalid, or if pViewport describes a region that cannot exist within the render target surface.

## Remarks

Direct3D sets the following default values for the viewport.

```

D3DVIEWPORT9 vp;
vp.X      = 0;
vp.Y      = 0;
vp.Width  = RenderTarget.Width;
vp.Height = RenderTarget.Height;
vp.MinZ   = 0.0f;
vp.MaxZ   = 1.0f;

```

**IDirect3DDevice9::SetViewport** can be used to draw on part of the screen. Make sure to call it before any geometry is drawn so the viewport settings will take effect.

To draw multiple views within a scene, repeat the **IDirect3DDevice9::SetViewport** and draw geometry sequence for each view.

## See also

[IDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3ddevice9)

[IDirect3DDevice9::GetViewport](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9-getviewport)