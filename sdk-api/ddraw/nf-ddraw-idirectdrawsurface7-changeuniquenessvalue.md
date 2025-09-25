# IDirectDrawSurface7::ChangeUniquenessValue

## Description

Manually updates the uniqueness value for this surface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_EXCEPTION
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

DirectDraw automatically updates uniqueness values whenever the contents of a surface change.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)