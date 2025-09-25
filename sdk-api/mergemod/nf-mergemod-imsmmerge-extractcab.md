# IMsmMerge::ExtractCAB

## Description

The
**ExtractCAB** method extracts the embedded .cab file from a module and saves it as the specified file. The installer creates this file if it does not already exist and overwrites the file if it does exist. For more information, see the
[ExtractCAB](https://learn.microsoft.com/windows/desktop/Msi/merge-extractcab) method of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

**IMsmMerge2::ExtractCAB** Mergemod.dll version 2.0 or later.**IMsmMerge::ExtractCAB** All Mergemod.dll versions.

## Parameters

### `FileName` [in]

The fully qualified destination file. A **LPCWSTR** may be used in place of a **BSTR**.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **ERROR_OPEN_FAILED as HRESULT** | Could not create the output file. |
| **ERROR_WRITE_FAULT as HRESULT** | Could not write data to the output file. |
| **E_FAIL** | Unable to access embedded .cab file. |
| **S_FALSE** | No embedded .cab file was found. |
| **S_OK** | The function succeeded. |

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)