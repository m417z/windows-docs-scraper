# IXpsOMObjectFactory::CreateGradientStop

## Description

Creates an [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interface to represent a single color and location definition within a gradient.

## Parameters

### `color` [in]

The color value.

### `colorProfile` [in]

A pointer to the [IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource) interface that contains the color profile to be used. If the color type is not [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type), this parameter must be **NULL**.

### `offset` [in]

The offset value.

Valid range: 0.0–1.0

### `gradientStop` [out, retval]

A pointer to the new [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value in *offset* is not valid. |
| **E_POINTER** | *color* or *gradientStop* is **NULL**. |
| **XPS_E_MISSING_COLORPROFILE** | *colorProfile* is **NULL** but a color profile is expected. A color profile is required when the color type is [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type). |
| **XPS_E_NO_CUSTOM_OBJECTS** | *colorProfile* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |
| **XPS_E_UNEXPECTED_COLORPROFILE** | *colorProfile* contains a color profile but one is not expected. A color profile is only allowed when the color type is [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type). |

## Remarks

 Gradient stops are used to define the color at a specific location; the color is interpolated between the gradient stops. The offset, which is specified by *offset*, is a relative position between the start and end points of the gradient. The offset at the start point of a linear gradient or the origin of a radial gradient is 0.0. The offset of the end point of a linear gradient or the bounding ellipse of a radial gradient is 1.0. Gradient stops can be specified for any offset between those points, including the start and end points. The following illustration shows the gradient path and gradient stops of a linear gradient.

![A figure that shows the terms used in a linear gradient](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/LinearGradient2.png)
The following illustration shows the gradient stops of a radial gradient. In this example, the radial gradient region is the area enclosed by the outer ellipse and the **XPS_SPREAD_METHOD_REFLECT** spread method is used to fill the space outside of the gradient region.

![A figure that shows the terms used in a radial gradient](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/RadialGradient2.png)
The [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interface specifies one and only one stop in a gradient.

The calculations used to render a gradient are described in the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification).

The code example that follows illustrates how this method is used to create a new interface.

```cpp

IXpsOMGradientStop    *newInterface;
// The following values are defined outside of
// this example.
//  XPS_COLOR                    color;
//  IXpsOMColorProfileResource    *colorProfile;
//  FLOAT                        offset;

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
    hr = xpsFactory->CreateGradientStop (
        &color,
        colorProfile,
        offset,
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

[IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource)

[IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_COLOR](https://learn.microsoft.com/previous-versions/windows/desktop/dd372939(v=vs.85))