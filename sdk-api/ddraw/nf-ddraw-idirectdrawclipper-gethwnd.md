## Description

Retrieves the window handle that was previously associated with this DirectDrawClipper object by the [IDirectDrawClipper::SetHWnd](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawclipper-sethwnd) method.

## Parameters

### `unnamedParam1` [out]

A pointer to a variable that receives the window handle that was previously associated with this DirectDrawClipper object by the [IDirectDrawClipper::SetHWnd](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawclipper-sethwnd) method.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

## See also

[IDirectDrawClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawclipper)

