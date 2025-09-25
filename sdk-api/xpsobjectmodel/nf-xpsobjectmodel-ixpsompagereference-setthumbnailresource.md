# IXpsOMPageReference::SetThumbnailResource

## Description

Sets the pointer to the [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface of the thumbnail image resource to be assigned to the page.

## Parameters

### `imageResource` [in]

A pointer to the [IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource) interface of the thumbnail image resource to be assigned to the page. If an **IXpsOMImageResource** interface has been set, a **NULL** pointer will release it.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_THUMBNAIL_IMAGE_TYPE** | The image in *imageResource* is not a supported image type. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *imageResource* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

The thumbnail image is a small, visual representation of the document's contents.

The image type of the image resource must be either [XPS_IMAGE_TYPE_JPEG](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_image_type) or **XPS_IMAGE_TYPE_PNG**.

## See also

[IXpsOMImageResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomimageresource)

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[IXpsOMThumbnailGenerator](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomthumbnailgenerator)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_IMAGE_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_image_type)