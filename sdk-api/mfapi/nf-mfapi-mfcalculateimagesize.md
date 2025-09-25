# MFCalculateImageSize function

## Description

Retrieves the image size, in bytes, for an uncompressed video format.

## Parameters

### `guidSubtype` [in]

Media subtype for the video format. For a list of subtypes, see [Media Type GUIDs](https://learn.microsoft.com/windows/desktop/medfound/media-type-guids).

### `unWidth` [in]

Width of the image, in pixels.

### `unHeight` [in]

Height of the image, in pixels.

### `pcbImageSize` [out]

Receives the size of each frame, in bytes. If the format is compressed or is not recognized, the value is zero.

## Return value

The function returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)