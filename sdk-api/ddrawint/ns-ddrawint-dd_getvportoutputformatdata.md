# DD_GETVPORTOUTPUTFORMATDATA structure

## Description

The DD_GETVPORTOUTPUTFORMATDATA structure contains the information required for the driver to return all of the output formats that the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object supports for a given input format.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to the [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this VPE object.

### `dwFlags`

Indicates the type of output formats for which support is being queried. This member can be one or more of the following values:

| Flag | Meaning |
| --- | --- |
| DDVPFORMAT_VBI | The driver should return formats for the [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data. |
| DDVPFORMAT_VIDEO | The driver should return formats for the video data. |

### `lpddpfInputFormat`

Points to a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure that contains an input format supported by the VPE object. This format was returned by [DdVideoPortGetInputFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getinputformats).

### `lpddpfOutputFormats`

Points to an array of DDPIXELFORMAT structures in which the driver should return the output formats that the VPE object supports for the input format specified by **lpddpfInputFormat**. This member can be **NULL**.

### `dwNumFormats`

Specifies the location in which the driver should return the number of output formats that the VPE object supports for the specified input format.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortGetOutputFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getoutputformats) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetVideoPortInputFormats`

Unused: Win95 compatibility

## See also

[DdVideoPortGetOutputFormats](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getoutputformats)