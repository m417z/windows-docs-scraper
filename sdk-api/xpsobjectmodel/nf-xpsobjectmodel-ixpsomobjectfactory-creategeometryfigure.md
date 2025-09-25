# IXpsOMObjectFactory::CreateGeometryFigure

## Description

Creates an [IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure) interface, which specifies a portion of an object that is defined by an [IXpsOMGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometry) interface.

## Parameters

### `startPoint` [in]

The coordinates of the starting point of the geometry figure.

### `figure` [out, retval]

A pointer to the new [IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *startPoint* or *figure* is **NULL**. |
| **XPS_E_INVALID_FLOAT** | One of the fields in the [XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point) structure that is passed in *startPoint* contains a value that is not valid. |

## Remarks

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMGeometryFigure    *newInterface;
// startPoint contains the starting point
// of the geometry figure being created
XPS_POINT                startPoint = {0,0};

// Note the implicit requirement that CoInitializeEx
//  has previously been called from this thread.

hr = CoCreateInstance(
    __uuidof(XpsOMObjectFactory),
    NULL,
    CLSCTX_INPROC_SERVER,
    _uuidof(IXpsOMObjectFactory),
    reinterpret_cast<LPVOID*>(&xpsFactory)
    );

if (SUCCEEDED(hr))
{
    hr = xpsFactory->CreateGeometryFigure (&startPoint, &newInterface);
    if (SUCCEEDED(hr))
    {
        // use newInterface

        newInterface->Release();
    }
    xpsFactory->Release();
}
else
{
    // evaluate HRESULT error returned in hr
}

```

## See also

[IXpsOMGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometry)

[IXpsOMGeometryFigure](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometryfigure)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point)