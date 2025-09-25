# MsiExtractPatchXMLDataA function

## Description

The **MsiExtractPatchXMLData** function extracts information from a patch that can be used to determine if the patch applies to a target system. The function returns an XML string that can be provided to [MsiDeterminePatchSequence](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msideterminepatchsequencea) and [MsiDetermineApplicablePatches](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msidetermineapplicablepatchesa) instead of the full patch file. The returned information can be used to determine whether the patch is applicable.

## Parameters

### `szPatchPath` [in]

The full path to the patch that is being queried. Pass in as a null-terminated string. This parameter cannot be **NULL**.

### `dwReserved` [in]

A reserved argument that must be 0 (zero).

### `szXMLData` [out, optional]

A pointer to a buffer to hold the XML string that contains the extracted patch information. This buffer should be large enough to contain the received information. If the buffer is too small, the function returns ERROR_MORE_DATA and sets **pcchXMLData* to the number of **TCHAR** in the value, not including the terminating NULL character.

If *szXMLData* is set to **NULL** and *pcchXMLData* is set to a valid pointer, the function returns ERROR_SUCCESS and sets **pcchXMLData* to the number of **TCHAR** in the value, not including the terminating NULL character. The function can then be called again to retrieve the value, with *szXMLData* buffer large enough to contain **pcchXMLData* + 1 characters.

### `pcchXMLData` [in, out, optional]

A pointer to a variable that specifies the number of **TCHAR** in the *szXMLData* buffer. When the function returns, this parameter is set to the size of the requested value whether or not the function copies the value into the specified buffer. The size is returned as the number of **TCHAR** in the requested value, not including the terminating null character.

If this parameter is set to **NULL**, the function returns ERROR_INVALID_PARAMETER.

## Return value

The **MsiExtractPatchXMLData** function can return the following values.

| Return code | Description |
| --- | --- |
| **ERROR_FUNCTION_FAILED** | The function failed in a way that is not identified by any of the return values in this table. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_MORE_DATA** | The value does not fit in the provided buffer. |
| **ERROR_PATCH_OPEN_FAILED** | The patch file could not be opened. |
| **ERROR_SUCCESS** | The function was successful. |
| **ERROR_PATCH_PACKAGE_INVALID** | The patch file could not be opened. |
| **ERROR_CALL_NOT_IMPLEMENTED** | This error can be returned if MSXML 3.0 is not installed. |

## Remarks

The [ExtractPatchXMLData](https://learn.microsoft.com/windows/desktop/Msi/installer-extractpatchxmldata) method of the [Installer](https://learn.microsoft.com/windows/desktop/Msi/installer-object) object uses the **MsiExtractPatchXMLData** function.

> [!NOTE]
> The msi.h header defines MsiExtractPatchXMLData as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MsiDetermineApplicablePatches](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msidetermineapplicablepatchesa)

[MsiDeterminePatchSequence](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msideterminepatchsequencea)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)