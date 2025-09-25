# IDirectDrawClipper::SetHWnd

## Description

Sets the window handle that the clipper object uses to obtain clipping information.

## Parameters

### `unnamedParam1` [in]

Currently not used and must be set to 0.

### `unnamedParam2` [in]

Window handle that obtains the clipping information.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDCLIPLIST
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_OUTOFMEMORY

## Remarks

## See also

[IDirectDrawClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawclipper)