## Description

Attaches a clipper object to, or deletes one from, this surface.

## Parameters

### `unnamedParam1` [in]

A pointer to the [IDirectDrawClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawclipper) interface for the DirectDrawClipper object to be attached to the DirectDrawSurface object. If you set this parameter to NULL, the current DirectDrawClipper object is detached.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDSURFACETYPE
* DDERR_NOCLIPPERATTACHED

## Remarks

When you set a clipper to a surface for the first time, **SetClipper** increments the clipper's reference count; subsequent calls do not affect the clipper's reference count. If you pass NULL as the *lpDDClipper* parameter, the clipper is removed from the surface, and the clipper's reference count is decremented. If you do not delete the clipper, the surface automatically releases its reference to the clipper when the surface itself is released. According to COM rules, your application must release any references that it holds to the clipper when the object is no longer needed.

**SetClipper** is primarily used by surfaces that are being overlaid on or bitbltted to the primary surface. However, it can be used on any surface. After a DirectDrawClipper object has been attached and a clip list is associated with it, the DirectDrawClipper object is used for the [IDirectDrawSurface7::Blt](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-blt), [IDirectDrawSurface7::BltBatch](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-bltbatch), and [IDirectDrawSurface7::UpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-updateoverlay) operations that involve the parent DirectDrawSurface object. **SetClipper** can also detach the current DirectDrawClipper object of a DirectDrawSurface object.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)

