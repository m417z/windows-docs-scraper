# DD_GETVPORTLINEDATA structure

## Description

The DD_GETVPORTLINEDATA structure contains the current line number of the hardware video port.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

### `dwLine`

Specifies the location in which the driver should write the current line number on the hardware video port.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortGetLine](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getline) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetVideoPortLine`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdVideoPortGetLine](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getline)