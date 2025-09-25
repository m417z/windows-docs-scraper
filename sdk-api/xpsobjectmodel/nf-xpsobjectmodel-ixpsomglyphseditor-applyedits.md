# IXpsOMGlyphsEditor::ApplyEdits

## Description

Performs cross-property validation and then copies the changes to the parent [IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The [IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor) interface does not belong to a valid [IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs) interface. |
| **XPS_E_CARET_OUTSIDE_STRING** | Caret stops were specified for an empty string, or the caret jump index has exceeded the length of the Unicode string. |
| **XPS_E_MAPPING_OUTSIDE_INDICES** | The glyph mappings exceed the number of glyph indices. |
| **XPS_E_MAPPING_OUTSIDE_STRING** | Glyph mappings were defined for an empty string. If the Unicode string is empty, there must not be any glyph mappings defined.<br><br>or<br><br>The glyph mappings exceed the length of the Unicode string. |
| **XPS_E_MISSING_GLYPHS** | The [IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs) interface without a Unicode string does not have any glyph indices specified. An **IXpsOMGlyphs** interface must specify either a Unicode string or an array of glyph indices. |
| **XPS_E_ODD_BIDILEVEL** | The text string was specified as sideways and right-to-left. If the text is sideways, it cannot have a bidi level that is an odd value (right-to-left). Likewise, if the bidi level is an odd value, it cannot be sideways. |
| **XPS_E_ONE_TO_ONE_MAPPING_EXPECTED** | Glyph mappings did not match the Unicode string contents. |
| **XPS_E_TOO_MANY_INDICES** | There were more glyph indices than Unicode code points. If there are no glyph mappings, the number of glyph indices must be less than or equal to the number of Unicode code points. |

## Remarks

The [IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor) interface remains valid after this method is called, allowing for additional modifications to be made.

## See also

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))