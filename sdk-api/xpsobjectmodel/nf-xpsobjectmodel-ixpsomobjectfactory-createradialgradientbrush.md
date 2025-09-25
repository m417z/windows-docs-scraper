# IXpsOMObjectFactory::CreateRadialGradientBrush

## Description

Creates an [IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush) interface.

## Parameters

### `gradStop1` [in]

The [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interface that specifies the properties of the gradient at gradient origin. This parameter must not be **NULL**.

### `gradStop2` [in]

The [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interface that specifies the properties of the gradient at the end of the gradient's vector, which is the ellipse that encloses the gradient region. This parameter must not be **NULL**.

### `centerPoint` [in]

The coordinates of the center point of the radial gradient ellipse.

### `gradientOrigin` [in]

The coordinates of the origin of the radial gradient.

### `radiiSizes` [in]

The [XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size) structure whose members specify the lengths of the gradient region's radii.

Size is described in XPS units. There are 96 XPS units per inch. For example, a 1" radius is 96 XPS units.

| [XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size) Member | Meaning |
| --- | --- |
| **width** | Length of the radius along the x-axis. |
| **height** | Length of the radius along the y-axis. |

### `radialGradientBrush` [out, retval]

A pointer to the new [IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The point that is described by *centerPoint*, *radiiSizes*, or *gradientOrigin* is not valid. The members of the [XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point) structure must contain valid and finite floating-point values. |
| **E_POINTER** | *gradStop1*, *gradStop2*, *centerPoint*, *gradientOrigin*, *radiiSizes*, or *radialGradientBrush* is **NULL**. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *gradStop1* or *gradStop1* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

 As shown in the following illustration, the gradient region of a radial gradient is the area enclosed by the ellipse that is described by the center point and the x and y radii that extend from the center point. The spread area is the area outside of that ellipse. The gradient path (not shown) is a radial line that is drawn between the gradient origin and the ellipse that bounds the gradient region.

![A figure that shows the terms used in a radial gradient](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/RadialGradient1.png)
For radial-gradient brushes, the gradient stop that is set by the *gradStop1* parameter corresponds to the gradient origin location and an offset value of 0.0. The gradient stop that is set by the *gradStop2* parameter corresponds to the circumference of the gradient region and an offset value of 1.0. For more information on gradient stops, see [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop).

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMRadialGradientBrush    *newInterface;
// The following values are defined outside of
// this example.
//  IXpsOMGradientStop       *gradStop1, *gradStop2;
//  XPS_POINT                centerPoint, gradientOrigin;
//  XPS_SIZE                 radiiSizes;

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
    hr = xpsFactory->CreateRadialGradientBrush (
        gradStop1,
        gradStop2,
        &centerPoint,
        &gradientOrigin,
        &radiiSizes,
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

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point)

[XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size)