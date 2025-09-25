## Description

Allows you to determine whether the specified profile is a valid International Color Consortium (ICC) profile, or a valid Windows Color System (WCS) profile handle that can be used for color management. WCS profile validation doesn't invoke the underlying device models, but instead simply validates against the XML schema and the schema element range limits.

## Parameters

### `hProfile`

Specifies a handle to the profile to be validated. The function determines whether the HPROFILE contains ICC or WCS profile information.

### `pbValid`

Pointer to a variable that is set to **TRUE** on return if the operation succeeds and the profile is a valid ICC or WCS profile. If the operation fails or the profile is not valid the variable is **FALSE**.

## Return value

If this function succeeds and the profile is valid, the return value is **TRUE**.

If this function fails (or succeeds and the profile is not valid), the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)