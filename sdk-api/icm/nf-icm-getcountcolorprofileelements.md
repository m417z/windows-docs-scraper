## Description

Retrieves the number of tagged elements in a given color profile.

## Parameters

### `hProfile`

Specifies a handle to the profile in question.

### `pnElementCount`

Pointer to a variable in which to place the number of tagged elements in the profile.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

This function will fail if *hProfile* is not a valid ICC profile.

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)