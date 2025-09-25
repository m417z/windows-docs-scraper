# DD_DESTROYVPORTDATA structure

## Description

The DD_DESTROYVPORTDATA structure contains the information necessary for the driver to clean up.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortDestroy](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_destroyvport) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `DestroyVideoPort`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdVideoPortDestroy](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_destroyvport)