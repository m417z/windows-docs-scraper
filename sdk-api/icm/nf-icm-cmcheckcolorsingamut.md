## Description

\[**CMCheckColorsInGamut** is no longer available for use as of Windows Vista.\]

Determines whether specified RGB triples lie in the output [gamut](https://learn.microsoft.com/windows/win32/wcs/g) of a specified transform.

## Parameters

### `hcmTransform`

Specifies the transform to use.

### `lpaRGBTriple`

Points to an array of RGB triples to check.

### `lpaResult`

Points to the buffer in which to put results.
The results are represented by an array of bytes. Each byte in the array corresponds to an RGB triple and has an unsigned value between 0 and 255. The value 0 denotes that the color is in gamut, while a nonzero value denotes that it is out of gamut. For any integer *n* in the range 0 \< *n* \< 255, a result value of *n* + 1 indicates that the corresponding color is at least as far out of gamut as would be indicated by a result value of *n*.

### `nCount`

Specifies the number of elements in the array.

## Return value

Beginning with Windows Vista, the default CMM (Icm32.dll) will return **FALSE** and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will report ERROR\_NOT\_SUPPORTED.

**Windows Server 2003, Windows XP and Windows 2000:**

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. Call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to retrieve the error.

## Remarks

Beginning with Windows Vista, CMM Implementors are no longer required to implement this method.

**Windows Server 2003, Windows XP and Windows 2000:**

CMM Implementors are required to implement this method.

Every CMM is required to export this function.

If the function is not successful, custom CMMs should call [SetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set the last error to a valid error value defined in Winerror.h.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)