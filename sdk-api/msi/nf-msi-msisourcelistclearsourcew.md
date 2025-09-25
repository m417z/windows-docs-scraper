# MsiSourceListClearSourceW function

## Description

The **MsiSourceListClearSource** function removes an existing source for a product or patch in a specified context. The patch registration is also removed if the sole source of the patch gets removed and if the patch is not installed by any client in the same context. Specifying that **MsiSourceListClearSource** remove the current source for this product or patch forces the installer to search the source list for a source the next time a source is required.

## Parameters

### `szProductCodeOrPatchCode` [in]

The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) or patch GUID of the product or patch. Use a null-terminated string. If the string is longer than 39 characters, the function fails and returns **ERROR_INVALID_PARAMETER**. This parameter cannot be **NULL**.

### `szUserSid` [in, optional]

This parameter can be a string SID that specifies the user account that contains the product or patch. The SID is not validated or resolved. An incorrect SID can return **ERROR_UNKNOWN_PRODUCT** or **ERROR_UNKNOWN_PATCH**. When referencing a machine context, *szUserSID* must be **NULL** and *dwContext* must be **MSIINSTALLCONTEXT_MACHINE**.

| Type of SID | Meaning |
| --- | --- |
| ****NULL**** | **NULL** denotes the currently logged on user. When referencing the current user account, *szUserSID* can be **NULL** and *dwContext* can be **MSIINSTALLCONTEXT_USERMANAGED** or **MSIINSTALLCONTEXT_USERUNMANAGED**. |
| **User SID** | Specifies enumeration for a particular user in the system. An example of a user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |

**Note** The special SID string "S-1-5-18" (system) cannot be used to enumerate products or patches installed as per-machine. Setting the SID value to "S-1-5-18" returns **ERROR_INVALID_PARAMETER**.

**Note** The special SID string "S-1-1-0" (everyone) should not be used. Setting the SID value to "S-1-1-0" fails and returns **ERROR_INVALID_PARAM**.

### `dwContext` [in]

This parameter specifies the context of the product or patch instance. This parameter can contain one of the following values.

| Type of context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | The product or patch instance exists in the per-user-managed context. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | The product or patch instance exists in the per-user-unmanaged context. |
| **MSIINSTALLCONTEXT_MACHINE** | The product or patch instance exists in the per-machine context. |

### `dwOptions` [in]

The *dwOptions* value determines the interpretation of the *szProductCodeOrPatchCode* value and the type of sources to clear. This parameter must be a combination of one of the following **MSISOURCETYPE_*** constants and one of the following **MSICODE_*** constants.

| Flag | Meaning |
| --- | --- |
| **MSISOURCETYPE_NETWORK** | The source is a network type. |
| **MSISOURCETYPE_URL** | The source is a URL type. |
| **MSICODE_PRODUCT** | *szProductCodeOrPatchCode* is a product code. |
| **MSICODE_PATCH** | *szProductCodeOrPatchCode* is a patch code. |

### `szSource` [in]

Source to remove. This parameter is expected to contain only the path without the filename.
The filename is already registered as "PackageName" and can be manipulated through [MsiSourceListSetInfo](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisourcelistsetinfoa). This argument is required.

## Return value

The **MsiSourceListClearSource** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have the ability to remove a source. Does not indicate whether the product or patch was found. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INSTALL_SERVICE_FAILURE** | Could not access the Windows Installer service |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The source was removed or not found. |
| **ERROR_UNKNOWN_PATCH** | The specified patch is unknown. |
| **ERROR_UNKNOWN_PRODUCT** | The specified product is unknown. |
| **ERROR_FUNCTION_FAILED** | Unexpected internal failure. |

## Remarks

Administrators can modify the installation of a product or patch instance that exists under the machine context or under their own per-user context (managed or unmanaged.) They can modify the installation of a product or patch instance that exists under any user's per-user-managed context. Administrators cannot modify another user's installation of a product or patch instance that exists under that other user's per-user-unmanaged context.

Non-administrators cannot modify the installation of a product or patch instance that exists under another user's per-user context (managed or unmanaged.) They can modify the installation of a product or patch instance that exists under their own per-user-unmanaged context. They can modify the installation of a product or patch instance under the machine context or their own per-user-managed context only if they are enabled to browse for a product or patch source. Users can be enabled to browse for sources by setting policy. For more information, see the [DisableBrowse](https://learn.microsoft.com/windows/desktop/Msi/disablebrowse), [AllowLockdownBrowse](https://learn.microsoft.com/windows/desktop/Msi/allowlockdownbrowse), and [AlwaysInstallElevated](https://learn.microsoft.com/windows/desktop/Msi/alwaysinstallelevated) policies.

> [!NOTE]
> The msi.h header defines MsiSourceListClearSource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AllowLockdownBrowse](https://learn.microsoft.com/windows/desktop/Msi/allowlockdownbrowse)

[AlwaysInstallElevated](https://learn.microsoft.com/windows/desktop/Msi/alwaysinstallelevated)

[DisableBrowse](https://learn.microsoft.com/windows/desktop/Msi/disablebrowse)

[MsiSourceListSetInfo](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisourcelistsetinfoa)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

[Source Resiliency](https://learn.microsoft.com/windows/desktop/Msi/source-resiliency)