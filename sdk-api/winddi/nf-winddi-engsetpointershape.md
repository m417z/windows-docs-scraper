# EngSetPointerShape function

## Description

The **EngSetPointerShape** function sets the pointer shape for the calling driver.

## Parameters

### `pso` [in]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `psoMask` [in]

Pointer to a SURFOBJ structure that defines the AND-XOR mask to apply to the pointer bitmap. The top half of the bitmap specifies the monochrome AND mask and the bottom half specifies the monochrome XOR mask. The pointer is the same width and half the height of the mask to which *psoMask* points. There are no implicit constraints on pointer sizes, but optimal pointer sizes are 32 x 32, 48 x 48, and 64 x 64 pixels. If this parameter is **NULL**, the pointer is transparent.

### `psoColor` [in]

Pointer to a SURFOBJ structure that defines the colors for a color pointer. This bitmap is the same width and half the height of the bitmap to which *psoMask* points, and is in the same color format as the surface to which *pso* points. If this parameter is **NULL**, the pointer is monochrome.

### `pxlo` [in]

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that defines the colors in *psoColor*.

### `xHot` [in]

Specifies the x coordinate of the pointer's hot spot relative to its upper-left pixel. The pixel indicated by the hot spot should be positioned at the new pointer position.

### `yHot` [in]

Specifies the y coordinate of the pointer's hot spot relative to its upper-left pixel. The pixel indicated by the hot spot should be positioned at the new pointer position.

### `x` [in]

Specifies the x coordinates of the new pointer position.

### `y` [in]

Specifies the y coordinates of the new pointer position.

### `prcl` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure. If non-**NULL**, the driver has provided a rectangle that bounds all pixels affected by the pointer on the display. GDI avoids drawing on this rectangle without first moving the pointer out of the way.

### `fl` [in]

Specifies a set of flags that GDI should use to process this call. This parameter can be one or more of the following predefined values:

| Flag | Meaning |
| --- | --- |
| SPS_ANIMATESTART | GDI should be prepared to receive a series of similarly-sized pointer shapes that will comprise an animated pointer effect. |
| SPS_ANIMATEUPDATE | GDI should draw the next pointer shape in the animated series. |
| SPS_CHANGE | GDI is requested to change the pointer shape. |

## Return value

**EngSetPointerShape** returns one of the following values:

| Return code | Description |
| --- | --- |
| **SPS_ACCEPT_EXCLUDE** | GDI accepts the shape. GDI does not read from or write to the rectangle written at *prcl* without first moving the pointer out of the way. |
| **SPS_ERROR** | GDI normally supports this shape, but failed for unusual reasons. |

## Remarks

The driver can call **EngSetPointerShape** to have GDI manage a software cursor.

There are two parts to the monochrome bitmap to which *psoMask* points. The first part defines the AND mask for the pointer while the second part defines the XOR mask. Taken together, these masks provide two bits of information for each pixel of the pointer image. The following truth table determines what GDI draws on the display for different values in the AND and XOR masks:

| AND value | XOR value | Resultant Pixel |
| --- | --- | --- |
| 0 | 0 | White |
| 0 | 1 | Black |
| 1 | 0 | No change in pixel |
| 1 | 1 | Pixel color is inverted |

This mechanism supplies a black and white image while allowing for transparency and inversion of the pixels that make up the pointer.

## See also

[DrvSetPointerShape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpointershape)

[EngMovePointer](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmovepointer)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)