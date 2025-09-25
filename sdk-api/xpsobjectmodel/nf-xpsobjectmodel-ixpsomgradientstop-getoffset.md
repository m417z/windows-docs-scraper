# IXpsOMGradientStop::GetOffset

## Description

Gets the offset value of the gradient stop.

## Parameters

### `offset` [out, retval]

The offset value of the gradient stop, expressed as a fraction of the gradient path.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *offset* is **NULL**. |

## Remarks

The valid range of values returned in *offset* is 0.0–1.0. 0.0 is the start point of the gradient, 1.0 is the end point, and a value between 0.0 and 1.0 is a location that is linearly interpolated between the start point and the end point.

## See also

[IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))