# IXpsOMLinearGradientBrush::SetEndPoint

## Description

Sets the end point of the gradient.

## Parameters

### `endPoint` [in]

The x and y coordinates of the end point.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The point described by *endPoint* was not valid. The [XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point) structure must contain valid and finite floating-point values. |
| **E_POINTER** | *endPoint* is **NULL**. |

## Remarks

The coordinates are relative to the page and are expressed in the units of the transform that is in effect.

## See also

[IXpsOMLinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomlineargradientbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point)