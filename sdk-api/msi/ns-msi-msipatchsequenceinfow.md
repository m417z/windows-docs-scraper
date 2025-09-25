# MSIPATCHSEQUENCEINFOW structure

## Description

The **MSIPATCHSEQUENCEINFO** structure is used by the [MsiDeterminePatchSequence](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msideterminepatchsequencea) and [MsiDetermineApplicablePatches](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msidetermineapplicablepatchesa) functions.

## Members

### `szPatchData`

Pointer to the path of a patch file, an XML blob, or an XML file.

### `ePatchDataType`

Qualifies **szPatchData** as a patch file, an XML blob, or an XML file.

| Value | Meaning |
| --- | --- |
| **MSIPATCH_DATATYPE_PATCHFILE**<br><br>0 | The **szPatchData** member refers to a path of a patch file. |
| **MSIPATCH_DATATYPE_XMLPATH**<br><br>1 | The **szPatchData** member refers to a path of a XML file. |
| **MSIPATCH_DATATYPE_XMLBLOB**<br><br>2 | The **szPatchData** member refers to an XML blob. |

### `dwOrder`

Set to an integer that indicates the sequence of the patch in the order of application. The sequence starts with 0. If a patch is not applicable to the specified .msi file, or if the function fails, **dwOrder** is set to -1.

### `uStatus`

Set to ERROR_SUCCESS or the corresponding Win32 error code.

## See also

[MsiDetermineApplicablePatches](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msidetermineapplicablepatchesa)

[MsiDeterminePatchSequence](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msideterminepatchsequencea)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

## Remarks

> [!NOTE]
> The msi.h header defines MSIPATCHSEQUENCEINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).