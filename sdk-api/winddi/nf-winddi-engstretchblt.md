# EngStretchBlt function

## Description

The **EngStretchBlt** function causes GDI to do a stretching bit-block transfer.

## Parameters

### `psoDest`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `psoSrc`

Pointer to a SURFOBJ structure that describes the source surface for the bit-block transfer.

### `psoMask`

Pointer to a SURFOBJ structure that defines a mask for the source. The mask is defined by a logic map, which is a bitmap with one bit per pixel.

The mask limits the area of the source that is copied. If this parameter is specified, it has an implicit *rop4* of 0xCCAA, meaning the source should be copied wherever the mask is 1, but the destination should be left alone wherever the mask is 0.

If this parameter is **NULL**, the *rop4* is implicitly 0xCCCC, which means the source should be copied everywhere in the source rectangle.

### `pco`

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that limits the area to be modified in the destination. GDI services are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

Whenever possible, GDI simplifies the clipping involved. However, unlike [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt), **EngStretchBlt** can be called with a single clipping rectangle. This prevents rounding errors in clipping the output.

### `pxlo`

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that specifies how color indices are to be translated between the source and target surfaces.

This XLATEOBJ structure can also be queried to find the RGB color for any source index. A high quality stretching bit-block transfer will need to interpolate colors in some cases.

### `pca` [in]

Pointer to a COLORADJUSTMENT structure that defines the color adjustment values to be applied to the source bitmap before stretching the bits. For more information, see the Microsoft Windows SDK documentation.

### `pptlHTOrg` [in]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the origin of the halftone brush. Drivers that use halftone brushes should align the upper left pixel of the brush's pattern with this point on the device surface.

### `prclDest` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the area to be modified in the coordinate system of the destination surface. This rectangle is defined by two points that are not well ordered, meaning the coordinates of the second point are not necessarily larger than those of the first point. The rectangle described does not include the lower and right edges. This function is never called with an empty destination rectangle.

If the destination rectangle is not well ordered, **EngStretchBlt** makes it well ordered.

### `prclSrc` [in]

Pointer to a RECTL structure that defines the area to be copied, in the coordinate system of the source surface. The rectangle will map to the rectangle defined by *prclDest*. This function is never given an empty source rectangle, and the points of the source rectangle are always well-ordered.

The mapping is defined by *prclSrc* and *prclDest*. The points specified in *prclDest* and *prclSrc* lie on integer coordinates, which correspond to pixel centers. A rectangle defined by two such points is considered to be a geometric rectangle with two vertices whose coordinates are the given points, but with 0.5 subtracted from each coordinate. (POINTL structures are shorthand notation for specifying these fractional coordinate vertices.)

The edges of any rectangle never intersect a pixel, but go around a set of pixels. The pixels that are inside the rectangle are those expected for a lower-right exclusive rectangle. **EngStretchBlt** maps the geometric source rectangle exactly onto the geometric destination rectangle.

### `pptlMask`

Pointer to a POINTL structure that defines the pixel in the given mask that corresponds to the upper left pixel in the source rectangle. This parameter is ignored if no mask is specified.

### `iMode` [in]

Specifies how source pixels are combined to get output pixels. The HALFTONE mode is slower than the other modes, but produces higher quality images.

| Value | Meaning |
| --- | --- |
| BLACKONWHITE | On a shrinking bit-block transfer, pixels should be combined with a Boolean AND operation. On a stretching bit-block transfer, pixels should be replicated. |
| COLORONCOLOR | On a shrinking bit-block transfer, enough pixels should be ignored so that pixels don't need to be combined. On a stretching bit-block transfer, pixels should be replicated. |
| HALFTONE | The driver can use groups of pixels in the output surface to best approximate the color or gray level of the input. |
| WHITEONBLACK | On a shrinking bit-block transfer, pixels should be combined with a Boolean OR operation. On a stretching bit-block transfer, pixels should be replicated. |

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE** and an error code is reported.

## Remarks

This function allows the same halftoning algorithm to be applied to GDI bitmaps and device surfaces.

The driver should call **EngStretchBlt** if it has hooked [DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt) and is called to do something the driver does not support.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)