## Description

Reports whether a specified International Color Consortium (ICC) tag is present in the specified color profile.

## Parameters

### `hProfile`

Specifies a handle to the ICC profile in question.

### `tag`

Specifies the ICC tag to check.

### `pbPresent`

Pointer to a variable that is set to **TRUE** on return if the specified ICC tag is present, or **FALSE** if not.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

This function will fail if *hProfile* is not a valid ICC profile.

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP; because profile elements are implicitly associated with and hard coded to ICC tag types and there exist many robust XML parsing libraries.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)