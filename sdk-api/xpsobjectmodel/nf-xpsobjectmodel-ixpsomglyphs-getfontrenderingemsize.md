# IXpsOMGlyphs::GetFontRenderingEmSize

## Description

Gets the font size.

## Parameters

### `fontRenderingEmSize` [out, retval]

The font size.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *fontRenderingEmSize* is **NULL**. |

## Remarks

The em size that is returned in *fontRenderingEmSize* specifies the font size in the drawing surface units. The drawing surface units are expressed as floating-point values in the effective coordinate space.

In new glyph objects, the default value of *fontRenderingEmSize* is 10.0.

If the value of *fontRenderingEmSize* is 0.0, no text is displayed.

## See also

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))