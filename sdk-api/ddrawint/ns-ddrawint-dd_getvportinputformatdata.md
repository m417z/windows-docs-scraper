# DD_GETVPORTINPUTFORMATDATA structure

## Description

The DD_GETVPORTINPUTFORMATDATA structure contains the information required for the driver to return the input formats that the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object can accept.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this VPE object.

### `dwFlags`

Indicates the type of formats for which support is being queried. This member can be one or more of the following values:

| Flag | Meaning |
| --- | --- |
| DDVPFORMAT_VBI | The driver should return formats for the [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data. |
| DDVPFORMAT_VIDEO | The driver should return formats for the video data. |

### `lpddpfFormat`

Points to an array of [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structures in which the driver should write the pixel formats supported by the VPE object. This member can be **NULL**.

### `dwNumFormats`

Specifies the location in which the driver should write the number of formats that the VPE object supports.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortGetInputFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getinputformats) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetVideoPortInputFormats`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdVideoPortGetInputFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getinputformats)