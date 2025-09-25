# DDOPENVIDEOPORTOUT structure

## Description

The DDOPENVIDEOPORTOUT structure contains a Microsoft DirectDraw return code and a new surface handle if **ddRVal** is set to DD_OK. This new handle must be used on all subsequent calls that require a [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object handle.

## Members

### `ddRVal`

Specifies the location in which DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for [DD_DXAPI_OPENVIDEOPORT](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551498(v=vs.85)) operations. A return code of DD_OK indicates success.

### `hVideoPort`

Handle to the new VPE object.

## See also

[DD_DXAPI_OPENVIDEOPORT](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551498(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)