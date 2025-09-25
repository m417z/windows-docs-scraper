# MsiApplyMultiplePatchesW function

## Description

The **MsiApplyMultiplePatches** function applies one or more patches to products eligible to receive the patches.
The **MsiApplyMultiplePatches** function sets the [PATCH](https://learn.microsoft.com/windows/desktop/Msi/patch) property with a list of patches delimited by semicolons and invokes the patching of the target products. Other properties can be set using a properties list.

## Parameters

### `szPatchPackages` [in]

A semicolon-delimited list of the paths to patch files as a single string. For example: ""c:\sus\download\cache\Office\sp1.msp; c:\sus\download\cache\Office\QFE1.msp; c:\sus\download\cache\Office\QFEn.msp" "

### `szProductCode` [in, optional]

This parameter is the [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID of the product to be patched. The user or application calling **MsiApplyMultiplePatches** must have privileges to apply patches. When this parameter is **NULL**, the patches are applied to all eligible products. When this parameter is non-**NULL**, the patches are applied only to the specified product.

### `szPropertiesList` [in, optional]

A null-terminated string that specifies command–line property settings used during the patching of products. If there are no command–line property settings, pass in a **NULL** pointer. An empty string is an invalid parameter. These properties are shared by all target products. For more information, see
[About Properties](https://learn.microsoft.com/windows/desktop/Msi/about-properties) and
[Setting Public Property Values on the Command Line](https://learn.microsoft.com/windows/desktop/Msi/setting-public-property-values-on-the-command-line).

**Note** The properties list should not contain the [PATCH](https://learn.microsoft.com/windows/desktop/Msi/patch) property. If the **PATCH** property is set in the command line the value is ignored and is overwritten with the patches being applied.

## Return value

The **MsiApplyMultiplePatches** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Some arguments passed in are incorrect or contradicting. |
| **ERROR_SUCCESS** | The function completed and all products are successfully patched. **ERROR_SUCCESS** is returned only if all the products eligible for the patches are patched successfully. If none of the new patches are applicable, [MsiApplyMultiplePatches](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiapplymultiplepatchesa) returns **ERROR_SUCCESS** and product state remains unchanged. |
| **ERROR_SUCCESS_REBOOT_INITIATED** | The restart initiated by the last transaction terminated this call to [MsiApplyMultiplePatches](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiapplymultiplepatchesa). All the target products may not have been patched. |
| **ERROR_SUCCESS_REBOOT_REQUIRED** | The restart required by the last transaction terminated this call to [MsiApplyMultiplePatches](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiapplymultiplepatchesa). All target products may not have been patched. |
| **ERROR_PATCH_PACKAGE_OPEN_FAILED** | One of the patch packages provide could not be opened. |
| **ERROR_PATCH_PACKAGE_INVALID** | One of the patch packages provide is not a valid one. |
| **ERROR_PATCH_PACKAGE_UNSUPPORTED** | One of the patch packages is unsupported. |
| **Any error in Winerror.h** | Implies possible partial completion or that one or more transactions failed. |

## See also

[About Properties](https://learn.microsoft.com/windows/desktop/Msi/about-properties)

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[PATCH](https://learn.microsoft.com/windows/desktop/Msi/patch)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

[Setting Public Property Values on the Command Line](https://learn.microsoft.com/windows/desktop/Msi/setting-public-property-values-on-the-command-line)

## Remarks

> [!NOTE]
> The msi.h header defines MsiApplyMultiplePatches as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).