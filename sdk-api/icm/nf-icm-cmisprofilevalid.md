## Description

Reports whether the given profile is a valid ICC profile that can be used for color management.

## Parameters

### `hProfile`

Specifies the profile to check.

### `lpbValid`

Pointer to a variable that is set on exit to TRUE if the profile is a valid ICC profile, or FALSE if not.

## Return value

If this function succeeds, the return value is TRUE.

If this function fails, the return value is FALSE. If the function fails, the CMM should call **SetLastError** to set the last error to a valid error value defined in Winerror.h.

## Remarks

Only the Windows default CMM is required to export this function; it is optional for all other CMMs.

If a CMM does not support this function, Windows uses the default CMM to validate the profile.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)