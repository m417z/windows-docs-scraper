# MsiSourceListAddMediaDiskA function

## Description

 The **MsiSourceListAddMediaDisk** function adds or updates a disk of the media source of a registered product or patch. If the disk specified already exists, it is updated with the new values. If the disk specified does not exist, a new disk entry is created with the new values.

## Parameters

### `szProductCodeOrPatchCode` [in]

The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) or patch GUID of the product or patch. Use a null-terminated string. If the string is longer than 39 characters, the function fails and returns ERROR_INVALID_PARAMETER. This parameter cannot be **NULL**.

### `szUserSid` [in, optional]

 This parameter can be a string SID that specifies the user account that contains the product or patch. The SID is not validated or resolved. An incorrect SID can return ERROR_UNKNOWN_PRODUCT or ERROR_UNKNOWN_PATCH.

| Type of SID | Meaning |
| --- | --- |
| **NULL** | **NULL** denotes the currently logged on user. When referencing the current user account, *szUserSID* can be **NULL** and *dwContext* can be MSIINSTALLCONTEXT_USERMANAGED or MSIINSTALLCONTEXT_USERUNMANAGED. |
| **User SID** | Specifies enumeration for a particular user in the system. An example of user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |

**Note** The special SID string s-1-5-18 (system) cannot be used to enumerate products or patches installed as per-machine. Setting the SID value to s-1-5-18 returns ERROR_INVALID_PARAMETER. When *dwContext* is set to MSIINSTALLCONTEXT_MACHINE only, *szUserSid* must be **NULL**.

**Note** The special SID string s-1-1-0 (everyone) should not be used. Setting the SID value to s-1-1-0 fails and returns ERROR_INVALID_PARAM .

### `dwContext` [in]

This parameter specifies the context of the product or patch instance. This parameter can contain one of the following values.

| Type of context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | The product or patch instance exists in the per-user-managed context. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | The product or patch instance exists in the per-user-unmanaged context. |
| **MSIINSTALLCONTEXT_MACHINE** | The product or patch instance exists in the per-machine context. |

### `dwOptions` [in]

The *dwOptions* value specifies the meaning of *szProductCodeOrPatchCode*.

| Flag | Meaning |
| --- | --- |
| **MSICODE_PRODUCT** | *szProductCodeOrPatchCode* is a product code GUID. <br><br> |
| **MSICODE_PATCH** | *szProductCodeOrPatchCode* is a patch code GUID. |

### `dwDiskId` [in]

This parameter provides the ID of the disk being added or updated.

### `szVolumeLabel` [in]

The *szVolumeLabel* provides the label of the disk being added or updated. An update overwrites the existing volume label in the registry. To change the disk prompt only, get the existing volume label from the registry and provide it in this call along with the new disk prompt. Passing a **NULL** or empty string for *szVolumeLabel* registers an empty string (0 bytes in length) as the volume label.

### `szDiskPrompt` [in, optional]

On entry to **MsiSourceListAddMediaDisk**, *szDiskPrompt* provides the disk prompt of the disk being added or updated. An update overwrites the registered disk prompt.
To change the volume label only, get the existing disk prompt that is registered and provide it when calling **MsiSourceListAddMediaDisk** along with the new volume label. Passing **NULL** or an empty string registers an empty string (0 bytes in length) as the disk prompt.

## Return value

The **MsiSourceListAddMediaDisk** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have the ability to read the specified media source or the specified product or patch. This does not indicate whether a media source, product or patch was found. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INSTALL_SERVICE_FAILURE** | The Windows Installer service could not be accessed. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The value was successfully reordered. |
| **ERROR_UNKNOWN_PATCH** | The patch was not found. |
| **ERROR_UNKNOWN_PRODUCT** | The product was not found. |
| **ERROR_FUNCTION_FAILED** | Unexpected internal failure. |

## Remarks

Administrators can modify the installation of a product or patch instance that exists under the machine context or under their own per-user context (managed or unmanaged.) They can modify the installation of a product or patch instance that exists under any user's per-user-managed context. Administrators cannot modify another user's installation of a product or patch instance that exists under that other user's per-user-unmanaged context.

Non-administrators cannot modify the installation of a product or patch instance that exists under another user's per-user context (managed or unmanaged.) They can modify the installation of a product or patch instance that exists under their own per-user-unmanaged context. They can modify the installation of a product or patch instance under the machine context or their own per-user-managed context only if they are enabled to browse for a product or patch source. Users can be enabled to browse for sources by setting policy. For more information, see [DisableBrowse](https://learn.microsoft.com/windows/desktop/Msi/disablebrowse), [AllowLockdownBrowse](https://learn.microsoft.com/windows/desktop/Msi/allowlockdownbrowse), [AllowLockDownMedia](https://learn.microsoft.com/windows/desktop/Msi/allowlockdownmedia) and [AlwaysInstallElevated](https://learn.microsoft.com/windows/desktop/Msi/alwaysinstallelevated) policies.

> [!NOTE]
> The msi.h header defines MsiSourceListAddMediaDisk as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)