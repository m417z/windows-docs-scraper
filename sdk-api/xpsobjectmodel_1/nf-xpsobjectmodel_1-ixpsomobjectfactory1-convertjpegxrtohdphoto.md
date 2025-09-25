# IXpsOMObjectFactory1::ConvertJpegXRToHDPhoto

## Description

Converts an image resource from a JpegXR to an HD Photo.

## Parameters

### `imageResource`

[in, out] The image resource to convert.

When the method returns, the converted image resource.

## Return value

Possible values include, but are not limited to, the following. For information about XPS document API return values that are not listed here, see XPS Document Errors.

S_OK: The method succeeded.

XPS_E_INVALID_CONTENT_TYPE: The image type is not XPS_IMAGE_TYPE_JXR.

E_INVALIDARG if data is not recognized by WDP decoder or another error occurred.

## Remarks

This image referenced by imageResource is changed from an XPS_IMAGE_TYPE_JPEGXR image type to an XPS_IMAGE_TYPE_WDP image type. This method converts the data stream of the image resource;, however, the part name of the resource remains the same.

## See also

[IXpsOMObjectFactory1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsomobjectfactory1)