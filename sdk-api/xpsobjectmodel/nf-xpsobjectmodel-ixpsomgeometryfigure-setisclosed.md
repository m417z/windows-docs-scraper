# IXpsOMGeometryFigure::SetIsClosed

## Description

Sets a value that indicates whether the figure is closed.

## Parameters

### `isClosed` [in]

The value to be set.

| Value | Meaning |
| --- | --- |
| **TRUE** | The figure is closed. A line segment between the start point and the last point defined in the figure will be stroked. |
| **FALSE** | The figure is open. There is no line segment between the start point and the last point defined in the figure. |

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

 This value only applies if the **PathFigure** attribute is used in the **Path** element that specifies a stroke.

 A closed figure adds a line segment between the start point and the end point of the figure to close the shape.

This value corresponds to that of the **IsClosed** element of the **PathFigure** element in the document markup.

## See also

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)