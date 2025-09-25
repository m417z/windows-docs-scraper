## Description

Notifies DirectDraw that the direct surface manipulations are complete.

## Parameters

### `unnamedParam1` [in]

A pointer to a **RECT** structure that was used to lock the surface in the corresponding call to the [IDirectDrawSurface7::Lock](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-lock) method. This parameter can be NULL only if the entire surface was locked by passing NULL in the *lpDestRect* parameter of the corresponding call to the **IDirectDrawSurface7::Lock** method.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDRECT
* DDERR_NOTLOCKED
* DDERR_SURFACELOST

## Remarks

Because you can call [IDirectDrawSurface7::Lock](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-lock) multiple times for the same surface with different destination rectangles, the pointer in *lpRect* links the calls to the **IDirectDrawSurface7::Lock** and **IDirectDrawSurface7::Unlock** methods.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)