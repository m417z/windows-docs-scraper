# IXpsOMGlyphsEditor::SetGlyphIndices

## Description

Sets an [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structure array that describes which glyph indices are to be used in the font.

## Parameters

### `indexCount` [in]

The number of [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures in the array that is referenced by *glyphIndices*. The value of 0 clears the property.

### `glyphIndices` [in]

An array of [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures that contain the glyph indices. If *indexCount* is 0, this parameter is ignored.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The **index** field of one or more [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures has a value that is not valid. The **index** field must have a value between and including –1 and 65535 (0xFFFF). |
| **E_POINTER** | *glyphIndices* is **NULL** and *indexCount* is greater than 0. |
| **XPS_E_INVALID_FLOAT** | The **advanceWidth**, **horizontalOffset**, or **verticalOffset** field of one or more [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures has a floating-point value that is not valid. |
| **XPS_E_NEGATIVE_FLOAT** | The **advanceWidth** field of one or more [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structures has a value that is not valid. The **advanceWidth** field must have a non-negative value or a value of exactly –1.0; a negative value that is not exactly –1.0 is not valid. |

## Remarks

 The glyph indices that are passed in *glyphIndices* override the default cmap mapping from the **UnicodeString** property to the glyph index. Each [XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index) structure also has advance width and vertical and horizontal offset information.

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_GLYPH_INDEX](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_glyph_index)