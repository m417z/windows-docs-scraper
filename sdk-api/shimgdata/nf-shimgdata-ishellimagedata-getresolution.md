# IShellImageData::GetResolution

## Description

Gets the resolution, in dots per inch (dpi), of the image.

## Parameters

### `puResolutionX` [out]

Type: **ULONG***

A pointer to the horizontal resolution.

### `puResolutionY` [out]

Type: **ULONG***

A pointer to the vertical resolution.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The image has not been decoded, the decode process failed, or the resolution cannot be retrieved. In the latter case, both *puResolutionX* and *puResolutionY* are set to 0. |
| **E_INVALIDARG** | Both *puResolutionX* and *puResolutionY* are **NULL**. |

## Remarks

If either *puResolutionX* or *puResolutionY* are **NULL**, the method returns only the value for the non-null parameter.