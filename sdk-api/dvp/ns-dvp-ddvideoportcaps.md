# DDVIDEOPORTCAPS structure

## Description

The DDVIDEOPORTCAPS structure describes the capabilities and alignment restrictions of a hardware video port.

## Members

### `dwSize`

Specifies the size in bytes of the structure.

### `dwFlags`

Specify what members in this structure contain valid data. This member can be a bitwise OR of any of the following values:

| Flag | Meaning |
| --- | --- |
| DDVPD_ALIGN | All of the alignment members are valid. These include:<br><br>**dwAlignVideoPortBoundary**,<br><br>**dwAlignVideoPortPrescaleWidth**,<br><br>**dwAlignVideoPortCropBoundary**, and<br><br>**dwAlignVideoPortCropWidth**. |
| DDVPD_AUTOFLIP | The **dwNumAutoFlipSurfaces** is valid. |
| DDVPD_CAPS | The **dwCaps** member is valid. |
| DDVPD_FX | The **dwFX** member is valid. |
| DDVPD_HEIGHT | The **dwMaxHeight** member is valid. |
| DDVPD_ID | The **dwVideoPortID** member is valid. |
| DDVPD_WIDTH | The **dwMaxWidth** and **dwMaxVBIWidth** members are valid. |

### `dwMaxWidth`

Specifies the maximum field width in pixels supported by the hardware video port. This value is typically dictated by the number of bits in the width register.

### `dwMaxVBIWidth`

