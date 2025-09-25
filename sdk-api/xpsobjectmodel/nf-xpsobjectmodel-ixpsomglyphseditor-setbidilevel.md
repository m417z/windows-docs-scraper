# IXpsOMGlyphsEditor::SetBidiLevel

## Description

Sets the level of bidirectional text.

## Parameters

### `bidiLevel` [in]

The level of bidirectional text.

Range: 0–61

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value of *bidiLevel* is outside of the allowed range. For more information, see the Remarks section. |

## Remarks

The **BidiLevel** property specifies the bidirectional nesting level of the Unicode algorithm. Even values imply the left-to-right layout and odd values the right-to-left layout. Right-to-left layout places the run origin on the right side of the first glyph. Advance widths that are positive will move to the left, allowing subsequent glyphs to be placed to the left of the previous glyph.

The range of allowed values for this property is between 0 and 61, inclusive, and the default value is 0.

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))