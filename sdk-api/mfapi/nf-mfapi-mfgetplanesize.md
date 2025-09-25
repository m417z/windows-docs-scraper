# MFGetPlaneSize function

## Description

Retrieves the image size, in bytes, for an uncompressed video format.

## Parameters

### `format` [in]

FOURCC code or **D3DFORMAT** value that specifies the video format.

### `dwWidth` [in]

Width of the image, in pixels.

### `dwHeight` [in]

Height of the image, in pixels.

### `pdwPlaneSize` [out]

Receives the size of one frame, in bytes. If the format is compressed or is not recognized, this value is zero.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

This function is equivalent to the [MFCalculateImageSize](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcalculateimagesize) function.

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)