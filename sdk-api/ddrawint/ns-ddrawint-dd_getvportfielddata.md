# DD_GETVPORTFIELDDATA structure

## Description

The DD_GETVPORTFIELDDATA structure contains the information required for the driver to determine whether the current field of an interlaced signal is even or odd.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

### `bField`

Specifies the location in which the driver should indicate the polarity of the field. This member should be set to **TRUE** if the current field is the even field of an interlaced signal and to **FALSE** if the current field is the odd field.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortGetField](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getfield) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetVideoPortField`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdVideoPortGetField](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getfield)