# DD_GETVPORTBANDWIDTHDATA structure

## Description

The DD_GETVPORTBANDWIDTHDATA structure contains the bandwidth information for any specified format.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

### `lpddpfFormat`

Points to a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure that describes the output pixel format for which the driver should return bandwidth information.

### `dwWidth`

### `dwHeight`

Specify the dimensions of the source overlay or of the video data in pixels depending on the value of **dwFlags**. These values are calculated by the client based on the VPE object's capabilities returned in a prior call to [DdVideoPortGetBandwidth](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getbandwidth).

### `dwFlags`

Specifies the flags indicating how the driver should interpret the **dwWidth** and **dwHeight** members. This member can be one of the values listed in the following table.

| Flag | Meaning |
| --- | --- |
| DDVPB_OVERLAY | The **dwWidth** and **dwHeight** members specify the size in pixels of the source overlay surface. This flag indicates that the VPE object is dependent on the overlay source size. |
| DDVPB_TYPE | The **dwWidth** and **dwHeight** members are not set. |
| DDVPB_VIDEOPORT | The **dwWidth** and **dwHeight** members specify the prescale size of the video data that the VPE object writes to the frame buffer. This flag indicates that the VPE object is dependent on the overlay stretch factor. |

### `lpBandwidth`

Points to the [DDVIDEOPORTBANDWIDTH](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportbandwidth) structure in which the driver should write the bandwidth parameters.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortGetBandwidth](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getbandwidth) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetVideoPortBandwidth`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DDVIDEOPORTBANDWIDTH](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportbandwidth)

[DdVideoPortGetBandwidth](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_getbandwidth)