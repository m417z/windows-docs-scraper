# DDVIDEOPORTDATA structure

## Description

The DDVIDEOPORTDATA structure is used by DirectDraw to represent a [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object to the kernel-mode video miniport driver.

## Members

### `dwVideoPortId`

Specifies the ID of this hardware video port, an integer in the range (0 - (maximum number of hardware video ports - 1)).

### `dwVPFlags`

Indicates a set of flags that specify the current user mode DDVP_*Xxx* flags set by [DdVideoPortUpdate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_update). This member can be a bitwise OR of any of the following flags:

| Flag | Meaning |
| --- | --- |
| DDVP_AUTOFLIP | Perform automatic flipping. Autoflipping is performed between the overlay surface that was attached to the hardware video port using the application's **AttachSurface** method, and the overlay surfaces that are attached to the surface using the application's **AttachSurface** method. The flip order is the order in which the overlay surfaces were attached. |
| DDVP_CONVERT | Perform the conversion using the target surface format. |
| DDVP_CROP | Perform cropping using the specified rectangle. |
| DDVP_HARDWAREDEINTERLACE | The hardware video port should use the deinterlacing hardware. |
| DDVP_IGNOREVBIXCROP | The video data should ignore the left and right cropping coordinates when cropping the [vertical blanking interval (VBI)](https://learn.microsoft.com/windows-hardware/drivers/) data. |
| DDVP_INTERLEAVE | Interlaced fields should be interleaved in memory. |
| DDVP_MIRRORLEFTRIGHT | The data should be mirrored left to right as it is written into the frame buffer. |
| DDVP_MIRRORUPDOWN | The data should be mirrored top to bottom as it is written into the frame buffer. |
| DDVP_OVERRIDEBOBWEAVE | These bob and weave decisions should not be overridden by other interfaces. If this flag is set, DirectDraw does not allow a kernel-mode driver to use the kernel-mode video transport functionality to switch the hardware between bob and weave modes. |
| DDVP_PRESCALE | Perform prescaling/zooming based on the prescale parameters. |
| DDVP_SKIPEVENFIELDS | Ignore input of even fields. |
| DDVP_SKIPODDFIELDS | Ignore input of odd fields. |
| DDVP_SYNCMASTER | Drive the graphics V-syncs using the hardware video port V-syncs. |
| DDVP_VBICONVERT | The **lpddpfVBIOutputFormat** member contains data that should be used to convert the data within the vertical blanking interval. |
| DDVP_VBINOINTERLEAVE | Interleaving can be disabled for data within the vertical blanking interval. |
| DDVP_VBINOSCALE | Data within the vertical blanking interval should not be scaled. |

### `dwOriginOffset`

Specifies the byte offset of the VPE object relative to the start of the surface. This value is used only by the miniport driver.

### `dwHeight`

Specifies the height in pixels of the VPE object data. This value is used only by the miniport driver.

### `dwVBIHeight`

Specifies the height in scan lines of the VBI data. This value is used only by the miniport driver.

### `dwDriverReserved1`

Reserved for use by the miniport driver.

### `dwDriverReserved2`

Reserved for use by the miniport driver.

### `dwDriverReserved3`

Reserved for use by the miniport driver.

## See also

[DdVideoPortUpdate](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_update)