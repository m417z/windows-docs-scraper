## Description

Converts a logical [color space](https://learn.microsoft.com/windows/win32/wcs/color-spaces) to a [device profile](https://learn.microsoft.com/windows/win32/wcs/using-device-profiles-with-wcs).

## Parameters

### `pLogColorSpace`

A pointer to a logical color space structure. See [**LOGCOLORSPACEA**](https://learn.microsoft.com/windows/desktop/api/Wingdi/ns-wingdi-logcolorspacea) for details. The **lcsFilename** \[0\] member of the structure must be set to the **null** character ('\\0') or this function call will fail with the return value of INVALID\_PARAMETER.

### `pProfile`

A pointer to a pointer to a buffer where the device profile will be created. This function allocates the buffer and fills it with profile information if it is successful. If not, the pointer is set to **NULL**. The caller is responsible for freeing this buffer when it is no longer needed.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**.

If the **lcsFilename** \[0\] member if the [**LOGCOLORSPACEA**](https://learn.microsoft.com/windows/desktop/api/Wingdi/ns-wingdi-logcolorspacea) structure pointed to by *pLogColorSpace* is not '\\0', this function returns INVALID\_PARAMETER.

## Remarks

This function can be used with ASCII or Unicode strings. The buffer created by this function must be freed by the caller when it is no longer needed or there will be a memory leak. The [GlobalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalfree) function should be used to free this buffer.

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [GlobalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalfree)