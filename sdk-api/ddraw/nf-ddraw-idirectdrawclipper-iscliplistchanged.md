## Description

Retrieves the status of the clip list if a window handle is associated with a DirectDrawClipper object.

## Parameters

### `unnamedParam1` [out]

A pointer to a variable that receives the status of the clip list. This parameter is TRUE if the clip list has changed, and FALSE otherwise.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

## See also

[IDirectDrawClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawclipper)