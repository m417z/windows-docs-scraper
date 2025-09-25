# DD_GETBLTSTATUSDATA structure

## Description

The DD_GETBLTSTATUSDATA structure returns the blit status information.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure representing the surface whose blit status is being queried.

### `dwFlags`

Specifies the blit status being requested. This member can be one of the following values:

| Flag | Meaning |
| --- | --- |
| DDGBS_CANBLT | Queries whether the driver can currently perform a blit. |
| DDGBS_ISBLTDONE | Queries whether the driver has completed the last blit. |

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdGetBltStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_getbltstatus) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetBltStatus`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## See also

[DdGetBltStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_getbltstatus)