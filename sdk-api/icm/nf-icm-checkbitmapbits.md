## Description

Checks whether the pixels in a specified bitmap lie within the output [gamut](https://learn.microsoft.com/windows/win32/wcs/g) of a specified transform.

## Parameters

### `hColorTransform`

Handle to the color transform to use.

### `pSrcBits`

Pointer to the bitmap to check against the output gamut.

### `bmInput`

Specifies the format of the bitmap. Must be set to one of the values of the [**BMFORMAT**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-bmformat) enumerated type.

### `dwWidth`

Specifies the number of pixels per scan line of the bitmap.

### `dwHeight`

Specifies the number of scan lines of the bitmap.

### `dwStride`

Specifies the number of bytes from the beginning one scan line to the beginning of the next one. If set to zero, the bitmap scan lines are assumed to be padded so as to be **DWORD**-aligned.

### `paResult`

Pointer to an array of bytes where the test results are to be placed. This results buffer must contain at least as many bytes as there are pixels in the bitmap.

### `pfnCallback`

Pointer to a callback function called periodically by **CheckBitmapBits** to report progress and allow the calling process to cancel the bitmap test. (See [**ICMProgressProcCallback**](https://learn.microsoft.com/windows/win32/wcs/icmprogressproccallback)).

### `lpCallbackData`

Data passed back to the callback function, for example, to identify the bitmap test about which progress is being reported.

## Return value

If this function succeeds, the return value is a nonzero value.

If this function fails, the return value is zero. For extended error information, call **GetLastError**.

## Remarks

If the input format is not compatible with the color transform, the **CheckBitmapBits** function fails.

This function places results of the tests in the buffer pointed to by *paResult*. Each byte in the buffer corresponds to a pixel in the bitmap, and has an unsigned value between 0 and 255. The value 0 denotes that the color is in gamut, while a nonzero value denotes that it is out of gamut. For any integer *n* such that 0 <*n* < 255, a result value of *n* + 1 indicates that the corresponding color is at least as far out of gamut as would be indicated by a result value of *n*.

When either of the floating point BMFORMATs, BM\_32b\_scARGB or BM\_32b\_scRGB is used, the color data being checked should not contain NaN or infinity. NaN and infinity are not considered to represent legitimate color component values, and the result of checking pixels containing NaN or infinity is meaningless in color terms. NaN or infinity values in the color data being processed will be handled silently, and an error will not be returned.

The out-of-gamut information in the gamut tags created in WCS use the perceptual color distance in CIECAM02, which is the mean square root in CIECAM02 Jab space. The distance in the legacy ICC profile gamut tags is the mean square root in CIELAB space. We recommend that you use the CIECAM02 space when it is available because it provides more perceptually accurate distance metrics.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [ICMProgressProcCallback](https://learn.microsoft.com/windows/win32/wcs/icmprogressproccallback)
* [BMFORMAT](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-bmformat)