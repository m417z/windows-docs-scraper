# DD_GETFLIPSTATUSDATA structure

## Description

The DD_GETFLIPSTATUSDATA structure returns the flip status information.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that describes the surface whose flip status is being queried.

### `dwFlags`

Specifies the flip status being requested. This member can be one of the following values:

| Flag | Meaning |
| --- | --- |
| DDGFS_CANFLIP | Queries whether the driver can currently perform a flip. |
| DDGFS_ISFLIPDONE | Queries whether the driver has finished the last flip. |

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdGetFlipStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_getflipstatus) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetFlipStatus`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## See also

[DdGetFlipStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_getflipstatus)