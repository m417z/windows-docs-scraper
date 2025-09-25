## Description

Retrieves the status of the vertical blank.

## Parameters

### `unnamedParam1` [out]

A pointer to a variable that receives the status of the vertical blank. This parameter is TRUE if a vertical blank is occurring, and FALSE otherwise.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

To synchronize with the vertical blank, use the [IDirectDraw7::WaitForVerticalBlank](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-waitforverticalblank) method.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)