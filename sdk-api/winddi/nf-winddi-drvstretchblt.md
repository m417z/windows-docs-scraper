# DrvStretchBlt function

## Description

The **DrvStretchBlt** function provides stretching bit-block transfer capabilities between any combination of device-managed and GDI-managed surfaces.

## Parameters

### `psoDest` [in, out]

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the surface on which to draw.

### `psoSrc` [in, out]

Pointer to the SURFOBJ structure that defines the source for the bit-block transfer operation.

### `psoMask` [in, optional]

Optional pointer to a SURFOBJ structure that defines a surface that provides a mask for the source. The mask is defined by a logic map, which is a bitmap with 1 bit per pixel.

The mask limits the area of the source that is copied. If this parameter is specified, it has an implicit *rop4* of 0xCCAA, meaning the source should be copied wherever the mask is one, but the destination should be left alone wherever the mask is zero.

When this parameter is **NULL**, there is an implicit *rop4* of 0xCCCC, which means that the source should be copied everywhere in the source rectangle.

The mask will always be large enough to contain the relevant source; tiling is unnecessary.

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that limits the area to be modified in the destination. GDI services are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles.

Whenever possible, GDI simplifies the clipping involved. However, unlike [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt), **DrvStretchBlt** can be called with a single clipping rectangle. This prevents rounding errors in clipping the output.

### `pxlo` [in, optional]

Pointer to a [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that specifies how color indices are to be translated between the source and target surfaces. If *pxlo* is **NULL**, no translation is needed.

The XLATEOBJ structure can also be queried to find the RGB color for any source index. A high quality stretching bit-block transfer will need to interpolate colors in some cases.

### `pca` [in, optional]

Pointer to a COLORADJUSTMENT structure that defines the color adjustment values to be applied to the source bitmap before stretching the bits. (See the Microsoft Windows SDK documentation.)

### `pptlHTOrg` [in]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that specifies the origin of the halftone brush. Device drivers that use halftone brushes should align the upper left pixel of the brush's pattern with this point on the device surface.

### `prclDest` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the area to be modified in the coordinate system of the destination surface. This rectangle is defined by two points that are not necessarily well ordered, meaning the coordinates of the second point are not necessarily larger than those of the first point. The rectangle they describe does not include the lower and right edges. This function is never called with an empty destination rectangle.

**DrvStretchBlt** should interchange the two *x* values and/or the two *y* values when the destination rectangle is not well ordered.

### `prclSrc` [in]

Pointer to a RECTL structure that defines the area that will be copied in the coordinate system of the source surface. The rectangle is defined by two points, and will map onto the rectangle defined by *prclDest*. The points of the source rectangle are well ordered. This function is never given an empty source rectangle.

The mapping is defined by *prclSrc* and *prclDest*. The points specified in *prclDest* and *prclSrc* lie on integer coordinates, which correspond to pixel centers. A rectangle defined by two such points is considered to be a geometric rectangle with two vertices whose coordinates are the given points, but with 0.5 subtracted from each coordinate. (POINTL structures should be considered a shorthand notation for specifying these fractional coordinate vertices.)

The edges of any rectangle never intersect a pixel, but go around a set of pixels. The pixels inside the rectangle are those expected for a "lower-right exclusive" rectangle. **DrvStretchBlt** will map the geometric source rectangle exactly onto the geometric destination rectangle.

### `pptlMask` [in, optional]

Pointer to a POINTL structure that specifies which pixel in the given mask corresponds to the upper left pixel in the source rectangle. Ignore this parameter if no mask is specified.

### `iMode` [in]

Specifies how source pixels are combined to get output pixels. The HALFTONE mode is slower than the other modes, but produces higher quality images.

| Value | Meaning |
| --- | --- |
| BLACKONWHITE | On a shrinking bit-block transfer, pixels should be combined with a Boolean AND operation. On a stretching bit-block transfer, pixels should be replicated. |
| COLORONCOLOR | On a shrinking bit-block transfer, enough pixels should be ignored so that pixels don't need to be combined. On a stretching bit-block transfer, pixels should be replicated. |
| HALFTONE | The driver can use groups of pixels in the output surface to best approximate the color or gray level of the input. |
| WHITEONBLACK | On a shrinking bit-block transfer, pixels should be combined with a Boolean OR operation. On a stretching bit-block transfer, pixels should be replicated. |

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE**, and an error code is logged.

## Remarks

**DrvStretchBlt** enables the device driver to write to GDI bitmaps, especially when the driver can perform halftoning. This function allows the same halftoning algorithm to be applied to GDI bitmaps and device surfaces.

This function can be provided to handle only certain forms of stretching, such as by integer multiples. If the driver has hooked the call and is asked to perform an operation it does not support, the driver should forward the data to [EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt) for GDI to handle.

If the driver wants GDI to handle halftoning, and wants to ensure the proper *iMode* value, the driver can hook **DrvStretchBlt**, set *iMode* to HALFTONE, and call back to GDI with [EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt) with the set *iMode* value.

**DrvStretchBlt** is optional for display drivers.

## See also

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)