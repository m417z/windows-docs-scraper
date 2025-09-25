# TYPE1_FONT structure

## Description

The TYPE1_FONT structure contains the information necessary for a PostScript driver to access a Type1 font through GDI.

## Members

### `hPFM`

Handle to the PostScript Type1 .[pfm](https://learn.microsoft.com/windows-hardware/drivers/) file.

### `hPFB`

Handle to the PostScript Type1 .*pfb* file.

### `ulIdentifier`

Is an identifier that is generated and used by GDI. The driver stores **ulIdentifier** in the **dpCharSets** field of the [IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics) structure.

## Remarks

A PostScript driver can obtain a list of installed Type1 fonts by calling [EngGetType1FontList](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-enggettype1fontlist).

Each PostScript Type1 font comes with two separate files: a .*pfm* file and a .*pfb* file. The .*pfm* file contains font metrics information; the .*pfb* file contains the PostScript Type1 binary font data.

## See also

[IFIMETRICS](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-ifimetrics)