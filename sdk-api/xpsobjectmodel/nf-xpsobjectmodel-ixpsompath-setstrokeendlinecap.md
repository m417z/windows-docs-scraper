# IXpsOMPath::SetStrokeEndLineCap

## Description

Sets the style of the stroke line's end cap.

## Parameters

### `strokeEndLineCap` [in]

The [XPS_LINE_CAP](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_line_cap) value to be set.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *strokeEndLineCap* is not a valid [XPS_LINE_CAP](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_line_cap) value. |

## Remarks

For more information about dash cap styles, see [XPS_LINE_CAP](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_line_cap).

## See also

[IXpsOMPath](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompath)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))