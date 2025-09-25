# MsiGetPatchFileListA function

## Description

The **MsiGetPatchFileList** function is provided a list of .msp files, delimited by semicolons, and retrieves the list of files that can be updated by the patches.

## Parameters

### `szProductCode` [in]

A null-terminated string value containing the [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) (GUID) of the product which is the target of the patches. This parameter cannot be **NULL**.

### `szPatchPackages` [in]

A null-terminated string value that contains the list of Windows Installer patches (.msp files). Each patch can be specified by the full path to the patch package. The patches in the list are delimited by semicolons. At least one patch must be specified.

### `pcFiles` [in, out]

A pointer to a location that receives the number of files that will be updated on this system by this list of patches specified by *szPatchList*. This parameter is required.

### `pphFileRecords` [in, out]

A pointer to a location that receives a pointer to an array of records. The first field (0-index) of each record contains the full file path of a file that can be updated when the list of patches in *szPatchList* are applied on this computer. This parameter is required.

## Return value

The **MsiGetPatchFileList** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_FUNCTION_FAILED** | The function failed. |

## Remarks

For example, *szPatchList* could have the value: "c:\sus\download\cache\Office\sp1.msp; c:\sus\download\cache\Office\QFE1.msp; c:\sus\download\cache\Office\QFEn.msp".

This function runs in the context of the caller. The product code is searched in the order of user-unmanaged context, user-managed context, and machine context.

You must close all MSIHANDLE objects that are returned by this function by calling
the [MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle) function.

If the function fails, you can obtain extended error information by using the [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord) function.

For more information about using the **MsiGetPatchFileList** function see [Listing the Files that can be Updated](https://learn.microsoft.com/windows/desktop/Msi/listing-the-files-that-can-be-updated).

> [!NOTE]
> The msi.h header defines MsiGetPatchFileList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Not Supported in Windows Installer 3.1 and earlier versions](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-3-1)