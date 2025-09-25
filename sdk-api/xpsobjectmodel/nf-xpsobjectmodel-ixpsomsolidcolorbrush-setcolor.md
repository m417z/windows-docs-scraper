# IXpsOMSolidColorBrush::SetColor

## Description

Sets the color value and color profile of the brush.

## Parameters

### `color` [in]

The color value of the brush.

If the value of the **colorType** field in the [XPS_COLOR](https://learn.microsoft.com/previous-versions/windows/desktop/dd372939(v=vs.85)) structure that is passed in this parameter is [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type), a valid color profile must be provided in the *colorProfile* parameter.

### `colorProfile` [in]

The color profile to be used with *color*.

A color profile is required when the value of the **colorType** field in the [XPS_COLOR](https://learn.microsoft.com/previous-versions/windows/desktop/dd372939(v=vs.85)) structure that is passed in the *color* parameter is [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type). If the value of the **colorType** field is not **XPS_COLOR_TYPE_CONTEXT**, this parameter must be set to **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *color* is **NULL**. |
| **XPS_E_MISSING_COLORPROFILE** | *colorProfile* is **NULL** when a color profile is expected. A color profile is required when the color type is [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type). |
| **XPS_E_UNEXPECTED_COLORPROFILE** | *colorProfile* has a color profile when none is expected. A color profile is only allowed when the color type is [XPS_COLOR_TYPE_CONTEXT](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_color_type). |
| **XPS_E_NO_CUSTOM_OBJECTS** | *colorProfile* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## See also

[IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource)

[IXpsOMSolidColorBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomsolidcolorbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))

[XPS_COLOR](https://learn.microsoft.com/previous-versions/windows/desktop/dd372939(v=vs.85))