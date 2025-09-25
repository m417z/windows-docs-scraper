# IMsmMerge::ExtractFiles

## Description

The
**ExtractFiles** method extracts the embedded .cab file from a module and then writes those files to the destination directory. For more information, see the
[ExtractFiles]() method of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

**IMsmMerge2::ExtractFiles** Mergemod.dll version 2.0 or later.**IMsmMerge::ExtractFiles** All Mergemod.dll versions.

## Parameters

### `Path` [in]

The fully qualified destination directory. A **LPCWSTR** may be used in place of a **BSTR**.

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

**ExtractFiles** always extracts files using short file names for the path. To use long file names for the path, use the
[ExtractFilesEx](https://learn.microsoft.com/windows/desktop/api/mergemod/nf-mergemod-imsmmerge2-extractfilesex) function.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)