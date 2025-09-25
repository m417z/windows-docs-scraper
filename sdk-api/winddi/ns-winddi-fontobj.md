# FONTOBJ structure

## Description

The FONTOBJ structure is used to give a driver access to information about a particular instance of a font.

## Members

### `iUniq`

Specifies a distinct realization of the font. This value can be used by the driver to identify a GDI font that it might have cached or to identify a driver's realization of its own font. If this member is zero for a GDI font, the font should not be cached.

### `iFace`

Specifies the device index for a device font, which was registered by a call to [DrvQueryFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfont). If the font is a GDI font, this member has meaning only to GDI, and the driver should ignore it.

### `cxMax`

Specifies the width, in pixels, of the largest glyph in the specified font.

### `flFontType`

Is a value specifying the type of the font. This member can be a combination of the flags listed in the following table. (Note, however, that FO_GRAY16 and FO_NOGRAY16 are mutually exclusive.)

| Flag | Meaning |
| --- | --- |
| FO_CFF | Postscript OpenType font. |
| FO_DBCS_FONT | Font supports DBCS code pages. |
| FO_EM_HEIGHT | TrueType driver internal flag. |
| FO_GRAY16 | Font bitmaps are four bits-per-pixel blending (alpha) values. |
| FO_MULTIPLEMASTER | Multiple Master (Type1 or OpenType) font. |
| FO_NOGRAY16 | Indicates that the font driver cannot (or will not) grayscale a particular font realization. |
| FO_POSTSCRIPT | Postscript (Type1 or OpenType) font. |
| FO_SIM_BOLD | Driver-simulated bold font. |
| FO_SIM_ITALIC | Driver-simulated italic font. |
| FO_TYPE_DEVICE | Device-specific font. |
| FO_TYPE_OPENTYPE | OpenType font. |
| FO_TYPE_RASTER | Bitmap font. |
| FO_TYPE_TRUETYPE | TrueType font. |
| FO_VERT_FACE | Vertical font. |

If the FO_RASTER flag is set, the glyphs written to the specified STROBJ structure are bitmaps, otherwise they are pointers to PATHOBJ structures. If the glyph images are returned in the form of PATHOBJ structures, the driver must inspect the FM_INFO_TECH_STROKE flag of the **flInfo** member of the associated [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure. If that flag is set, the paths should be stroked, otherwise the paths must be filled using the alternating mode convention.

If the FO_GRAY16 flag is set, then the font bitmaps are four bits-per-pixel blending (alpha) values. A value of zero means that the resulting pixel should have the same color as the background. If the alpha value is k, then the following table describes the attributes of the resulting pixel, using either linear alpha blending, or gamma-corrected alpha blending. In both methods, the foreground and background colors are, respectively, cf and cb.

| Pixel Attribute | Description |
| --- | --- |
| Blended Color<br><br>(linear alpha blending) | Linear alpha blending produces a blended color that is a linear combination of the foreground and background colors.<br><br> c = b * cf + (1 - b) * cb<br><br>The blend fraction, b, is obtained as follows:<br><br> b = k / 15, for k = 0, 1, 2, ..., 15<br><br>Note: the foreground and background colors include all three color channels (R, G, B). |
| Blended Color<br><br>(gamma-corrected alpha blending) | Gamma-corrected alpha blending produces a blended color by raising a variable that depends on the alpha value to a fixed power. <br><br>Two formulas are provided: one should be used when the foreground color is numerically larger than the background color; the other should be used in the opposite case. (When the foreground and background colors are equal, both formulas simplify to c = cb.) <br><br>If cf > cb,<br><br>c = cb + **pow**(b[k], (1 / gamma)) * (cf - cb)<br><br>If cf < cb,<br><br>c = cb + (1 - **pow**(1 - b[k], 1 / gamma)) * (cf - cb)<br><br>In these formulas, gamma = 2.33, and b[k] is the kth blending fraction, obtained as follows:<br><br>b[k] = 0, for k = 0, and<br><br>b[k] = (k + 1) / 16, for k = 1, 2, ..., 15<br><br>Note: unlike linear alpha blending, these formulas must be applied to *each* of the three color channels (R, G, B). |

GDI sets the FO_GRAY16 flag on entry to the [DrvQueryFontData](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfontdata) function when it requests that a font be grayscaled to one of 16 values. If the font driver cannot grayscale a particular font realization, then the font provider clears the FO_GRAY16 flag and sets the FO_NOGRAY16 flag to inform GDI that the grayscaling request will not be satisfied.

### `iTTUniq`

Specifies the associated TrueType file. Two separate point size realizations of a TrueType font face will have FONTOBJ structures that share the same **iTTUniq** value, but will have different **iUniq** values. Only TrueType font types can have a nonzero **iTTUniq** member. For more information see **flFontType**.

### `iFile`

Pointer to a driver-defined value for device fonts that are already loaded. If the font is a GDI font, then this member is used internally to identify the font and should be ignored.

### `sizLogResPpi`

Specifies the resolution of the device for which this font is realized.

### `ulStyleSize`

Specifies the style size of the font instance, in points.

### `pvConsumer`

Pointer to consumer-allocated data associated with this font instance. A consumer is a driver that accepts glyph information as input for generating text output. Only a font consumer can modify this member. The consumer of this font can store any information in the location pointed to by this member. The engine will not modify this member. The **pvConsumer** member is guaranteed to be null the first time a FONTOBJ structure is passed to the consumer.

### `pvProducer`

Pointer to producer-allocated data associated with this font instance. A producer is a driver that can produce glyph information as output; this includes glyph metrics, bitmaps, and outlines. Only a font producer can modify this member. The producer of this font can store any information in the location pointed to by this member. The engine will not modify this member. The **pvProducer** member is guaranteed to be null the first time a FONTOBJ structure is passed to the producer.

## Remarks

As an accelerator, the driver is allowed to access the public members of the FONTOBJ structure.

A driver can be both a producer and a consumer. For example, a printer driver can act as a producer while processing a call to the driver-supplied [DrvQueryFontData](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfontdata) function to provide glyph metrics, and later act a consumer while processing a call to the driver-supplied [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout) function.

## See also

[DrvDestroyFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdestroyfont)

[DrvGetGlyphMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetglyphmode)

[DrvQueryFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfont)

[DrvQueryTrueTypeOutline](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvquerytruetypeoutline)

[FONTOBJ_cGetAllGlyphHandles](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_cgetallglyphhandles)

[FONTOBJ_cGetGlyphs](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_cgetglyphs)

[FONTOBJ_pifi](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_pifi)

[FONTOBJ_pxoGetXform](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_pxogetxform)

[FONTOBJ_vGetInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-fontobj_vgetinfo)

[IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics)