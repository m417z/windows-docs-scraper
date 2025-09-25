## Description

Transforms indices in a color space to an array of names in a named color space.

## Parameters

### `hProfile`

The handle to a color space profile.

### `paIndex`

Pointer to an array of color-space index numbers.

### `paColorName`

Pointer to an array of color name structures.

### `dwCount`

The number of indices to convert.

## Return value

If this conversion function succeeds, the return value is TRUE.

If this function fails, the return value is FALSE. When this occurs, the CMM should call **SetLastError** to set the last error to a valid error value defined in Winerror.h.

## Remarks

This function is required in the default CMM. It is optional for all other CMMs.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)