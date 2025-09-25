# EngComputeGlyphSet function

## Description

The **EngComputeGlyphSet** function computes the glyph set supported on a device.

## Parameters

### `nCodePage` [in]

Specifies the code page supported.

### `nFirstChar` [in]

Specifies the character code of the first supported ANSI character.

### `cChars` [in]

Specifies the number of ANSI characters supported.

## Return value

If the glyph set is computed successfully, the function returns a pointer to an [FD_GLYPHSET](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphset) structure. If an error occurs, the function returns **NULL**.

## Remarks

A driver can use **EngComputeGlyphSet** to compute the glyph set for a font that contains only glyphs in the code page described by *nCodePage*.

The driver must call [EngFreeMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreemem) to free memory when it is done using the FD_GLYPHSET structure returned by **EngComputeGlyphSet**.

## See also

[EngFreeMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfreemem)

[FD_GLYPHSET](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphset)