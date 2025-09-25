# IXpsOMImageBrush::SetColorProfileResource

## Description

Sets a pointer to the [IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource) interface, which contains the color profile resource that is associated with the image.

## Parameters

### `colorProfileResource` [in]

The color profile resource that is associated with the image. A **NULL** pointer will release any previously set color profile resources.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *colorProfileResource* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## See also

[IXpsOMColorProfileResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcolorprofileresource)

[IXpsOMImageBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimagebrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))