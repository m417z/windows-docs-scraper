## Description

Creates an International Color Consortium (ICC) *device link profile* from a set of color profiles, using the specified intents.

## Parameters

### `hProfile`

Pointer to an array of handles of the color profiles to be used. The function determines whether the HPROFILEs contain ICC profile information and, if so, it processes them appropriately.

### `nProfiles`

Specifies the number of profiles in the array pointed to by *hProfile*.

### `padwIntent`

Pointer to an array of **DWORDS** containing the intents to be used. See [Rendering intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

### `nIntents`

The number of intents in the array pointed to by *padwIntent*.

### `dwFlags`

Specifies flags to used control creation of the transform. For details, see [CMM Transform Creation Flags](https://learn.microsoft.com/windows/win32/wcs/cmm-transform-creation-flags).

### `pProfileData`

Pointer to a pointer to a buffer. If successful, this function allocates the buffer, places its address in *\*pProfileData*, and fills it with a device link profile. If the function succeeds, the calling application must free the buffer after it is no longer needed.

### `indexPreferredCMM`

Specifies the one-based index of the color profile that indicates what color management module (CMM) to use. The application developer may allow Windows to choose the CMM by setting this parameter to INDEX\_DONT\_CARE. See [Using Color Management Modules (CMM)](https://learn.microsoft.com/windows/win32/wcs/using-color-management-modules--cmm).

## Return value

If this function succeeds, the return value is a nonzero value.

If this function fails, the return value is zero. For extended error information, call GetLastError.

## Remarks

For HPROFILEs that contain WCS profile information, the HPROFILEs are converted into valid ICC profile handles and then these ICC profile handles are used in creating the device link profile.

The first and the last profiles in the array must be device profiles. The other profiles can be color space or abstract profiles.

Each profile's output color space must be the next profile's input color space.

The calling application must free the buffer allocated by this function and pointed to by the *pProfileData* parameter. The [**GlobalFree**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalfree) function should be used to free the buffer.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [GlobalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-globalfree)