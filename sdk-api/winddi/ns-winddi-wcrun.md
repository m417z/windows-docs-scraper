# WCRUN structure

## Description

The WCRUN structure describes a run of Unicode characters.

## Members

### `wcLow`

Specifies the first character in the run.

### `cGlyphs`

Specifies the count of characters in the run.

### `phg`

Pointer to an array of glyph handles that correspond to this run. If this member is **NULL**, then each character in this run can be converted to a glyph handle by a cast, as in the following example:

```
HGLYPH hg = (HGLYPH) wc;
```

## Remarks

GDI relies on the runs being arranged in increasing order by code points. A binary search is made through the list of runs.

The [FD_GLYPHSET](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphset) structure contains a WCRUN structure as one of its members.

## See also

[DrvQueryFontTree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfonttree)

[FD_GLYPHSET](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-fd_glyphset)