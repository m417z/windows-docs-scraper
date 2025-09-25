# MsiRemovePatchesA function

## Description

The **MsiRemovePatches** function removes one or more patches from a single product. To remove a patch from multiple products, **MsiRemovePatches** must be called for each product.

## Parameters

### `szPatchList` [in]

A null-terminated string that represents the list of patches to remove. Each patch can be specified by the GUID of the patch or the full path to the patch package. The patches in the list are delimited by semicolons.

### `szProductCode` [in]

A null-terminated string that is the [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) (GUID) of the product from which the patches are removed. This parameter cannot be **NULL**.

### `eUninstallType` [in]

Value that indicates the type of patch removal to perform. This parameter must be **INSTALLTYPE_SINGLE_INSTANCE**.

| Value | Meaning |
| --- | --- |
| **INSTALLTYPE_SINGLE_INSTANCE** | The patch is uninstalled for only the product specified by *szProduct*. |

### `szPropertyList` [in, optional]

A null-terminated string that specifies command-line property settings. For more information see
[About Properties](https://learn.microsoft.com/windows/desktop/Msi/about-properties) and
[Setting Public Property Values on the Command Line](https://learn.microsoft.com/windows/desktop/Msi/setting-public-property-values-on-the-command-line). This parameter can be **NULL**.

## Return value

The **MsiRemovePatches** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was included. |
| **ERROR_PATCH_PACKAGE_OPEN_FAILED** | The patch package could not be opened. |
| **ERROR_SUCCESS** | The patch was successfully removed. |
| **ERROR_UNKNOWN_PRODUCT** | The product specified by *szProductList* is not installed either per-machine or per-user for the caller of [MsiRemovePatches](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiremovepatchesa). |
| **ERROR_PATCH_PACKAGE_OPEN_FAILED** | The patch package could not be opened. |
| **ERROR_PATCH_PACKAGE_INVALID** | The patch package is invalid. |
| **ERROR_PATCH_PACKAGE_UNSUPPORTED** | The patch package cannot be processed by this version of the Windows Installer service. |
| **ERROR_PATCH_REMOVAL_UNSUPPORTED** | The patch package is not removable. |
| **ERROR_UNKNOWN_PATCH** | The patch has not been applied to this product. |
| **ERROR_PATCH_REMOVAL_DISALLOWED** | Patch removal was disallowed by policy. |

## Remarks

See [Uninstalling Patches](https://learn.microsoft.com/windows/desktop/Msi/uninstalling-patches) for an example that demonstrates how an application can remove a patch from all products that are available to the user.

> [!NOTE]
> The msi.h header defines MsiRemovePatches as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[About Properties](https://learn.microsoft.com/windows/desktop/Msi/about-properties)

[MsiApplyPatch](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiapplypatcha)

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

[Removing Patches](https://learn.microsoft.com/windows/desktop/Msi/removing-patches)

[Setting Public Property Values on the Command Line](https://learn.microsoft.com/windows/desktop/Msi/setting-public-property-values-on-the-command-line)

[Uninstalling Patches](https://learn.microsoft.com/windows/desktop/Msi/uninstalling-patches)