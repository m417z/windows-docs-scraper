# IXpsOMSolidColorBrush::GetColor

## Description

Gets the color value and color profile of the brush.

## Parameters

### `color` [out]

The color value of the brush.

### `colorProfile` [out, retval]

The color profile of the brush.

If no color profile has been specified for the brush, a **NULL** pointer is returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *color*, *colorProfile*, or both are **NULL**. |

## See also

[IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource)

[IXpsOMSolidColorBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsolidcolorbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_COLOR](https://learn.microsoft.com/previous-versions/windows/desktop/dd372939(v=vs.85))