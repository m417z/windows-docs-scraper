# IShellImageData::GetDelay

## Description

Gets the delay value for the current frame of an animation.

## Parameters

### `pdwDelay` [out]

Type: **DWORD***

A pointer to the delay value, in milliseconds. This value is valid only when the method returns S_OK.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | The image has not been decoded or the decoding process failed. |

## Remarks

Delay can vary from frame to frame in an animated image.

This method retrieves a minimum value of 100 milliseconds. Values less than that duration are also reported as 100 milliseconds.