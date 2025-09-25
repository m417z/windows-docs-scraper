# IXpsOMGlyphs::GetGlyphIndices

## Description

Gets an array of [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures that describe the specific glyph indices in the font.

## Parameters

### `indexCount` [in, out]

The number of [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures that will fit in the array that is referenced by *glyphIndices*. When the method returns, *indexCount* will contain the number of **XPS_GLYPH_INDEX** structures that are returned in the array referenced by *glyphIndices*.

### `glyphIndices` [in, out]

The address of an array of [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures that receive the glyph indices.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *indexCount* or *glyphIndices* is **NULL**. |
| **ERROR_MORE_DATA** | *glyphIndices* is not large enough to receive the glyph index data. *indexCount* contains the required number of elements. |

## Remarks

[GetGlyphIndexCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getglyphindexcount) gets the number of elements in the glyph index array.

The glyph indices override the default **cmap** mapping from the **UnicodeString** to the glyph index. The [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structure also contains advance width as well as vertical and horizontal offset information.

## See also

[GetGlyphIndexCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getglyphindexcount)

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index)