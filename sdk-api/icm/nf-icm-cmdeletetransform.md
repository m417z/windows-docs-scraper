## Description

Deletes a specified color transform, and frees any memory associated with it.

## Parameters

### `hcmTransform`

Identifies the color transform to be deleted.

## Return value

If this function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. If the **CMDeleteTransform** function is not successful, the CMM should call **SetLastError** to set the last error to a valid error value defined in Winerror.h.

## Remarks

Every CMM is required to export this function.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)