# DD_CREATEVPORTDATA structure

## Description

The DD_CREATEVPORTDATA structure contains the information necessary to describe the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object being created.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpDDVideoPortDesc`

Points to a [DDVIDEOPORTDESC](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportdesc) structure that describes the created VPE object.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents the created VPE object.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_createvideoport) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `CreateVideoPort`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdVideoPortCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_createvideoport)