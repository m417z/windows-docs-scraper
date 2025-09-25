# IShellImageData::IsEditable

## Description

Determines whether the image can be edited.

## Return value

Type: **HRESULT**

Returns one of the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The image can be edited. |
| **S_FALSE** | The image cannot be edited, the image has not been decoded, or the decoding process failed. |

## Remarks

At this time, the criteria for determining whether the image can be edited is solely that it is a Tagged Image File Format (TIFF) image with the Exif IFD tag set.