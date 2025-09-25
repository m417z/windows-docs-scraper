# IXpsOMGlyphs::SetOrigin

## Description

Sets the starting position of the text.

## Parameters

### `origin` [in]

The [XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point) structure that contains the coordinates to be set as the text's starting position.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *origin* is **NULL**. |
| **E_INVALIDARG** | *origin.x* or *origin.y* refers to a floating-point value that is not valid. |

## Remarks

In the units of the effective coordinate space, the origin specifies the x and y coordinates of the first glyph in the run. The glyph is placed such that its baseline and the leading edge of its advance vector intersect with the point defined by *origin.x* and *origin.y*.

## See also

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point)