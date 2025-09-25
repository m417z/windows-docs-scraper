# SAFER_CODE_PROPERTIES_V2 structure

## Description

The **SAFER_CODE_PROPERTIES** structure contains code image information and criteria to be checked on the code image. An array of **SAFER_CODE_PROPERTIES** structures is passed to the
[SaferIdentifyLevel](https://learn.microsoft.com/windows/desktop/api/winsafer/nf-winsafer-saferidentifylevel) function.

SAFER_CODE_PROPERTIES_V2 is a redefinition of **SAFER_CODE_PROPERTIES** and is an extended version of [SAFER_CODE_PROPERTIES_V1](https://learn.microsoft.com/windows/desktop/api/winsafer/ns-winsafer-safer_code_properties_v1) because it includes new members for Windows Store app packages. Existing binary callers can distinguish which version by checking the **cbSize** member.

## Members

### `cbSize`

The size of this structure in bytes. This is used for future and backward compatibility.

### `dwCheckFlags`

The types of criteria considered when evaluating this structure. Some flags might be silently ignored if some or all of their associated structure elements are not supplied. Specifying zero for this parameter causes the entire structure's contents to be ignored.

The following table shows the possible values. These values may be combined using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **SAFER_CRITERIA_IMAGEPATH**<br><br>0x00001 | Check the code image path. |
| **SAFER_CRITERIA_IMAGEHASH**<br><br>0x00004 | Check the code hash. |
| **SAFER_CRITERIA_AUTHENTICODE**<br><br>0x00008 | Check the Authenticode signature. If this value is used, either the **hImageFileHandle** member or the **ImagePath** member must be set. |
| **SAFER_CRITERIA_URLZONE**<br><br>0x00010 | Check the URL of origin. |
| **SAFER_CRITERIA_IMAGEPATH_NT**<br><br>0x01000 | Check the Windows NT image path. |
| **SAFER_CRITERIA_APPX_PACKAGE**<br><br>0x00020 | Check for a Windows Store app package. For use by Windows Store apps. |

### `ImagePath`

A string specifying the fully qualified path and file name to be used for discrimination checks based on the path. The image path is also used to open and read the file to identify any other discrimination criteria not supplied in this structure. This member can be **NULL**; however, if the **dwCheckFlags** member includes **SAFER_CRITERIA_AUTHENTICODE**, either this member or the **hImageFileHandle** member must be set.

### `hImageFileHandle`

A file handle to a code image with at least GENERIC_READ access. The handle is used instead of explicitly reopening the file to compute discrimination criteria not supplied in this structure. This member can be **NULL**; however, if **dwCheckFlags** includes **SAFER_CRITERIA_AUTHENTICODE**, either this member or the **ImagePath** member must be set.

### `UrlZoneId`

The predetermined Internet Explorer security zones. The following zones are defined:

* URLZONE_LOCAL_MACHINE
* URLZONE_INTRANET
* URLZONE_TRUSTED
* URLZONE_INTERNET
* URLZONE_UNTRUSTED

This member can be set to 0.

### `ImageHash`

The pre-computed hash of the image. The supplied hash is interpreted as valid if both the **ImageSize** member and the **dwImageHashSize** member are nonzero and the **HashAlgorithm** member contains a valid hashing algorithm from Wincrypt.h.

If the supplied hash fails to meet these conditions, the hash will be automatically recomputed by:

* Using the **ImageSize** member and the **pByteBlock** member if both are nonzero.
* Using the **hImageFileHandle** member if it is not **NULL**.
* Opening and using the **ImagePath** member if it is not **NULL**.

### `dwImageHashSize`

The size in bytes of the **ImageHash** member.

### `ImageSize`

The size in bytes of the **pByteBlock** member. This member is not used if the **pByteBlock** member is **NULL**.

### `HashAlgorithm`

The hash algorithm used to create the **ImageHash** member.

### `pByteBlock`

The memory block containing the image of the code being checked. This member is optional. If this member is specified, the **ImageSize** member must also be supplied.

### `hWndParent`

The arguments used for Authenticode signer certificate verification. These arguments are passed to the [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) function and control the user interface (UI) that prompts the user to accept or reject entrusted certificates.

### `dwWVTUIChoice`

Indicates the type of UI used. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| WTD_UI_ALL | Display all UI. |
| WTD_UI_NONE | Display no UI. |
| WTD_UI_NOBAD | Display UI only if there were no errors. |
| WTD_UI_NOGOOD | Display UI only if an error occurs. |

### `PackageMoniker`

The package moniker property. For use by Windows Store apps.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not available.

### `PackagePublisher`

The package publisher property. For use by Windows Store apps.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not available.

### `PackageName`

The package name property. For use by Windows Store apps.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not available.

### `PackageVersion`

The package version property. For use by Windows Store apps.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not available.

### `PackageIsFramework`

The package is a framework package. For use by Windows Store apps.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This member is not available.