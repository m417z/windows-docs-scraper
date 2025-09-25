# MsiDetermineApplicablePatchesA function

## Description

The **MsiDetermineApplicablePatches** function takes a set of patch files, XML files, and XML blobs and determines which patches apply to a specified Windows Installer package and in what sequence. The function can account for superseded or obsolete patches. This function does not account for products or patches that are installed on the system that are not specified in the set.

## Parameters

### `szProductPackagePath` [in]

Full path to an .msi file. The function determines the patches that are applicable to this package and in what sequence.

### `cPatchInfo` [in]

Number of patches in the array. Must be greater than zero.

### `pPatchInfo` [in]

Pointer to an array of [MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa) structures.

## Return value

The
**MsiDetermineApplicablePatches** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_FUNCTION_FAILED** | The function failed in a manner not covered in the other error codes. |
| **ERROR_INVALID_PARAMETER** | An argument is invalid. |
| **ERROR_PATCH_NO_SEQUENCE** | No valid sequence could be found for the set of patches. |
| **ERROR_SUCCESS** | The patches were successfully sorted. |
| **ERROR_FILE_NOT_FOUND** | The .msi file was not found. |
| **ERROR_PATH_NOT_FOUND** | The path to the .msi file was not found. |
| **ERROR_INVALID_PATCH_XML** | The XML patch data is invalid. |
| **ERROR_INSTALL_PACKAGE_OPEN_FAILED** | An installation package referenced by path cannot be opened. |
| **ERROR_CALL_NOT_IMPLEMENTED** | This error can be returned if the function was called from a [custom action](https://learn.microsoft.com/windows/desktop/Msi/custom-actions) or if MSXML 3.0 is not installed. |

## Remarks

If this function is called from a custom action it fails and returns ERROR_CALL_NOT_IMPLEMENTED. The function requires MSXML version 3.0 to process XML and returns ERROR_CALL_NOT_IMPLEMENTED if MSXML 3.0 is not installed.

The **MsiDetermineApplicablePatches** function sets the **uStatus** and **dwOrder** members of each [MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa) structure pointed to by *pPatchInfo*. Each structure contains information about a particular patch.

If the function succeeds, the [MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa) structure of every patch that can be applied to the product returns with a **uStatus** of ERROR_SUCCESS and a **dwOrder** greater than or equal to zero. The values of **dwOrder** greater than or equal to zero indicate the best application sequence for the patches starting with zero.

If the function succeeds, patches excluded from the best patching sequence return a [MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa) structure with a **dwOrder** equal to -1. In these cases, a **uStatus** field of ERROR_SUCCESS indicates a patch that is obsolete or superseded for the product. A **uStatus** field of ERROR_PATCH_TARGET_NOT_FOUND indicates a patch that is inapplicable to the product.

If the function fails, the [MSIPATCHSEQUENCEINFO](https://learn.microsoft.com/windows/desktop/api/msi/ns-msi-msipatchsequenceinfoa) structure for every patch returns a **dwOrder** equal to -1. In this case, the **uStatus** fields can contain errors with more information about individual patches. For example, ERROR_PATCH_NO_SEQUENCE is returned for patches that have circular sequencing information.

> [!NOTE]
> The msi.h header defines MsiDetermineApplicablePatches as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MsiDeterminePatchSequence](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msideterminepatchsequencea)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)