# FD_DEVICEMETRICS structure

## Description

The FD_DEVICEMETRICS structure is used to provide device-specific font information to GDI if the *iMode* parameter of the driver-supplied [DrvQueryFontData](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfontdata) function is QFD_MAXEXTENTS.

## Members

### `flRealizedType`

Is a set of accelerator flags. This value can be a combination of the following values:

#### FDM_TYPE_BM_SIDE_CONST

An accelerator for horizontal and vertical writing. If this flag is set, the font has constant height for all bitmaps. In the horizontal case, this means that the *cy* dimension is constant; in the vertical case, this means that the *cx* dimension is constant. This accelerator is not used for outlines.

#### FDM_TYPE_CHAR_INC_EQUAL_BM_BASE

An accelerator for horizontal and vertical writing. In the horizontal case, if this flag is set, each glyph's advance width is equal to the *cx* dimension of the glyph bitmap; in the vertical case, if this flag is set, each glyph's advance width is equal to the *cy* dimension of the glyph bitmap. This accelerator is not used for outlines.

#### FDM_TYPE_CONST_BEARINGS

If set, the a and c spacing is constant for all glyphs.

#### FDM_TYPE_MAXEXT_EQUAL_BM_SIDE

This flag can be set only if FDM_TYPE_BM_SIDE_CONST is also set. If set, the font height (as defined above for horizontal and vertical writing) is equal to the sum of max ascender and max descender. This accelerator is not used for outlines.

#### FDM_TYPE_ZERO_BEARINGS

If set, the a and c spacing is zero for all glyphs.

### `pteBase`

Specifies a POINTE structure that contains the notional space unit vector along the font's baseline, transformed to device space and then normalized. For more information, see POINTE in [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

### `pteSide`

Specifies POINTE structure that contains a notional space unit vector perpendicular to the font's baseline in the direction of the ascender, transformed to device space and then normalized. In notional space, baseline and ascender directions must be orthogonal, but in device space, **pteBase** and **pteSide** do not have to be orthogonal, depending on the Notional to Device space transform.

### `lD`

Specifies the advance width if the font is a fixed pitch (monospaced) font. If the font is a variable pitch font, this member should be set to zero.

### `fxMaxAscender`

Specifies the hinted maximum ascender height for this font instance, measured along **pteSide**. See the FIX data type in [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

### `fxMaxDescender`

Specifies the hinted maximum descender height for this font instance, measured along **pteSide**. See the FIX data type in [GDI Data Types](https://learn.microsoft.com/windows-hardware/drivers/display/gdi-data-types).

### `ptlUnderline1`

Specifies a [POINTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-pointl) structure that contains the hinted underline position for this font instance, relative to the glyph's character origin.

### `ptlStrikeOut`

Specifies a POINTL structure that contains the hinted strikeout position for this font instance, relative to the glyph's character origin.

### `ptlULThickness`

Specifies a POINTL structure that contains the hinted underline thickness for this font instance. This vector defines the side of the rectangle used to draw the underline. The base is implicitly defined by the baseline.

### `ptlSOThickness`

Specifies a POINTL structure that contains the hinted strikeout thickness for this font instance. This vector defines the side of the rectangle used to draw the strikeout. The base is implicitly defined by the baseline.

### `cxMax`

Specifies the hinted maximum glyph bitmap width, in pixels, for this font instance. Not used for outlines.

### `cyMax`

Specifies the hinted maximum glyph bitmap height, in pixels, for this font instance. Not used for outlines.

### `cjGlyphMax`

Specifies the hinted maximum size of a glyph, in bytes, for this font instance. This value is the maximum size of the [GLYPHBITS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphbits) structure needed to store any of the font's glyphs.

### `fdxQuantized`

Specifies an [FD_XFORM](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_xform) structure. The font driver fills in the font transformation that is actually used in the realization of the font. This may differ from the transformation requested by GDI as defined by [FONTOBJ_pxoGetXform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_pxogetxform).

### `lNonLinearExtLeading`

Is the nonlinear external leading in 28.4 device units.

### `lNonLinearIntLeading`

Is the nonlinear internal leading in 28.4 device units.

### `lNonLinearMaxCharWidth`

Is the nonlinear maximum character increment in 28.4 device units.

### `lNonLinearAvgCharWidth`

Is the nonlinear average character width in 28.4 device units.

### `lMinA`

Is the largest negative A space for this font realization, specified as an absolute value.

### `lMinC`

Is the largest negative C space for this font realization, specified as an absolute value.

### `lMinD`

Is the smallest nonzero character width for this font realization.

### `alReserved`

Is reserved and should be ignored by the font provider.

## See also

[DrvQueryFontData](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfontdata)

[FD_XFORM](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_xform)

[FONTOBJ_pxoGetXform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_pxogetxform)

[GLYPHBITS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-glyphbits)