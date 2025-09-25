# CheckColorsInGamut function

## Description

The **CheckColorsInGamut** function determines whether a specified set of RGB triples lies in the output [gamut](https://learn.microsoft.com/windows/win32/wcs/g) of a specified device. The RGB triples are interpreted in the input logical color space.

## Parameters

### `hdc`

Handle to the device context whose output gamut to be checked.

### `lpRGBTriple`

Pointer to an array of RGB triples to check.

### `dlpBuffer`

Pointer to the buffer in which the results are to be placed. This buffer must be at least as large as *nCount* bytes.

### `nCount`

The number of elements in the array of triples.

## Return value

If this function succeeds, the return value is a nonzero value.

If this function fails, the return value is zero.

## Remarks

The function places the test results in the buffer pointed to by *lpBuffer*. Each byte in the buffer corresponds to an *RGB triple*, and has an unsigned value between CM_IN_GAMUT (= 0) and CM_OUT_OF_GAMUT (= 255). The value 0 denotes that the color is in gamut, while a nonzero value denotes that it is out of gamut. For any integer *n* such that 0 < *n* < 255, a result value of *n* + 1 indicates that the corresponding color is at least as far out of gamut as would be indicated by a result value of *n*, as specified by the ICC Profile Format Specification. For more information on the ICC Profile Format Specification, see the sources listed in [Further information](https://learn.microsoft.com/windows/win32/wcs/further-information)
.

Note that for this function to succeed, WCS must be enabled for the device context handle that is passed in through the *hDC* parameter. WCS can be enabled for a device context handle by calling the [SetICMMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-seticmmode) function.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [SetICMMode](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-seticmmode)