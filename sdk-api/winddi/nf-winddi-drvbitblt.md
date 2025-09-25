# DrvBitBlt function

## Description

The **DrvBitBlt** function provides general bit-block transfer capabilities between [device-managed surfaces](https://learn.microsoft.com/windows-hardware/drivers/), between GDI-managed standard-format bitmaps, or between a device-managed surface and a GDI-managed standard-format bitmap.

## Parameters

### `psoTrg` [in, out]

Pointer to the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure that describes the surface on which to draw.

### `psoSrc` [in, optional]

Pointer to a SURFOBJ structure that describes the source for the bit-block transfer operation, if required by the *rop4* parameter.

### `psoMask` [in, optional]

Pointer to a SURFOBJ structure that describes a surface to be used as a mask for the *rop4* parameter. The mask is a bitmap with 1 bit per pixel. Typically, a mask is used to limit the area to be modified in the destination surface. Masking is selected by setting the *rop4* parameter to the value 0xAACC. The destination surface is unaffected if the mask is 0x0000.

The mask will be large enough to cover the destination rectangle.

If this parameter is **NULL** and a mask is required by the *rop4* parameter, the implicit mask in the brush is used.

### `pco` [in]

Pointer to a [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj) structure that limits the area to be modified. GDI services (**CLIPOBJ***Xxx*) that enumerate the [clip region](https://learn.microsoft.com/windows-hardware/drivers/) as a set of rectangles are provided. Whenever possible, GDI simplifies the clipping involved; for example, this function is never called with a single clipping rectangle. GDI clips the destination rectangle before calling this function, making additional clipping unnecessary.

### `pxlo` [in, optional]

Pointer to an [XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj) structure that specifies how color indices should be translated between the source and destination surfaces. If *pxlo* is **NULL**, no translation is needed.

If the source surface is palette-managed, its colors are represented by indices into a lookup table of RGB values. The XLATEOBJ structure can be queried for a translate vector that will allow the device driver to translate any source index into a color index for the destination.

The situation is more complicated when, for example, the source is RGB, but the destination is palette-managed. In this case, the closest match to each source RGB value must be found in the destination palette. The driver can call the [XLATEOBJ_iXlate](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_ixlate) service to perform this operation.

Optionally, the device driver can match colors when the target palette is the default device palette.

### `prclTrg` [in]

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines the area to be modified. This structure uses the coordinate system of the destination surface. The lower and right edges of this rectangle are not part of the bit-block transfer, meaning the rectangle is lower right exclusive.

**DrvBitBlt** is never called with an empty destination rectangle. The two points that define the rectangle are always well-ordered. However, on multimonitor systems the rectangle may define a region larger than the destination surface. Drivers should intersect this rectangle with their surface.

### `pptlSrc` [in, optional]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the upper left corner of the source rectangle, if a source exists. This parameter is ignored if there is no source.

### `pptlMask` [in, optional]

Pointer to a POINTL structure that defines which pixel in the mask corresponds to the upper left corner of the source rectangle, if a source exists. This parameter is ignored if the *psoMask* parameter is **NULL**.

### `pbo` [in, optional]

Pointer to a [BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj) structure that defines the pattern for the bit-block transfer. GDI's [BRUSHOBJ_pvGetRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvgetrbrush) service can be used to retrieve the device's realization of the brush. This parameter is ignored if the *rop4* parameter does not require a pattern.

### `pptlBrush` [in, optional]

Pointer to a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that defines the origin of the brush in the destination surface. The upper left pixel of the brush is aligned at this point, and the brush repeats according to its dimensions. This parameter is ignored if the *rop4* parameter does not require a pattern.

### `rop4` [in]

Specifies a raster operation that defines how the mask, pattern, source, and destination pixels are combined to write to the destination surface.

This is a quaternary raster operation, which is an extension of the ternary Rop3 operation. A Rop4 has 16 relevant bits, which are similar to the 8 defining bits of a Rop3. The simplest way to implement a Rop4 is to consider its 2 bytes separately: The low byte specifies a Rop3 that should be calculated if the mask is one, and the high byte specifies a Rop3 that can be calculated and applied if the mask is 0.

## Return value

DrvBitBlt returns **TRUE** if the bit-block transfer operation is successful. Otherwise, the function returns **FALSE**, and an error code is logged.

## Remarks

If the driver hooks **DrvBitBlt**, GDI will call this function when it needs to perform a BitBlt operation where one of the surfaces is a device-managed surface. If the driver implements opaque device-managed bitmaps, it must hook **DrvBitBlt**; otherwise, hooking **DrvBitBlt** is optional. If the driver cannot handle the specified call, it may punt the callback to the DIB engine by calling [EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt).

GDI's [CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)*Xxx* services allow the clipping to be reduced to a series of clipping rectangles. A translation vector assists in color index translation for palettes.

**Note** Do not dereference parameter pointers unless the [ROP](https://learn.microsoft.com/windows-hardware/drivers/) indicates they are needed. For example, never unnecessarily dereference *pbo*-->**iSolidColor** because doing so for a ROP such as BLACKNESS can cause an access violation. (This rule also applies to any function that includes a MIX parameter.)

If the driver receives a call to this function in which the *rop4* parameter is set to 0XCCAA, the driver should punt the call to [EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt), exposing the device surface(s) as appropriate for the call.

For more information about raster operations, see the Microsoft Windows SDK documentation.

## See also

[BRUSHOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-brushobj)

[BRUSHOBJ_pvGetRbrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-brushobj_pvgetrbrush)

[CLIPOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-clipobj)

[DrvSynchronize](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsynchronize)

[EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface)

[EngBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engbitblt)

[EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap)

[EngCreateDeviceSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedevicesurface)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)

[XLATEOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-xlateobj)

[XLATEOBJ_iXlate](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-xlateobj_ixlate)