# IDirectDraw7::RestoreAllSurfaces

## Description

 Restores all the surfaces that were created for the DirectDraw object, in the order that they were created.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

This method is provided for convenience. Effectively, this method calls the [IDirectDrawSurface7::Restore](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-restore) method for each surface that is created by this DirectDraw object.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)