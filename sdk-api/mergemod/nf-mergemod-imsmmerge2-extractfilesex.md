# IMsmMerge2::ExtractFilesEx

## Description

The
**ExtractFilesEx** method extracts the embedded .cab file from a module and then writes those files to the destination directory. For more information, see the
[ExtractFilesEx](https://learn.microsoft.com/windows/desktop/Msi/merge-extractfilesex) method of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

## Parameters

### `Path` [in]

The fully qualified destination directory. A **LPCWSTR** may be used in place of a **BSTR**.

### `fLongFileNames` [in]

Set to specify using long file names for path segments and final file names.

### `pFilePaths` [out]

A pointer to a memory location. This memory location receives a second pointer to a string enumerator containing a list of fully qualified paths for the files that were extracted. The list is empty if no files can be extracted. This argument may be null. No list is provided if *pFilePaths* is Null.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **ERROR_CANNOT_MAKE as HRESULT** | Could not create the output path. |
| **ERROR_OPEN_FAILED as HRESULT** | Could not create the output file. |
| **ERROR_WRITE_FAULT as HRESULT** | Could not write data to the output file. |
| **E_FAIL** | Unable to access embedded .cab file, or create temporary file. |
| **S_FALSE** | No embedded .cab file was found. |
| **S_OK** | The function succeeded. |

## Remarks

Any files in the destination directory with the same name are overwritten. The path is created if it does not already exist.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)