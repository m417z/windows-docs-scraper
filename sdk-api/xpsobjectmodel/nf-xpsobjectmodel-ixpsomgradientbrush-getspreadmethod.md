# IXpsOMGradientBrush::GetSpreadMethod

## Description

Gets the [XPS_SPREAD_METHOD](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_spread_method) value, which describes how the area outside of the gradient region will be rendered.

## Parameters

### `spreadMethod` [out, retval]

The [XPS_SPREAD_METHOD](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_spread_method) value that describes how the area outside of the gradient region will be rendered. The gradient region is defined by the linear-gradient brush or radial-gradient brush that inherits this interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *spreadMethod* is **NULL**. |

## Remarks

For more information about different types of spread methods, see [XPS_SPREAD_METHOD](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_spread_method).

## See also

[IXpsOMGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientbrush)

[IXpsOMLinearGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomlineargradientbrush)

[IXpsOMRadialGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomradialgradientbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_SPREAD_METHOD](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_spread_method)