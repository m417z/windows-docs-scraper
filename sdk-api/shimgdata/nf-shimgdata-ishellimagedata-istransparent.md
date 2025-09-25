# IShellImageData::IsTransparent

## Description

Determines whether the image is transparent.

## Return value

Type: **HRESULT**

Returns one of the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The image has transparency. |
| **S_FALSE** | The image does not have transparency. |
| **E_FAIL** | The image has not been decoded. |

## Remarks

If an image supports transparency but does not use it, the method returns S_FALSE.