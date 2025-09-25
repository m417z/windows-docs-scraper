## Description

Retrieves the current color-control settings that are associated with an overlay or a primary surface.

## Parameters

### `unnamedParam1` [in, out]

A pointer to a [DDCOLORCONTROL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549237(v=vs.85)) structure that receives the current control settings.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_UNSUPPORTED

## Remarks

The **dwFlags** member of the [DDCOLORCONTROL](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549237(v=vs.85)) structure indicates which of the color-control options are supported.

## See also

[IDirectDrawColorControl](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawcolorcontrol)

