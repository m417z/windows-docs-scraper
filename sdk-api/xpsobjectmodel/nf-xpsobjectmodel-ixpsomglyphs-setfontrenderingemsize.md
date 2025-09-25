# IXpsOMGlyphs::SetFontRenderingEmSize

## Description

Sets the font size of the text.

## Parameters

### `fontRenderingEmSize` [in]

The font size.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value of *fontRenderingEmSize* is not valid; it must be a non-negative number. |

## Remarks

The em size returned in *fontRenderingEmSize* specifies the font size in drawing surface units. Drawing surface units are expressed as floating-point values in the units of the effective coordinate space.

In new glyph objects, the default value of *fontRenderingEmSize* is 10.0.

If the value of *fontRenderingEmSize* is 0.0, no text is displayed.

A value of 0.0 results in no visible text being displayed.

## See also

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))