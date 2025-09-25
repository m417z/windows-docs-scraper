# IXpsOMGeometryFigure::GetIsClosed

## Description

Gets a value that indicates whether the figure is closed.

## Parameters

### `isClosed` [out, retval]

The Boolean value that indicates whether the figure is closed.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | The figure is closed. The line segment between the start and end points of the figure will be stroked to close the shape. |
| ****FALSE**** | The figure is open. No line segment will be stroked between the start and end points of the figure. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *isClosed* is **NULL**. |

## Remarks

 This value only applies if the **PathFigure** attribute is used in the **Path** element that specifies a stroke.

 A closed figure adds a line segment between the start point and the end point of the figure to close the shape.

This value corresponds to that of the **IsClosed** element of the **PathFigure** element in the document markup.

## See also

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))