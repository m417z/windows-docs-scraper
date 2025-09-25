# DD_CANCREATEVPORTDATA structure

## Description

The DD_CANCREATEVPORTDATA structure contains the information required for the driver to determine whether a [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object can be created.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpDDVideoPortDesc`

Points to a [DDVIDEOPORTDESC](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportdesc) structure that contains a description of the VPE object being requested.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortCanCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_cancreatevideoport) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `CanCreateVideoPort`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdVideoPortCanCreate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_cancreatevideoport)