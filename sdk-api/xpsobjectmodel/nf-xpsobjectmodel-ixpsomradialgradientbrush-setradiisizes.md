# IXpsOMRadialGradientBrush::SetRadiiSizes

## Description

Sets the sizes of the radii that define ellipse of the radial gradient region.

## Parameters

### `radiiSizes` [in]

The [XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size) structure that receives the sizes of the radii.

| Field | Meaning |
| --- | --- |
| **width** | Size of the radius along the x-axis. |
| **height** | Size of the radius along the y-axis. |

Size is described in XPS units. There are 96 XPS units per inch. For example, a 1" radius is 96 XPS units.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | One of the sizes described by *radiiSizes* is not valid. The [XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size) structure must contain valid, finite, and non-negative floating-point values. |
| **E_POINTER** | *radiiSizes* is **NULL**. |

## Remarks

The following illustration identifies the parts of a radial gradient. *radiiSizes.width* sets the x-radius, and *radiiSizes.height* the y-radius. For a more detailed description of this diagram, see [IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush).

![A figure that shows the terms used in a radial gradient](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/images/RadialGradient1.png)

## See also

[IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_SIZE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ns-xpsobjectmodel-xps_size)