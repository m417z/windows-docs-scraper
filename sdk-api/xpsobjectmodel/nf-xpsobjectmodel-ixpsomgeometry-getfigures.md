# IXpsOMGeometry::GetFigures

## Description

Gets a pointer to the geometry's [IXpsOMGeometryFigureCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigurecollection) interface, which contains the collection of figures that make up this geometry.

## Parameters

### `figures` [out, retval]

A pointer to the [IXpsOMGeometryFigureCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigurecollection) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *figures* is **NULL**. |

## See also

[IXpsOMGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometry)

[IXpsOMGeometryFigureCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigurecollection)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))