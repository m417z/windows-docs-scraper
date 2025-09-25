# DDOPENVIDEOPORTIN structure

## Description

The DDOPENVIDEOPORTIN structure contains the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object information.

## Members

### `hDirectDraw`

Specifies the Microsoft DirectDraw object to which the surface handle is associated.

### `dwVideoPortHandle`

Specifies the hardware video port ID that was passed down when the VPE object was created in user mode.

### `pfnVideoPortClose`

Points to a [pfnVideoPortClose](https://learn.microsoft.com/windows/desktop/api/ddkmapi/nc-ddkmapi-lpdd_notifycallback) callback function that is called when the VPE object becomes unusable.

### `pContext`

Contains a value that is passed if the **pfnVideoPortClose** callback function is ever called.

## See also

[DD_DXAPI_OPENVIDEOPORT](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551498(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)