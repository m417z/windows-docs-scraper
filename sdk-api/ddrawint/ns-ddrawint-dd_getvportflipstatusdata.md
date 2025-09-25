# DD_GETVPORTFLIPSTATUSDATA structure

## Description

The DD_GETVPORTFLIPSTATUSDATA structure contains the flip status information for the specified surface.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `fpSurface`

Points to the surface for which the flip status information is required.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortGetFlipStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getflipstatus) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetVideoPortFlipStatus`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdVideoPortGetFlipStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getflipstatus)