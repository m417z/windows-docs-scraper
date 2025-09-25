# DDVIDEOPORTINFO structure

## Description

The DDVIDEOPORTINFO structure describes how the driver should transfer video data to a surface (or to surfaces); DDVIDEOPORTINFO is a member of the [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure.

## Members

### `dwSize`

Specifies the size in bytes of the structure. This member must be initialized before the structure is used.

### `dwOriginX`

Indicates the x placement of the video data within the surface, in pixels. This offset applies to all surfaces when autoflipping is requested.

### `dwOriginY`

Indicates the y placement of the video data within the surface, in pixels. This offset applies to all surfaces when autoflipping is requested.

### `dwVPFlags`

Indicates a set of flags that specify how the driver should transfer the video data. This member can be a bitwise OR of the following values:

| Flag | Meaning |
| --- | --- |
| DDVP_AUTOFLIP | Perform automatic flipping. Auto-flipping is performed between the overlay surface that was attached to the hardware video port and the overlay surfaces that are attached to the surface. The flip order is the order in which the overlay surfaces were attached. |
| DDVP_CONVERT | The video data and target surface have different formats. The driver should convert the video data to the format of the target surface format. |
| DDVP_CROP | The driver should crop both the video and [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data using the rectangle in the **rCrop** member. |
| DDVP_IGNOREVBIXCROP | The driver should ignore the left and right cropping coordinates when cropping the VBI data. |
| DDVP_INTERLEAVE | Interlaced fields of both video and VBI data should be interleaved in memory. |
| DDVP_MIRRORLEFTRIGHT | Video data should be mirrored left to right as it is written into the frame buffer. |
| DDVP_MIRRORUPDOWN | Video data should be mirrored top to bottom as it is written into the frame buffer. |
| DDVP_NOINTERLEAVE | If the DDVP_INTERLEAVE flag is set, the driver should interleave the video data only; that is, the driver should not interleave the VBI data. |
| DDVP_OVERRIDEBOBWEAVE | The bob and weave decisions should not be overridden by other interfaces. If this flag is set, Microsoft DirectDraw does not allow a kernel-mode driver to use the kernel-mode video transport functionality to switch the hardware between bob and weave modes. |
| DDVP_PRESCALE | Perform prescaling/zooming based on the **dwPrescaleWidth** and **dwPrescaleHeight** members. The driver should prescale only the video data if DDVP_VBINOSCALE is set; otherwise, it should prescale both the video and VBI data. |
| DDVP_SKIPEVENFIELDS | Ignore input of even fields for both video and VBI data. |
| DDVP_SKIPODDFIELDS | Ignore input of odd fields for both video and VBI data. |
| DDVP_SYNCMASTER | Drive the graphics VSYNCs using the hardware video port VSYNCs. |
| DDVP_VBICONVERT | The [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure to which the **lpddpfVBIOutputFormat** member points contains data that should be used to convert the data within the vertical blanking interval. |
| DDVP_VBINOSCALE | Data within the vertical blanking interval should not be scaled. |

### `rCrop`

Specifies a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies a cropping rectangle in pixels. This member contains a valid rectangle when the DDVP_CROP flag is set in the **dwVPFlags** member.

### `dwPrescaleWidth`

Specifies the width in pixels to which the video and VBI data should be prescaled or zoomed. For example, if the video data is 720 pixels wide and the client requests the width cut in half, the client specifies 360 in **dwPrescaleWidth**. This member contains a valid width when the DDVP_PRESCALE flag is set in the **dwVPFlags** member.

### `dwPrescaleHeight`

Specifies the height in pixels to which the video and VBI data should be prescaled or zoomed. For example, if the video data is 240 pixels wide and the client requests the width cut in half, the client specifies 120 in **dwPrescaleHeight**. This member contains a valid width when the DDVP_PRESCALE flag is set in the **dwVPFlags** member.

### `lpddpfInputFormat`

Points to a [DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat) structure that specifies the format of the video data to be written to the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object. This format can be different from the target surface format if the VPE object performs a conversion.

### `lpddpfVBIInputFormat`

Points to a DDPIXELFORMAT structure that specifies the input format of the data within the vertical blanking interval.

### `lpddpfVBIOutputFormat`

Points to a DDPIXELFORMAT structure that specifies the output format of the data within the vertical blanking interval.

### `dwVBIHeight`

Specifies the number of lines of data within the vertical blanking interval.

### `dwReserved1`

Reserved for system use and should be ignored by the driver.

### `dwReserved2`

Reserved for system use and should be ignored by the driver.

## Remarks

All members of this structure are set by the client and the driver should never change them. The client is typically the overlay mixer.

## See also

[DDPIXELFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-_ddpixelformat)

[DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local)