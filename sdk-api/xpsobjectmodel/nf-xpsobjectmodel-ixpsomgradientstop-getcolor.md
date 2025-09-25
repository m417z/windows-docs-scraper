# IXpsOMGradientStop::GetColor

## Description

Gets the color value and color profile of the gradient stop.

## Parameters

### `color` [out]

The color value of the gradient stop.

### `colorProfile` [out, retval]

A pointer to the [IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource) interface that contains the color profile to be used. If no color profile resource has been set, a **NULL** pointer is returned. See remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *color*, *colorProfile*, or both were **NULL**. |

## Remarks

A color profile is only returned when the color type of *color* is [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type).

## See also

[IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource)

[IXpsOMGradientStop](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientstop)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_COLOR](https://learn.microsoft.com/previous-versions/windows/desktop/dd372939(v=vs.85))