Specifies the maximum width, in number of samples, in a line of [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data supported by the hardware video port. This value can be larger than the normal field width if the hardware video port supports oversampled VBI data.

### `dwMaxHeight`

Specifies the maximum field height in pixels supported by the hardware video port. This value is typically dictated by the number of bits in the height register.

### `dwVideoPortID`

Specifies the hardware video port ID for this entry. This member should be the index number of this DDVIDEOPORTCAPS structure within the array to which the **lpDDVideoPortCaps** member of the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure points. This value ranges from 0 to (**dwMaxVideoPorts** - 1). (**dwMaxVideoPorts** is a member of the [DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps) structure.) If the device supports only one hardware video port, this member should be zero.

### `dwCaps`

Indicates a set of flags that specify the capabilities supported by this hardware video port. This member can be a bitwise OR of any of the following values:

| Flag | Meaning |
| --- | --- |
| DDVPCAPS_AUTOFLIP | A flip can be performed automatically to avoid tearing. |
| DDVPCAPS_COLORCONTROL | The hardware video port can perform color operations on the incoming data before it is written to the frame buffer. |
| DDVPCAPS_INTERLACED | The hardware video port supports interlaced video. |
| DDVPCAPS_NONINTERLACED | The hardware video port supports noninterlaced video. |
| DDVPCAPS_OVERSAMPLEDVBI | The hardware video port can accept VBI data in a different width or format than the regular video data. |
| DDVPCAPS_READBACKFIELD | The device can return a value signifying whether the current field of an interlaced signal is even or odd. |
| DDVPCAPS_READBACKLINE | The device can return the number of the current line of video being written into the frame buffer. |
| DDVPCAPS_SHAREABLE | Ignored by Microsoft DirectDraw. |
| DDVPCAPS_SKIPEVENFIELDS | The hardware video port can automatically discard even fields of video. |
| DDVPCAPS_SKIPODDFIELDS | The hardware video port can automatically discard odd fields of video. |
| DDVPCAPS_SYNCMASTER | The device is capable of driving the graphics V-sync with the hardware video port driver V-sync. |
| DDVPCAPS_SYSTEMMEMORY | The hardware video port can write data directly to system memory. |
| DDVPCAPS_VBISURFACE | The data within the vertical blanking interval can be written to a different surface. |

### `dwFX`

Indicates a set of flags that specify the effects supported by this hardware video port. This member is a bitwise OR of any of the following values:

| Flag | Meaning |
| --- | --- |
| DDVPFX_CROPTOPDATA | The hardware video port supports limited cropping to crop out the vertical interval data. |
| DDVPFX_CROPX | The hardware video port can crop incoming data in the x direction before writing it to the surface. |
| DDVPFX_CROPY | The hardware video port can crop incoming data in the y direction before writing it to the surface. |
| DDVPFX_IGNOREVBIXCROP | The hardware video port can ignore the left and right cropping coordinates for video data when cropping oversampled VBI data. |
| DDVPFX_INTERLEAVE | The hardware video port supports interleaving interlaced fields in memory. |
| DDVPFX_MIRRORLEFTRIGHT | The hardware video port supports mirroring left to right as the video data is written into the frame buffer. |
| DDVPFX_MIRRORUPDOWN | The hardware video port supports mirroring top to bottom as the video data is written into the frame buffer. |
| DDVPFX_PRESHRINKX | Data can be arbitrarily shrunk in the x direction before it is written to the surface. |
| DDVPFX_PRESHRINKXB | Data can be shrunk by negative powers of 2 (1/2, 1/4, 1/8, and so on) in the x direction before it is written to the surface. |
| DDVPFX_PRESHRINKXS | Data can be shrunk in increments of 1/**dwPreshrinkXStep** in the x direction before it is written to the surface. |
| DDVPFX_PRESHRINKY | Data can be arbitrarily shrunk in the y direction before it is written to the surface. |
| DDVPFX_PRESHRINKYB | Data can be shrunk by negative powers of 2 (1/2, 1/4, 1/8, and so on) in the y direction before it is written to the surface. |
| DDVPFX_PRESHRINKYS | Data can be shrunk in increments of 1/**dwPreshrinkYStep** in the y direction before it is written to the surface. |
| DDVPFX_PRESTRETCHX | Data can be arbitrarily stretched in the x direction before it is written to the surface. |
| DDVPFX_PRESTRETCHXN | Data can be stretched by integer factors in the x direction before it is written to the surface. |
| DDVPFX_PRESTRETCHY | Data can be arbitrarily stretched in the y direction before it is written to the surface. |
| DDVPFX_PRESTRETCHYN | Data can be stretched by integer factors in the y direction before it is written to the surface. |
| DDVPFX_VBICONVERT | Data within the vertical blanking interval can be converted independent of the remaining video data. |
| DDVPFX_VBINOSCALE | Scaling can be disabled for data within the vertical blanking interval. |

### `dwNumAutoFlipSurfaces`

Specifies the maximum number of surfaces supported in the autoflip chain, if the hardware video port supports autoflipping. If the hardware video port does not support autoflipping, the driver should set this member to zero.

### `dwAlignVideoPortBoundary`

Specifies the byte alignment restriction, in bytes, of where the hardware video port can be oriented relative to the origin of the surface in the x direction.

### `dwAlignVideoPortPrescaleWidth`

Specifies the byte alignment restriction, in bytes, of how wide the hardware video port data can be when prescaling is performed.

### `dwAlignVideoPortCropBoundary`

Specifies the byte alignment restriction, in bytes, for the left cropping coordinate.

### `dwAlignVideoPortCropWidth`

Specifies the byte alignment restriction, in bytes, for the width of the cropping rectangle.

### `dwPreshrinkXStep`

Indicates that the hardware video port can shrink the video data width in steps of 1/**dwPreshrinkXStep**. This member is valid only when the DDVPFX_PRESHRINKXS capability is specified.

### `dwPreshrinkYStep`

Indicates that the hardware video port can shrink the video data height in steps of 1/**dwPreshrinkYStep**. This member is valid only when the DDVPFX_PRESHRINKYS capability is specified.

### `dwNumVBIAutoFlipSurfaces`

Specifies the maximum number of surfaces supported in the autoflip chain, if the hardware video port supports autoflipping. If the hardware video port does not support autoflipping, the driver should set this member to zero. This member works the same way as **dwNumAutoFlipSurfaces** except that it pertains only to devices that can send the VBI data to a different surface than that to which the normal video is being written.

### `dwNumPreferredAutoflip`

Specifies the optimal number of autoflippable surfaces supported by the hardware.

### `wNumFilterTapsX`

Indicates the number of taps the prescaler uses in the x direction. A value of 0 indicates no prescale, a value of 1 indicates replication, and so on.

### `wNumFilterTapsY`

Indicates the number of taps the prescaler uses in the y direction. A value of 0 indicates no prescale, a value of 1 indicates replication, and so on.

## Remarks

The driver reports the capabilities described by the DDVIDEOPORTCAPS structure when its [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function is called with the GUID_VideoPortCaps GUID.

## See also

[DDCORECAPS](https://learn.microsoft.com/windows/desktop/api/ddrawi/ns-ddrawi-ddcorecaps)

[DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)