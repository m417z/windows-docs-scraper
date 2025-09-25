# IDirectDrawSurface7::DeleteAttachedSurface

## Description

Detaches one or more attached surfaces.

## Parameters

### `unnamedParam1` [in]

Currently not used and must be set to 0.

### `unnamedParam2` [in]

A pointer to the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for the DirectDrawSurface object to be detached. If this parameter is NULL, all attached surfaces become detached.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_CANNOTDETACHSURFACE
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_SURFACELOST
* DDERR_SURFACENOTATTACHED

## Remarks

**DeleteAttachedSurface** decrements the reference count of the surface to be detached. If the reference count of the surface to be detached reaches 0, the surface is lost and removed from memory.

Implicit attachments, those formed by DirectDraw rather than the [IDirectDrawSurface7::AddAttachedSurface](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-addattachedsurface) method, cannot be detached. Detaching surfaces from a flipping chain can alter other surfaces in the chain. If a front buffer is detached from a flipping chain, the next surface in the chain becomes the front buffer, and the following surface becomes the back buffer. If a back buffer is detached from a chain, the following surface becomes a back buffer. If a plain surface is detached from a chain, the chain simply becomes shorter. If a flipping chain has only two surfaces and they are detached, the chain is destroyed, and both surfaces return to their previous designations.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)