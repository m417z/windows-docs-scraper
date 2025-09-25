# IXpsOMPath::GetStrokeMiterLimit

## Description

Gets the miter limit value that is set for the stroke.

## Parameters

### `strokeMiterLimit` [out, retval]

The miter limit value that is set for the stroke.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *strokeMiterLimit* is **NULL**. |

## Remarks

 The miter limit value is the ratio of the maximum miter length to one-half of the stroke thickness.

The miter limit value describes how to render a mitered line join; this value applies only if the line join style value is [XPS_LINE_JOIN_MITER](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_line_join).

## See also

[IXpsOMPath](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompath)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_LINE_JOIN_MITER](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_line_join)