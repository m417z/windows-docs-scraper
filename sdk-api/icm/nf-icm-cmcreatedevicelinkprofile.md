## Description

Creates a [device link profile](https://learn.microsoft.com/windows/win32/wcs/d) in the format specified by the International Color Consortium in its ICC Profile Format Specification.

## Parameters

### `pahProfiles`

Pointer to an array of profile handles.

### `nProfiles`

Specifies the number of profiles in the array.

### `padwIntents`

An array of rendering intents.

### `nIntents`

The number of elements in the array of intents.

### `dwFlags`

Specifies flags to used control creation of the transform. For details, see [CMM Transform Creation Flags](https://learn.microsoft.com/windows/win32/wcs/cmm-transform-creation-flags).

### `lpProfileData`

Pointer to a pointer to a buffer. If successful the function allocates and fills this buffer. The calling application must free this buffer when it is no longer needed. Use the **GlobalFree** function to free this buffer.

## Return value

If the function succeeds, the return value is a nonzero value.

If this function fails, the return value is zero. If the function is not successful, the CMM should call **SetLastError** to set the last error to a valid error value defined in Winerror.h.

## Remarks

Only the Windows default CMM is required to export this function; it is optional for all other CMMs.

If a CMM does not support **CMCreateDeviceLinkProfile**, Windows uses the default CMM to create a device link profile.

The first and the last profiles in the array must be [device profiles](https://learn.microsoft.com/windows/win32/wcs/using-device-profiles-with-wcs). The other profiles can be [color space](https://learn.microsoft.com/windows/win32/wcs/color-spaces) or abstract profiles. Each profile's output color space must be the next profile's input color space.

The calling application must free the buffer allocated by this function and pointed to by the *lpProfileData* parameter. Use the [GlobalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalfree) function to free the buffer.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [GlobalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalfree)