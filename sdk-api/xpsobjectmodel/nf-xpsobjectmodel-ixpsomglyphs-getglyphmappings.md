# IXpsOMGlyphs::GetGlyphMappings

## Description

Gets an array of [XPS_GLYPH_MAPPING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_mapping) structures that describe how to map UTF-16 scalar values to entries in the array of [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures, which is returned by [GetGlyphIndices](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getglyphindices).

## Parameters

### `glyphMappingCount` [in, out]

The number of [XPS_GLYPH_MAPPING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_mapping) structures that will fit in the array referenced by *glyphMappings*. When the method returns, *glyphMappingCount* contains the number of values returned in the array referenced by *glyphMappings*.

### `glyphMappings` [in, out]

An array of [XPS_GLYPH_MAPPING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_mapping) structures that contain the glyph mapping values.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *glyphMappingCount*, *glyphMappings*, or both are **NULL**. |
| **ERROR_MORE_DATA** | *glyphMappings* is not large enough to receive the glyph index data. *glyphMappingCount* contains the required number of elements. |

## Remarks

[GetGlyphMappingCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getglyphmappingcount) gets the number of glyph mappings.

## See also

[GetGlyphMappingCount](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getglyphmappingcount)

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index)

[XPS_GLYPH_MAPPING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_mapping)