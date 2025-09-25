# DrvSetPointerShape function

## Description

The **DrvSetPointerShape** function is used to request the driver to take the pointer off the display, if the driver has drawn it there; to attempt to set a new pointer shape; and to put the new pointer on the display at a specified position.

## Parameters

### `pso` [in]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `psoMask` [in]

Pointer to the SURFOBJ structure that defines the AND-XOR mask. (The AND-XOR mask is described in [Drawing Monochrome Pointers](https://learn.microsoft.com/windows-hardware/drivers/display/drawing-monochrome-pointers).) The dimensions of this bitmap determine the size of the pointer. There are no implicit constraints on pointer sizes, but optimal pointer sizes are 32 x 32, 48 x 48, and 64 x 64 pixels. If this parameter is **NULL**, the pointer is transparent.

### `psoColor` [in]

Pointer to the SURFOBJ structure that defines the colors for a color pointer. If this parameter is **NULL**, the pointer is monochrome. The pointer bitmap has the same width as *psoMask* and half the height.

### `pxlo` [in]

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that defines the colors in *psoColor*.

### `xHot` [in]

Specify the *x* position of the pointer's hot spot relative to its upper-left pixel. The pixel indicated by the hot spot should be positioned at the new pointer position.

### `yHot` [in]

Specify the *y* position of the pointer's hot spot relative to its upper-left pixel. The pixel indicated by the hot spot should be positioned at the new pointer position.

### `x` [in]

Specify the x-coordinate of the new pointer position.

### `y` [in]

Specify the y-coordinate of the new pointer position.

### `prcl` [in]

Specifies the [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that indicates the location in which the driver should write a rectangle that specifies a tight bound for the visible portion of the pointer.

### `fl` [in]

Specifies an extensible set of flags. The driver should decline the call if any flags are set that it does not understand. This parameter can be one or more of the following predefined values, and one or more driver-defined values:

| Flag | Meaning |
| --- | --- |
| SPS_ALPHA | The pointer has per-pixel alpha values. |
| SPS_ANIMATESTART | The driver should be prepared to receive a series of similarly-sized pointer shapes that will comprise an animated pointer effect. |
| SPS_ANIMATEUPDATE | The driver should draw the next pointer shape in the animated series. |
| SPS_ASYNCCHANGE | This flag is obsolete. For legacy drivers, the driver should accept the change only if it is capable of changing the pointer shape in the hardware while other drawing is underway on the device. GDI uses this option only if the now obsolete GCAPS_ASYNCCHANGE flag is set in the **flGraphicsCaps** member of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure. |
| SPS_CHANGE | The driver is requested to change the pointer shape. |
| SPS_FREQMASK | The driver is requested to render a mouse trail, updating the image as many times per millisecond as indicated in the expression *fl* & SPS_FREQMASK. A driver that is capable of rendering mouse trails must have the GCAPS2_MOUSETRAILS flag set in the **flGraphicsCaps2** member of its [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure. |
| SPS_LENGTHMASK | The driver is requested to render a mouse trail of length indicated by the expression *fl* & SPS_LENGTHMASK. (A mouse trail of length *N* is made up of *N* + 1 cursor images.) A driver that is capable of rendering mouse trails must have the GCAPS2_MOUSETRAILS flag set in the **flGraphicsCaps2** member of its [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure. |

## Return value

The return value can be one of the following values:

| Return code | Description |
| --- | --- |
| **SPS_ACCEPT_EXCLUDE** | Is obsolete. GDI will disable the driver's pointer and revert to software simulation if the driver returns this value. |
| **SPS_ACCEPT_NOEXCLUDE** | The driver accepts the shape. The shape is supported in hardware and GDI is not concerned about other drawings overwriting the pointer. |
| **SPS_DECLINE** | The driver does not support the shape, so GDI must simulate it. |
| **SPS_ERROR** | The driver normally supports this shape, but failed for unusual reasons. |

## Remarks

**DrvSetPointerShape** is optional for display drivers. If this function is implemented, however, [DrvMovePointer](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvmovepointer) must also be implemented.

The **iUniq** members of the SURFOBJ structures to which *psoMask* and *psoColor* point are unique for unique pointers. The driver can use this information in conjunction with these structures' unique **dhsurf** handles as cache keys for cursor caching.

When SPS_ALPHA is set in the *fl* parameter, *psoMask* is **NULL** and *psoColor* points to a 32bpp BGRA surface. The per-pixel alpha value indicates the opacity of the corresponding pointer pixel with the desktop pixel underneath. The source alpha format is premultiplied; that is, each of the color channels of the source surface has already been premultiplied with the corresponding alpha value, thus eliminating a multiply operation at the time of the blend.

Default alpha cursors are largely black and white with a large range of alpha values; however, there is no color restriction since applications can specify arbitrary cursors themselves. Typical alpha pointer sizes are approximately 8 pixels larger in dimension than typical pointers without alpha. This accommodates the shadow effect, which is accomplished by a blurring filter that expands the resulting pointer bitmap shape. The vast majority of pointers will be 64x64 pixel bitmaps or smaller.

The driver indicates its ability to handle pointers with per-pixel alpha values by setting the GCAPS2_ALPHACURSOR flag in the **flGraphicsCaps2** member of the [DEVINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-devinfo) structure returned by [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[DrvMovePointer](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvmovepointer)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)