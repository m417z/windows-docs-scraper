# IXpsOMObjectFactory1::ConvertHDPhotoToJpegXR

## Description

Converts an image resource from an HD Photo to a JpegXR.

## Parameters

### `imageResource`

[in, out] The image resource to convert.

When the method returns, the converted image resource.

## Return value

Possible values include, but are not limited to, the following. For information about XPS document API return values that are not listed here, see XPS Document Errors.

S_OK: The method succeeded.

XPS_E_INVALID_CONTENT_TYPE: The image type is not XPS_IMAGE_TYPE_WDP.

 E_INVALIDARG: The image resource is not recognized by the WDP decoder or another general error occurred.

## Remarks

This image referenced by imageResource is changed from an XPS_IMAGE_TYPE_WDP image type to an XPS_IMAGE_TYPE_JPEGXR image type. This method converts the data stream of the image resource;, however, the part name of the resource remains the same.

## See also

[IXpsOMObjectFactory1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsomobjectfactory1)