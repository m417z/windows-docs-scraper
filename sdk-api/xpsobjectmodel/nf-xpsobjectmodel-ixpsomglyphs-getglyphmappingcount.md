# IXpsOMGlyphs::GetGlyphMappingCount

## Description

Gets the number of glyph mappings.

## Parameters

### `glyphMappingCount` [out, retval]

The number of glyph mappings.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *glyphMappingCount* is **NULL**. |

## Remarks

[GetGlyphMappings](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getglyphmappings) gets the glyph mappings.

## See also

[GetGlyphMappings](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getglyphmappings)

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))