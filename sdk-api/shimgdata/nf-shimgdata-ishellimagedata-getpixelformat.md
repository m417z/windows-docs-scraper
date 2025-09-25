# IShellImageData::GetPixelFormat

## Description

Gets the pixel format of the image.

## Parameters

### `pFormat` [out]

Type: **PixelFormat***

A pointer to a value of type [PixelFormat](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants) indicating the pixel format. This value is valid only when the method returns **S_OK**.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The image has not been decoded or the decoding process failed. |

## Remarks

Values that identify various pixel formats are defined in Gdipluspixelformats.h.