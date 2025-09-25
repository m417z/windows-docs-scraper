# IXpsOMPath::SetStrokeDashOffset

## Description

Sets the offset from the origin of the stroke to the starting point of the dash array pattern.

## Parameters

### `strokeDashOffset` [in]

The offset value to be set.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *strokeDashOffset* is not a valid offset value. |

## Remarks

 The offset describes the distance from the origin of the stroke where the dash starts, and is specified in multiples of the stroke thickness.

## See also

[IXpsOMPath](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompath)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))