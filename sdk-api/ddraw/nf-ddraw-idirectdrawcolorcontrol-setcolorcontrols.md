## Description

Sets the color-control options for an overlay or a primary surface.

## Parameters

### `unnamedParam1` [in]

A pointer to a [DDCOLORCONTROL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549237(v=vs.85)) structure that contains the new control settings to apply.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_UNSUPPORTED

## Remarks

## See also

[IDirectDrawColorControl](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawcolorcontrol)