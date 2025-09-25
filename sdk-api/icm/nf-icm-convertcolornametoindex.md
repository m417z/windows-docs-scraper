## Description

Converts color names in a named color space to index numbers in an International Color Consortium (ICC) color profile.

## Parameters

### `hProfile`

The handle to an ICC named color profile.

### `paColorName`

Pointer to an array of color name structures.

### `paIndex`

Pointer to an array of **DWORDS** that this function fills with the indices. The indices begin with one, not zero.

### `dwCount`

The number of color names to convert.

## Return value

If this function succeeds with the conversion, the return value is **TRUE**.

If the conversion function fails, the return value is **FALSE**.

## Remarks

This function will fail if *hProfile* is not a valid ICC profile.

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP; because named profiles are explicit ICC profile types.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)