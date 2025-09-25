# IDirectDrawSurface7::Restore

## Description

Restores a surface that has been lost. This occurs when the surface memory that is associated with the DirectDrawSurface object has been freed.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_IMPLICITLYCREATED
* DDERR_INCOMPATIBLEPRIMARY
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOEXCLUSIVEMODE
* DDERR_OUTOFMEMORY
* DDERR_UNSUPPORTED
* DDERR_WRONGMODE

## Remarks

**Restore** restores the memory that was allocated for a surface, but does not reload any bitmaps that might have existed in the surface before it was lost.

Surfaces can be lost because the mode of the graphics adapter was changed or because an application received exclusive access to the graphics adapter and freed all surface memory currently allocated on the adapter. When a DirectDrawSurface object loses its surface memory, many methods return DDERR_SURFACELOST and perform no other function. The **IDirectDrawSurface7::Restore** method reallocates surface memory and reattaches it to the DirectDrawSurface object.

A single call to **Restore** restores a DirectDrawSurface object's associated implicit surfaces (back buffers, and so on). An attempt to restore an implicitly created surface results in an error. **Restore** does not work across explicit attachments that were created by using the [IDirectDrawSurface7::AddAttachedSurface](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-addattachedsurface) method—each of these surfaces must be restored individually.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)