# IXpsOMGlyphsEditor::GetBidiLevel

## Description

Gets the bidirectional text level of the parent [IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs) interface.

## Parameters

### `bidiLevel` [out, retval]

The bidirectional text level.

Range: 0–61

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | bidiLevel is **NULL**. |

## Remarks

The **BidiLevel** property specifies the bidirectional nesting level of the Unicode algorithm. Even values imply the left-to-right layout and odd values the right-to-left layout. Right-to-left layout places the run origin at the right side of the first glyph. Advance widths that are positive will move to the left, allowing subsequent glyphs to be placed to the left of the previous glyph.

The range of allowed values for this property is between 0 and 61, inclusive, and the default value is 0.

## See also

[IXpsOMGlyphsEditor](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphseditor)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))