# DD_GETVPORTCONNECTDATA structure

## Description

The DD_GETVPORTCONNECTDATA structure contains the connection combinations supported by the specified [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `dwPortId`

Specifies the ID of the VPE object for which the driver is to retrieve connection information. DirectDraw obtains this ID from the **dwVideoPortID** member of the [DDVIDEOPORTCAPS](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportcaps) structure.

### `lpConnect`

Points to an array of [DDVIDEOPORTCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddvideoportconnect) structures in which the driver should return the characteristics of each connection that the VPE object supports. This member can be **NULL**.

### `dwNumEntries`

Specifies the location in which the driver returns the number of connection combinations supported by the specified VPE object.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortGetConnectInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getvportconnect) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetVideoPortConnectInfo`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DDVIDEOPORTCAPS](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportcaps)

[DDVIDEOPORTCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddvideoportconnect)

[DdVideoPortGetConnectInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getvportconnect)