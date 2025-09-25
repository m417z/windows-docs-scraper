## Description

Retrieves the current uniqueness value for this surface.

## Parameters

### `unnamedParam1` [out]

A pointer to a variable that receives the surface's current uniqueness value if the call succeeds.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

The only defined uniqueness value is 0, which indicates that the surface is likely to be changing beyond the control of DirectDraw. Other uniqueness values are significant only if they differ from a previously cached uniqueness value. If the current value is different from a cached value, the contents of the surface have changed.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)

