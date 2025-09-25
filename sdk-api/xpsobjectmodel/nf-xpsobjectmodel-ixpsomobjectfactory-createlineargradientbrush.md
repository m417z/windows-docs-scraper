# IXpsOMObjectFactory::CreateLinearGradientBrush

## Description

Creates an [IXpsOMLinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomlineargradientbrush) interface.

## Parameters

### `gradStop1` [in]

The [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interface that specifies the gradient properties at the beginning of the gradient's vector. This parameter must not be **NULL**.

### `gradStop2` [in]

The [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interface that specifies the gradient properties at the end of the gradient's vector. This parameter must not be **NULL**.

### `startPoint` [in]

The [XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point) structure that contains the coordinates of the start point in two-dimensional space.

### `endPoint` [in]

The [XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point) structure that contains the coordinates of the end point in two-dimensional space.

### `linearGradientBrush` [out, retval]

A pointer to the new [IXpsOMLinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomlineargradientbrush) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The point specified by either *startPoint* or *endPoint* was not valid. The members of the [XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point) structure must contain valid and finite floating-point values. |
| **E_POINTER** | *gradStop1*, *gradStop2*, *startPoint*, *figure*, or *linearGradientBrush* is **NULL**. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *gradStop1* or *gradStop1* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

The gradient region of a linear gradient is the area between and including the start and end points and extending in both directions at a right angle to the gradient path. The spread area is the area of the geometry that lies outside the gradient region.

Gradient stops define the color at specific locations along the gradient path. In the illustration, gradient stop 0, specified by the *gradStop1* parameter, is located at the start point of the gradient path, and gradient stop 1, specified by the *gradStop2* parameter, is at the end point.

As shown in the illustration that follows, the start and end points of a linear gradient are also the start and end points of the gradient path, which is the straight line that connects those points.

![A figure that shows the terms used in a linear gradient](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/LinearGradient1.png)
The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMLinearGradientBrush    *newInterface;
// The following values are defined outside of
// this example.
//  IXpsOMGradientStop       *gradStop1, *gradStop2;
//  XPS_POINT                startPoint, endPoint;

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
    hr = xpsFactory->CreateLinearGradientBrush (
        gradStop1,
        gradStop2,
        &startPoint,
        &endPoint,
        &newInterface);

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

[IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop)

[IXpsOMLinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomlineargradientbrush)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point)