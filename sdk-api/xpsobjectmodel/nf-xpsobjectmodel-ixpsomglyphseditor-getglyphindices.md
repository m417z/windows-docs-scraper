# IXpsOMGlyphsEditor::GetGlyphIndices

## Description

Gets an array of [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures that describe the specific glyph indices in the font.

## Parameters

### `indexCount` [in, out]

The number of elements that will fit in the array referenced by the *glyphIndices* parameter. When the method returns, *indexCount* will contain the number of [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures that are returned in the array referenced by *glyphIndices*.

### `glyphIndices` [out]

The [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structure array that receives the glyph indices.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *indexCount* or *glyphIndices* is **NULL**, or both are **NULL**. |
| **ERROR_MORE_DATA** | *glyphIndices* is not large enough to receive the glyph index data. *indexCount* contains the required number of elements. |

## Remarks

 The glyph indices that are returned in *glyphIndices* override the default cmap mapping from the **UnicodeString** property to the glyph index. Each [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structure also contains advance width and vertical and horizontal offset information.

[GetGlyphIndexCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphseditor-getglyphindexcount) gets the number of elements in the glyph index array.

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index)