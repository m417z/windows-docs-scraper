## Description

Converts color names in a named color space to index numbers in a color profile.

## Parameters

### `hProfile`

The handle to a named color profile.

### `paColorName`

Pointer to an array of color name structures.

### `paIndex`

Pointer to an array of **DWORDS** that this function fills with the indices.

### `dwCount`

The number of color names to convert.

## Return value

If this function succeeds with the conversion, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. When this occurs, the CMM should call **SetLastError** to set the last error to a valid error value defined in Winerror.h.

## Remarks

This function is required in the default CMM. It is optional for all other CMMs.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)