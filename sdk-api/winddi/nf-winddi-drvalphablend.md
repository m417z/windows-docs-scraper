# DrvAlphaBlend function

## Description

The **DrvAlphaBlend** function provides bit-block transfer capabilities with [alpha blending](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `psoDest` [in, out]

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that identifies the surface on which to draw.

### `psoSrc` [in]

Pointer to a SURFOBJ structure that identifies the source surface.

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure. The CLIPOBJ_*Xxx* service routines are provided to enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles. This enumeration limits the area of the destination that is modified. Whenever possible, GDI simplifies the clipping involved. However, unlike [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt), **DrvAlphaBlend** might be called with a single rectangle in order to prevent round-off errors in clipping the output.

### `pxlo` [in, optional]

Pointer to an [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that specifies how color indices should be translated between the source and destination surfaces. If *pxlo* is **NULL**, no translation is needed.

If the source surface is palette-managed, its colors are represented by indices into a lookup table of RGB color values. In this case, the XLATEOBJ can be queried for a translate vector that allows the device driver to quickly translate any source index into a color index for the destination.

The situation is more complicated when, for example, the source is RGB but the destination is palette-managed. In this case, the closest match to each source RGB value must be found in the destination palette. The driver can call the [XLATEOBJ_iXlate](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_ixlate) service routine to perform this matching operation.

### `prclDest` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the rectangular area to be modified. This rectangle is specified in the coordinate system of the destination surface and is defined by two points: upper left and lower right. The two points that define the rectangle are always well ordered. The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the blend.

The driver should be careful to do proper clipping when writing the pixels because the specified rectangle might overhang the destination surface.

**DrvAlphaBlend** is never called with an empty destination rectangle.

### `prclSrc` [in]

Pointer to a RECTL structure that defines the area to be copied. This rectangle is specified in the coordinate system of the source surface, and is defined by two points: upper left and lower right. The two points that define the rectangle are always well ordered. The rectangle is lower-right exclusive; that is, its lower and right edges are not a part of the blend.

The source rectangle will never exceed the bounds of the source surface, and so will never overhang the source surface.

**DrvAlphaBlend** is never called with an empty source rectangle.

The mapping is defined by *prclSrc* and *prclDest*. The points specified in *prclDest* and *prclSrc* lie on integer coordinates, which correspond to pixel centers. A rectangle defined by two such points is considered to be a geometric rectangle with two vertices whose coordinates are the given points, but with 0.5 subtracted from each coordinate. (POINTL structures are shorthand notation for specifying these fractional coordinate vertices.)

### `pBlendObj` [in]

Pointer to a [BLENDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-blendobj) structure that describes the blending operation to perform between the source and destination surfaces. This structure is a wrapper for the BLENDFUNCTION structure, which includes necessary source and destination format information not available in the XLATEOBJ. The BLENDFUNCTION structure is defined in the Microsoft Windows SDK documentation. Its members are defined as follows:

**BlendOp** defines the blend operation to be performed. Currently this value must be AC_SRC_OVER, which means that the source bitmap is placed over the destination bitmap based on the alpha values of the source pixels. There are three possible cases that this blend operation should handle. These are described in the Remarks section.

**BlendFlags** is reserved and is currently set to zero.

**SourceConstantAlpha** defines the constant blend factor to apply to the entire source surface. This value is in the range of [0,255], where 0 is completely transparent and 255 is completely opaque.

**AlphaFormat** defines whether the surface is assumed to have an alpha channel. This member can optionally be set to the following value:

#### AC_SRC_ALPHA

The source surface can be assumed to be in a premultiplied alpha 32bpp "BGRA" format; that is, the surface type is BMF_32BPP and the palette type is BI_RGB. The alpha component is an integer in the range of [0,255], where 0 is completely transparent and 255 is completely opaque.

## Return value

**DrvAlphaBlend** returns **TRUE** upon success. Otherwise, it reports an error and returns **FALSE**.

## Remarks

The driver can support a bit-block transfer with alpha blending between the following surfaces:

* From one [device-managed surface](https://learn.microsoft.com/windows-hardware/drivers/) to another device-managed surface.
* From one GDI-managed standard format bitmap to another GDI-managed standard format bitmap.
* From one device-managed surface to a GDI-managed surface, and vice versa.

The driver can punt calls to [EngAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engalphablend).

The driver will never be called with overlapping source and destination rectangles on the same surface.

The three possible cases for the AC_SRC_OVER blend function are:

* The source bitmap has no per-pixel alpha (AC_SRC_ALPHA is not set), so the blend is applied to the pixel's color channels based on the constant source alpha value specified in SourceConstantAlpha as follows:

  ```
  Dst.Red = Round(((Src.Red * SourceConstantAlpha) +
      ((255 − SourceConstantAlpha) * Dst.Red)) / 255);
  Dst.Green = Round(((Src.Green * SourceConstantAlpha) +
      ((255 − SourceConstantAlpha) * Dst.Green)) / 255);
  Dst.Blue = Round(((Src.Blue * SourceConstantAlpha) +
      ((255 − SourceConstantAlpha) * Dst.Blue)) / 255);
  /* Do the next computation only if the destination bitmap
      has an alpha channel. */
  Dst.Alpha = Round(((Src.Alpha * SourceConstantAlpha) +
      ((255 − SourceConstantAlpha) * Dst.Alpha)) / 255);
  ```
* The source bitmap has per-pixel alpha values (AC_SRC_ALPHA is set), and **SourceConstantAlpha** is not used (it is set to 255). The blend is computed as follows:

  ```
  Dst.Red = Src.Red +
      Round(((255 − Src.Alpha) * Dst.Red) / 255);
  Dst.Green = Src.Green +
      Round(((255 − Src.Alpha) * Dst.Green) / 255);
  Dst.Blue = Src.Blue +
      Round(((255 − Src.Alpha) * Dst.Blue) / 255);
  /* Do the next computation only if the destination bitmap
      has an alpha channel. */
  Dst.Alpha = Src.Alpha +
      Round(((255 − Src.Alpha) * Dst.Alpha) / 255);
  ```
* The source bitmap has per-pixel alpha values (AC_SRC_ALPHA is set), and **SourceConstantAlpha** is used (it is not set to 255). The blend is computed as follows:

  ```
  Temp.Red = Round((Src.Red * SourceConstantAlpha) / 255);
  Temp.Green = Round((Src.Green * SourceConstantAlpha) / 255);
  Temp.Blue = Round((Src.Blue * SourceConstantAlpha) / 255);
  /* The next computation must be done even if the
      destination bitmap does not have an alpha channel. */
  Temp.Alpha = Round((Src.Alpha * SourceConstantAlpha) / 255);

  /* Note that the following equations use the just-computed
     Temp.Alpha value: */
  Dst.Red = Temp.Red +
      Round(((255 − Temp.Alpha) * Dst.Red) / 255);
  Dst.Green = Temp.Green +
      Round(((255 − Temp.Alpha) * Dst.Green) / 255);
  Dst.Blue = Temp.Blue +
      Round(((255 − Temp.Alpha) * Dst.Blue) / 255);
  /* Do the next computation only if the destination bitmap
      has an alpha channel.  */
  Dst.Alpha = Temp.Alpha +
      Round(((255 − Temp.Alpha) * Dst.Alpha) / 255);
  ```

The **Round(x)** function rounds to the nearest integer, computed as:

```
Trunc(x + 0.5);
```

**DrvAlphaBlend** can be optionally implemented in graphics drivers. It can be provided to handle some kinds of alpha blends, such as blends where the source and destination surfaces are the same format and do not contain an alpha channel.

A hardware implementation can use floating point or fixed point in the blend operation. Compatibility tests will account for some numerical error in the results; please see [Special Effects in Display Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/special-effects-in-display-drivers) for information about maximum permissible error. When using fixed point, an acceptable approximation to the term *x/255* is *(x*257)/65536*. Incorporating rounding, the expression:

```
((255 - Src.Alpha) * Dst.Red) / 255
```

can then be approximated as:

```
temp = ((255 - Src.Alpha) * Dst.Red) + 128;
result = (temp + (temp >> 8)) >> 8;
```

The driver hooks **DrvAlphaBlend** by setting the HOOK_ALPHABLEND flag when it calls [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface). If the driver has hooked **DrvAlphaBlend** and is called to perform an operation that it does not support, the driver should have GDI handle the operation by punting the data in a call to [EngAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engalphablend).

## See also

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[DrvPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvplgblt)

[DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt)

[DrvStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchbltrop)

[DrvTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtransparentblt)

[EngAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engalphablend)

[EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt)

[EngPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engplgblt)

[EngStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchblt)

[EngStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engstretchbltrop)

[EngTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engtransparentblt)