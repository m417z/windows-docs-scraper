# XPS_SPREAD_METHOD enumeration

## Description

Describes how the spread region is to be filled.
The spread region is the area that falls within the drawing area but outside of the gradient region.

## Constants

### `XPS_SPREAD_METHOD_PAD:1`

The spread region is filled with the color whose value equals the color at the end of the gradient region.

### `XPS_SPREAD_METHOD_REFLECT`

The spread region is filled by repeating the alternating reflection of the gradient that is inside the gradient region.

### `XPS_SPREAD_METHOD_REPEAT`

The spread region is filled by repeating the gradient that is inside the gradient region, in the same orientation and direction.

## Remarks

The following illustration shows the effect of the spread methods on gradients that are drawn by using the [IXpsOMLinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomlineargradientbrush) and [IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush) interfaces. The gradient region of an **IXpsOMLinearGradientBrush** interface is defined by calling the [SetStartPoint](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomlineargradientbrush-setstartpoint) and [SetEndPoint](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomlineargradientbrush-setendpoint) methods; the gradient region of an **IXpsOMRadialGradientBrush** interface is defined by calling the [SetCenter](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomradialgradientbrush-setcenter), [SetGradientOrigin](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomradialgradientbrush-setgradientorigin), and [SetRadiiSizes](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomradialgradientbrush-setradiisizes) methods. The gradient region is the area inside the dashed lines, and the spread area is the area outside of the gradient region.

![An illustration that shows examples of the spread method](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/XPS_Spread_Method.png)

## See also

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)