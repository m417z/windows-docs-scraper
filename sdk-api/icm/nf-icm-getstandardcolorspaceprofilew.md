## Description

Retrieves the color profile registered for the specified standard [color space](https://learn.microsoft.com/windows/win32/wcs/c#color-space).

## Parameters

### `pMachineName`

Reserved. Must be **NULL**. This parameter is intended to point to the name of the computer on which to get a standard color space profile. A **NULL** pointer indicates the local machine.

### `dwSCS`

Specifies the ID value of the standard color space for which to retrieve the profile. The only valid values for this parameter are LCS\_sRGB and LCS\_WINDOWS\_COLOR\_SPACE.

### `pBuffer`

Pointer to the buffer in which the name of the profile is to be placed. If **NULL**, the call will return **TRUE** and the required size of the buffer is placed in *pdwSize.*

### `pcbSize`

Pointer to a variable containing the size in bytes of the buffer pointed to by *pProfileName*. On return, the variable contains the size of the buffer actually used or needed.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

If the buffer pointed to by *pProfileName* is to be dynamically allocated by an application, the application can call the **GetStandardColorSpaceProfile** function to retrieve the size required for the buffer. If **GetStandardColorSpaceProfile** is called with *pProfileName* set to **NULL**, it will return **FALSE** and the **DWORD** pointed at by *pdwSize* will contain the number of bytes needed for the buffer pointed at by *pProfileName*. The application can then allocate the buffer and call **GetStandardColorSpaceProfile** again with *pProfileName* set to the address of the buffer.

This function supports Windows Color System (WCS) device model profiles (DMPs) in addition to International Color Consortium (ICC) profiles. It does not support WCS CAMP or GMMP profiles and will return an error if such profiles are used.

**Overview of Windows Vista Specific Functionality**

This will support WCS DMPs in addition to ICC profiles. It will not support WCS CAMP or GMMP profiles and will return an error if such profiles are used with this API.

***Per-user/LUA support***

This will retrieve the color profile registered for the given standard color space for current user. If there is no such setting for the current user, it retrieves the system wide setting.

This uses **WcsGetDefaultColorProfile** with WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER.

This is executable in LUA context.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [SetStandardColorSpaceProfile](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-setstandardcolorspaceprofilew)