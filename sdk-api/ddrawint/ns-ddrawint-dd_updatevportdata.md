# DD_UPDATEVPORTDATA structure

## Description

The DD_UPDATEVPORTDATA structure contains the information required to start, stop, and change the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this VPE object.

### `lplpDDSurface`

Points to an array of [DD_SURFACE_INT](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_int) structures that represent regular video surfaces. This member can be **NULL**.

### `lplpDDVBISurface`

Points to an array of DD_SURFACE_INT structures that represent [VBI](https://learn.microsoft.com/windows-hardware/drivers/) surfaces. This member can be **NULL**.

### `lpVideoInfo`

Points to a [DDVIDEOPORTINFO](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportinfo) structure that describes how the VPE object should transfer video data to a surface. This member can be **NULL** when **dwFlags** is DDRAWI_VPORTSTOP.

### `dwFlags`

Indicates the action to be performed by the VPE object. This member must be one of the following values:

| Flag | Meaning |
| --- | --- |
| DDRAWI_VPORTSTART | The driver should start the flow of data through the VPE object. |
| DDRAWI_VPORTSTOP | The driver should stop the flow of data through the VPE object. |
| DDRAWI_VPORTUPDATE | **DdVideoPortUpdate** has been called with a new set of flags in the **dwVPFlags** member of the DDVIDEOPORTINFO structure to which **lpVideoInfo** points. The driver should change the flow of data through the VPE object according to the new flags. |

### `dwNumAutoflip`

Specifies the number of surfaces in the list to which **lplpDDSurface** points. If this member is greater than 1, **lplpDDSurface** is an array of surface structures to accommodate autoflipping.

### `dwNumVBIAutoflip`

Specifies the number of surfaces in the list to which **lplpDDVBISurface** points. If this member is greater than 1, **lplpDDVBISurface** is an array of surface structures to accommodate autoflipping of [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortUpdate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_update) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `UpdateVideoPort`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DDVIDEOPORTINFO](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportinfo)

[DdVideoPortUpdate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_update)