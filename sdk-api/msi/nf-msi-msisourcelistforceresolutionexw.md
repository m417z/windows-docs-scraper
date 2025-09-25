# MsiSourceListForceResolutionExW function

## Description

The **MsiSourceListForceResolutionEx** function removes the registration of the property called "LastUsedSource".
This function does not affect the registered source list. Whenever the installer requires the source to reinstall a product or patch, it first tries the source registered as "LastUsedSource". If that fails, or if that registration is missing, the installer searches the other registered sources until it finds a valid source or until the list of sources is exhausted.
Clearing the "LastUsedSource" registration forces the installer to do a source resolution against the registered sources the next time it requires the source.

## Parameters

### `szProductCodeOrPatchCode` [in]

The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) or patch GUID of the product or patch. Use a null-terminated string. If the string is longer than 39 characters, the function fails and returns ERROR_INVALID_PARAMETER. This parameter cannot be **NULL**.

### `szUserSid` [in, optional]

 This parameter can be a string SID that specifies the user account that contains the product or patch. The SID is not validated or resolved. An incorrect SID can return ERROR_UNKNOWN_PRODUCT or ERROR_UNKNOWN_PATCH. When referencing a machine context, *szUserSID* must be **NULL** and *dwContext* must be MSIINSTALLCONTEXT_MACHINE. Using the machine SID ("S-1-5-18") returns ERROR_INVALID PARAMETER. When referencing the current user account, *szUserSID* can be **NULL** and *dwContext* can be MSIINSTALLCONTEXT_USERMANAGED or MSIINSTALLCONTEXT_USERUNMANAGED.

### `dwContext` [in]

This parameter specifies the context of the product or patch instance. This parameter can contain one of the following values.

| Type of context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | The product or patch instance exists in the per-user-managed context. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | The product or patch instance exists in the per-user-unmanaged context. |
| **MSIINSTALLCONTEXT_MACHINE** | The product or patch instance exists in the per-machine context. |

### `dwOptions` [in]

The *dwOptions* value determines the interpretation of the *szProductCodeOrPatchCode* value .

| Flag | Meaning |
| --- | --- |
| **MSICODE_PRODUCT** | *szProductCodeOrPatchCode* is a product code. <br><br> |
| **MSICODE_PATCH** | *szProductCodeOrPatchCode* is a patch code. |

## Return value

The **MsiSourceListForceResolutionEx** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have the ability to modify the specified source list. Does not indicate whether the product or patch was found. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INSTALL_SERVICE_FAILURE** | Could not access the Windows Installer service |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The "LastUsedSource" registration was cleared. |
| **ERROR_UNKNOWN_PATCH** | The patch was not found. |
| **ERROR_UNKNOWN_PRODUCT** | The specified product or patch was not found. |
| **ERROR_FUNCTION_FAILED** | Unexpected internal failure. |

## Remarks

Administrators can modify the installation of a product or patch instance that exists under the machine context or under their own per-user context (managed or unmanaged.) They can modify the installation of a product or patch instance that exists under any user's per-user-managed context. Administrators cannot modify another user's installation of a product or patch instance that exists under that other user's per-user-unmanaged context.

Non-administrators cannot modify the installation of a product or patch instance that exists under another user's per-user context (managed or unmanaged.) They can modify the installation of a product or patch instance that exists under their own per-user-unmanaged context. They can modify the installation of a product or patch instance under the machine context or their own per-user-managed context only if they are enabled to browse for a product or patch source. Users can be enabled to browse for sources by setting policy, for more information, see [DisableBrowse](https://learn.microsoft.com/windows/desktop/Msi/disablebrowse), [AllowLockdownBrowse](https://learn.microsoft.com/windows/desktop/Msi/allowlockdownbrowse), and [AlwaysInstallElevated](https://learn.microsoft.com/windows/desktop/Msi/alwaysinstallelevated) policies.

> [!NOTE]
> The msi.h header defines MsiSourceListForceResolutionEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

[Source Resiliency](https://learn.microsoft.com/windows/desktop/Msi/source-resiliency)