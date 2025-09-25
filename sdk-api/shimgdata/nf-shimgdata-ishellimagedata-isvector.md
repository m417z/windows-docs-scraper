# IShellImageData::IsVector

## Description

Determines whether the image is a vector image.

## Return value

Type: **HRESULT**

Returns one of the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The image is a vector image, supporting the GDI+ flag [ImageFlagsScalable](https://learn.microsoft.com/windows/desktop/api/gdiplusimaging/ne-gdiplusimaging-imageflags). |
| **E_FAIL** | The image has not been decoded, the image is empty, or the file is not an image. |
| **S_FALSE** | All other cases. |