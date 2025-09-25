# IShellImageData::IsMultipage

## Description

Determines whether the image is a multipage Tagged Image File Format (TIFF) image.

## Return value

Type: **HRESULT**

Returns one of the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The image contains more than one page. |
| **E_FAIL** | The image has only one page, the image has not been decoded, or the decoding process failed. |