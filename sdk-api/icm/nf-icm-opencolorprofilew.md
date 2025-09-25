## Description

Creates a handle to a specified color profile. The handle can then be used in other profile management functions.

## Parameters

### `pProfile`

Pointer to a color profile structure specifying the profile. The *pProfile* pointer can be freed as soon as the handle is created.

### `dwDesiredAccess`

Specifies how to access the given profile. This parameter must take one the following constant values.

| Value | Meaning |
|-|-|
|

**PROFILE\_READ**

| Opens the profile for read access.<br> |
|

**PROFILE\_READWRITE**

| Opens the profile for both read and write access. Has no effect for WCS XML profiles.<br> |

### `dwShareMode`

Specifies how the profile should be shared, if the profile is contained in a file. A value of zero prevents the profile from being shared at all. The parameter can contain one or both of the following constants (combined by addition or logical OR).

| Value | Meaning |
|-|-|
|

**FILE\_SHARE\_READ**

| Other open operations can be performed on the profile for read access.<br> |
|

**FILE\_SHARE\_WRITE**

| Other open operations can be performed on the profile for write access. Has no effect for WCS XML profiles.<br> |

### `dwCreationMode`

Specifies which actions to take on the profile while opening it, if it is contained in a file. This parameter must take one of the following constant values.

| Value | Meaning |
|-|-|
|

**CREATE\_NEW**

| Creates a new profile. Fails if the profile already exists.<br> |
|

**CREATE\_ALWAYS**

| Creates a new profile. Overwrites the profile if it exists.<br> |
|

**OPEN\_EXISTING**

| Opens the profile. Fails if it does not exist<br> |
|

**OPEN\_ALWAYS**

| Opens the profile if it exists. For ICC profiles, if the profile does not exist, creates the profile. For WCS XML profiles, if the profile does not exist, returns an error.<br> |
|

**TRUNCATE\_EXISTING**

| Opens the profile, and truncates it to zero bytes, returning a blank ICC profile. Fails if the profile doesn't exist.<br> |

## Return value

If this function succeeds, the return value is the handle of the color profile that is opened. For ICC and WCS profiles, a CAMP and GMMP are provided by the function based on the current default CAMP and GMMP in the registry.

When OpenColorProfile encounters an ICC profile with an embedded WCS profile, and if the dwType member within the Profile structure does not take the value DONT\_USE\_EMBEDDED\_WCS\_PROFILES, it should extract and use the WCS profile(s) contained in this WcsProfilesTag. The HPROFILE returned would be a WCS HPROFILE.

If this function fails, the return value is **NULL**. For extended error information, call **GetLastError**.

## Remarks

If the profile data is not specified using a file name, *dwShareMode* and *dwCreationMode* are ignored.

*dwCreationMode* flags CREATE\_NEW, CREATE\_ALWAYS, and TRUNCATE\_EXISTING, will always return blank ICC HPROFILEs. If other *dwCreationMode* flags are present, InternalOpenColorProfile is called (using the flags as provided by the API) to determine whether the profile is ICC or WCS XML.

Within the ICC code path, an ICC HPROFILE is returned using the requested sharing, access and creation flags as specified in the tables above.

Within the WCS path, the *dwCreationMode* flag OPEN\_ALWAYS will fail if the profile doesn't exist, since WCS profiles cannot be created or edited within the WCS architecture (they must be edited outside of it, using MSXML6). For the same reason, *dwShareMode* flag FILE\_SHARE\_WRITE, and *dwDesiredAccess* flag PROFILE\_READWRITE are ignored within the WCS path.

When the function opens the ICC profile, it will look for a *WcsProfilesTag* and, if there is one, it will extract and use the original WCS profiles contained therein. (See [**WcsCreateIccProfile**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcscreateiccprofile).)

An HPROFILE with WCS profile information is derived from a DMP by acquiring the default CAMP and default GMMP from the registry. An HPROFILE is a composition of a DMP, CAMP and GMMP.

Once the handle to the color profile is created, any information used to create that handle can be deleted.

Use the [**CloseColorProfile**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-closecolorprofile) function to close an object handle returned by **OpenColorProfile**.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [CloseColorProfile](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-closecolorprofile)
* [PROFILE](https://learn.microsoft.com/windows/win32/api/icm/ns-icm-profile)