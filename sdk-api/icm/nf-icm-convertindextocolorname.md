## Description

Transforms indices in a color space to an array of names in a named color space.

## Parameters

### `hProfile`

The handle to an International Color Consortium (ICC) color space profile.

### `paIndex`

Pointer to an array of color-space index numbers. The indices begin with one, not zero.

### `paColorName`

Pointer to an array of color name structures.

### `dwCount`

The number of indices to convert.

## Return value

If this conversion function succeeds, the return value is **TRUE**.

If this conversion function fails, the return value is **FALSE**.

## Remarks

This function will fail if *hProfile* is not a valid ICC profile.

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP; because named profiles are explicit ICC profile types.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)