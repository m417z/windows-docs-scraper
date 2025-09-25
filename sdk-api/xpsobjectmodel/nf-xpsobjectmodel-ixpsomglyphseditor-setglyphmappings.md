# IXpsOMGlyphsEditor::SetGlyphMappings

## Description

Sets an array of [XPS_GLYPH_MAPPING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_mapping) structures that describe how to map the UTF-16 scalar values in the **UnicodeString** property to entries in the array of [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures.

## Parameters

### `glyphMappingCount` [in]

The number of [XPS_GLYPH_MAPPING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_mapping) structures in the array that is referenced by *glyphMappings*. A value of 0 clears the property.

### `glyphMappings` [in]

An [XPS_GLYPH_MAPPING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_mapping) structure array that contains the glyph mapping values. If *glyphMappingCount* is 0, this parameter is ignored and can be set to **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | A member of one or more [XPS_GLYPH_MAPPING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_mapping) structures has a value that is not valid. This can occur in the following cases: the sum of string length and start position is less than the start position; the sum of index position and index length is less than the start position; and length of indices is 0. |
| **E_POINTER** | *glyphMappings* is **NULL** and *glyphMappingCount* is greater than 0. |
| **XPS_E_MAPPING_OUT_OF_ORDER** | In one or more [XPS_GLYPH_MAPPING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_mapping) structures, an element is out of sequence. |

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_GLYPH_MAPPING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_mapping)