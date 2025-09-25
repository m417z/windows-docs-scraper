# IXpsOMGradientBrush::GetGradientStops

## Description

Gets a pointer to an [IXpsOMGradientStopCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstopcollection) interface that contains the collection of [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interfaces that define the gradient.

## Parameters

### `gradientStops` [out, retval]

A pointer to the [IXpsOMGradientStopCollection](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstopcollection) interface that contains the collection of [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interfaces.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *gradientStops* is **NULL**. |

## Remarks

Gradient stops, which are described in the XPS OM by an [IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop) interface, are used to define the color at a specific location along a gradient path; the color is interpolated between the gradient stops. The illustration that follows shows the gradient path and gradient stops of a linear gradient.

![A figure that shows the terms used in a linear gradient](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/LinearGradient2.png)
The illustration that follows shows the gradient stops of a radial gradient. In this example, the gradient region is the area enclosed by the outer ellipse, and the radial gradient is using the **XPS_SPREAD_METHOD_REFLECT** spread method to fill the space outside of the gradient region.

![A figure that shows the terms used in a radial gradient](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/RadialGradient2.png)

## See also

[IXpsOMGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientbrush)

[IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))