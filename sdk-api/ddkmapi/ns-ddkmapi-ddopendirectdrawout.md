# DDOPENDIRECTDRAWOUT structure

## Description

The DDOPENDIRECTDRAWOUT structure contains a new Microsoft DirectDraw handle for the [DD_DXAPI_OPENDIRECTDRAW](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550702(v=vs.85)) function identifier of the **DxApi** function if the **ddRVal** member of DDOPENDIRECTDRAWOUT is set to DD_OK. This new handle must be used on all subsequent calls that require a DirectDraw handle.

## Members

### `ddRVal`

Specifies the location in which DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for [DD_DXAPI_OPENDIRECTDRAW](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550702(v=vs.85)) operations. A return code of DD_OK indicates success.

### `hDirectDraw`

Handle to the new DirectDraw object.

## See also

[DD_DXAPI_OPENDIRECTDRAW](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550702(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)