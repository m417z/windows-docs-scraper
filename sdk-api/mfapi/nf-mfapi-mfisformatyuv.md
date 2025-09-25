# MFIsFormatYUV function

## Description

Queries whether a FOURCC code or **D3DFORMAT** value is a YUV format.

## Parameters

### `Format` [in]

FOURCC code or **D3DFORMAT** value.

## Return value

The function returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The value specifies a YUV format. |
| **FALSE** | The value does not specify a recognized YUV format. |

## Remarks

This function checks whether *Format* specifies a YUV format. Not every YUV format is recognized by this function. However, if a YUV format is not recognized by this function, it is probably not supported for video rendering or DirectX video acceleration (DXVA).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)