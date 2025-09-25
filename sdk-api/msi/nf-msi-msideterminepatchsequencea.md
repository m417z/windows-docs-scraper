# MsiDeterminePatchSequenceA function

## Description

The **MsiDeterminePatchSequence** function takes a set of patch files, XML files, and XML blobs and determines the best sequence of application for the patches to a specified installed product. This function accounts for patches that have already been applied to the product and accounts for obsolete and superseded patches.

## Parameters

### `szProductCode` [in]

The product that is the target for the set of patches. The value must be the [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID for the product.

### `szUserSid` [in, optional]

Null-terminated string that specifies a security identifier (SID) of a user. This parameter restricts the context of enumeration for this user account. This parameter cannot be the special SID strings "S-1-1-0" (everyone) or "S-1-5-18" (local system). For the machine context *dwContext* is set to **MSIINSTALLCONTEXT_MACHINE** and *szUserSid* must be **NULL**.
For the current user context *szUserSid* can be null and *dwContext* can be set to **MSIINSTALLCONTEXT_USERMANAGED** or **MSIINSTALLCONTEXT_USERUNMANAGED**.

### `dwContext` [in]

Restricts the enumeration to a per-user-unmanaged, per-user-managed, or per-machine context. This parameter can be any one of the following values.

| Type of context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | Patches are considered for all per-user-managed installations of the product for the user specified by *szUserSid*. A null *szUserSid* with this context means the current user. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | Patches are considered for all per-user-unmanaged installations for the user specified by *szUserSid*. A null *szUserSid* with this context means the current user. |
| **MSIINSTALLCONTEXT_MACHINE** | Patches are considered for the per-machine installation. When *dwContext* is set to **MSIINSTALLCONTEXT_MACHINE** the *szUserSid* parameter must be null. |

### `cPatchInfo` [in]

The number of patches in the array.

### `pPatchInfo` [in]

Pointer to an array of [MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa) structures.

## Return value

The **MsiDeterminePatchSequence** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_FUNCTION_FAILED** | The function failed in a manner not covered in the other error codes. |
| **ERROR_INVALID_PARAMETER** | An argument is invalid. |
| **ERROR_PATCH_NO_SEQUENCE** | No valid sequence could be found for the set of patches. |
| **ERROR_INSTALL_PACKAGE_OPEN_FAILED** | An installation package referenced by path cannot be opened. |
| **ERROR_SUCCESS** | The patches were successfully sorted. |
| **ERROR_FILE_NOT_FOUND** | The .msi file was not found. |
| **ERROR_PATH_NOT_FOUND** | The path to the .msi file was not found. |
| **ERROR_INVALID_PATCH_XML** | The XML patch data is invalid. |
| **ERROR_INSTALL_PACKAGE_INVALID** | The installation package was invalid. |
| **ERROR_ACCESS_DENIED** | A user that is not an administrator attempted to call the function with a context of a different user. |
| **ERROR_BAD_CONFIGURATION** | The configuration data for a registered patch or product is invalid. |
| **ERROR_UNKNOWN_PRODUCT** | The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID specified is not registered. |
| **ERROR_FUNCTION_NOT_CALLED** | Windows Installer version 3.0 is required to determine the best patch sequence. The function was called with *szProductCode* not yet installed with Windows Installer version 3.0. |
| **ERROR_CALL_NOT_IMPLEMENTED** | This error can be returned if the function was called from a [custom action](https://learn.microsoft.com/windows/desktop/Msi/custom-actions) or if MSXML 3.0 is not installed. |
| **ERROR_UNKNOWN_PATCH** | The specified patch is unknown. |

## Remarks

Users that do not have administrator privileges can call this function only in their own or machine context. Users that are administrators can call it for other users.

If this function is called from a custom action it fails and returns **ERROR_CALL_NOT_IMPLEMENTED**. The function requires MSXML version 3.0 to process XML and returns **ERROR_CALL_NOT_IMPLEMENTED** if MSXML 3.0 is not installed.

The **MsiDeterminePatchSequence** function sets the **uStatus** and **dwOrder** members of each [MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa) structure pointed to by *pPatchInfo*. Each structure contains information about a particular patch.

If the function succeeds, the [MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa) structure of every patch that can be applied to the product returns with a **uStatus** of **ERROR_SUCCESS** and a **dwOrder** greater than or equal to zero. The values of **dwOrder** greater than or equal to zero indicate the best application sequence for the patches starting with zero.

If the function succeeds, patches excluded from the best patching sequence return a [MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa) structure with a **dwOrder** equal to -1. In these cases, a **uStatus** field of **ERROR_SUCCESS** indicates a patch that is obsolete or superseded for the product. A **uStatus** field of **ERROR_PATCH_TARGET_NOT_FOUND** indicates a patch that is inapplicable to the product.

If the function fails, the [MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa) structure for every patch returns a **dwOrder** equal to -1. In this case, the **uStatus** fields can contain errors with more information about individual patches. For example, **ERROR_PATCH_NO_SEQUENCE** is returned for patches that have circular sequencing information.

> [!NOTE]
> The msi.h header defines MsiDeterminePatchSequence as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa)

[MsiDetermineApplicablePatches](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msidetermineapplicablepatchesa)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)