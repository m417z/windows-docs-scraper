# IDirectDrawClipper::SetClipList

## Description

Sets or deletes the clip list that is used by the [IDirectDrawSurface7::Blt](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-blt), [IDirectDrawSurface7::BltBatch](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-bltbatch), and [IDirectDrawSurface7::UpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-updateoverlay) methods on surfaces to which the parent DirectDrawClipper object is attached.

## Parameters

### `unnamedParam1` [in]

A pointer to a valid [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata) structure for the clip list to set or NULL. If there is an existing clip list that is associated with the DirectDrawClipper object and this value is NULL, the clip list is deleted.

### `unnamedParam2` [in]

Currently not used and must be set to 0.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_CLIPPERISUSINGHWND
* DDERR_INVALIDCLIPLIST
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_OUTOFMEMORY

## Remarks

You cannot set the clip list if a window handle is already associated with the DirectDrawClipper object.

The [IDirectDrawSurface7::BltFast](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-bltfast) method cannot clip. If you call **IDirectDrawSurface7::BltFast** on a surface with an attached clipper, it returns DDERR_UNSUPPORTED.

## See also

[IDirectDrawClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawclipper)