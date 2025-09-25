# ID3D11VideoProcessorEnumerator1::CheckVideoProcessorFormatConversion

## Description

Indicates whether the driver supports the specified combination of format and colorspace conversions.

## Parameters

### `InputFormat` [in]

Type: **DXGI_FORMAT**

The format of the video processor input.

### `InputColorSpace` [in]

Type: **DXGI_COLOR_SPACE_TYPE**

The colorspace of the video processor input.

### `OutputFormat` [in]

Type: **DXGI_FORMAT**

The format of the video processor output.

### `OutputColorSpace` [in]

Type: **DXGI_COLOR_SPACE_TYPE**

The colorspace of the video processor output.

### `pSupported` [out]

Type: **BOOL***

Pointer to a boolean that is set by the driver to indicate if the specified combination of format and colorspace conversions is supported. True if the conversion is supported; otherwise, false.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following error codes.

|  |  |
| --- | --- |
| S_OK | The operation completed successfully. |
| E_INVALIDARG | An invalid parameter was passed or this function was called using an invalid calling pattern. |

## See also

[ID3D11VideoProcessorEnumerator1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videoprocessorenumerator1)