# IDirectDrawSurface7::IsLost

## Description

Determines whether the surface memory that is associated with a DirectDrawSurface object has been freed.

## Return value

If the method succeeds, the return value is DD_OK because the memory has not been freed.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_SURFACELOST

You can use this method to determine when you need to reallocate surface memory. When a DirectDrawSurface object loses its surface memory, most methods return DDERR_SURFACELOST and perform no other action.

## Remarks

Surfaces can lose their memory when the mode of the graphics adapter is changed or when an application receives exclusive access to the graphics adapter and frees all surface memory that is currently allocated on the graphics adapter.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)