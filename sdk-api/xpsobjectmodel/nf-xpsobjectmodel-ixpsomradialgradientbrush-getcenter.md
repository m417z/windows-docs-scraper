# IXpsOMRadialGradientBrush::GetCenter

## Description

Gets the center point of the radial gradient region ellipse.

## Parameters

### `center` [out, retval]

The x and y coordinates of the center point of the radial gradient region ellipse.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *center* is **NULL**. |

## Remarks

The x and y coordinates that are specified in *center* are relative to the page and are expressed in units of the transform that is in effect.

The following illustration shows the parts of a radial gradient. *center* gets the location of the center point of the ellipse that bounds the radial gradient region. For a more detailed description of this diagram, see [IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush).

![A figure that shows the terms used in a radial gradient](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/RadialGradient1.png)

## See also

[IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_POINT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_point)