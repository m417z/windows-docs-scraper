## Description

Retrieves information about the International Color Consortium (ICC) named color profile that is specified in the first parameter.

## Parameters

### `hProfile`

The handle to the ICC profile from which the information will be retrieved.

### `pNamedProfileInfo`

A pointer to a **NAMED\_PROFILE\_INFO** structure.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**.

## Remarks

This function will fail if *hProfile* is not a valid ICC profile.

This function does not support Windows Color System (WCS) profiles CAMP, DMP, and GMMP; because named profiles are explicit ICC profile types.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [NAMED\_PROFILE\_INFO](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-named_profile_info)