# IXpsOMRadialGradientBrush::GetGradientOrigin

## Description

Gets the origin point of the radial gradient.

## Parameters

### `origin` [out, retval]

The x and y coordinates of the radial gradient's origin point.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *origin* is **NULL**. |

## Remarks

The x and y coordinates that are specified in *origin* are relative to the page and are expressed in units of the transform that is in effect.

The following illustration shows the parts of a radial gradient. *origin* gets the location of the gradient origin. For a more detailed description of this diagram, see [IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush).

![A figure that shows the terms used in a radial gradient](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/RadialGradient1.png)

## See also

[IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point)