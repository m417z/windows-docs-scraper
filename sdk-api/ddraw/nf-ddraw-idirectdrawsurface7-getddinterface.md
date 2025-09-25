# IDirectDrawSurface7::GetDDInterface

## Description

Retrieves an interface to the DirectDraw object that was used to create this surface.

## Parameters

### `unnamedParam1` [out]

A pointer to a variable that receives a valid interface pointer if the call succeeds. Cast this pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer; then query for the [IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7) interface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)

