## Description

Retrieves a description of this surface in its current condition.

## Parameters

### `unnamedParam1` [in, out]

A pointer to a [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure that receives the current description of this surface. You need only initialize this structure's **dwSize** member to the size, in bytes, of the structure prior to the call; no other preparation is required.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)