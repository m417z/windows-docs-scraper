# IXpsOMGeometryFigure::GetStartPoint

## Description

Gets the starting point of the figure.

## Parameters

### `startPoint` [out, retval]

The coordinates of the starting point of the figure.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *startPoint* is **NULL**. |

## Remarks

In the document markup, the value returned in *startPoint* corresponds to that of the **StartPoint** attribute of the **PathFigure** element.

## See also

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point)