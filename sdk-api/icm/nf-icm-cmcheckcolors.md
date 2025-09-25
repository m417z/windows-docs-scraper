## Description

Determines whether given colors lie within the output [gamut](https://learn.microsoft.com/windows/win32/wcs/g) of a specified transform.

## Parameters

### `hcmTransform`

Handle to the color transform to use.

### `lpaInputColors`

Pointer to an array of [**COLOR**](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-color) structures to check against the output gamut.

### `nColors`

Specifies the number of elements in the array.

### `ctInput`

Specifies the input color type.

### `lpaResult`

Pointer to a buffer in which to place an array of bytes containing the test results. Each byte in the buffer corresponds to a **COLOR** structure, and on exit has been set to an unsigned value between 0 and 255. The value 0 denotes that the color is in gamut, while a nonzero value indicates that it is out of gamut. For any integer *n* such that 0 \< *n* \< 255, a result value of *n* + 1 indicates that the corresponding color is at least as far out of gamut as would be indicated by a result value of *n*. These values are usually generated from the *gamutTag* in the ICC profile.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. If the function is not successful, the CMM should call [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set the last error to a valid error value defined in Winerror.h.

## Remarks

Every CMM is required to export this function.

If the input color type is not compatible with the color transform **CMCheckColors** fails.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)