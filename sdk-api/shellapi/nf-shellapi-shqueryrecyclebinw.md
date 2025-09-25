# SHQueryRecycleBinW function

## Description

Retrieves the size of the Recycle Bin and the number of items in it, for a specified drive.

## Parameters

### `pszRootPath` [in, optional]

Type: **LPCTSTR**

The address of a **null**-terminated string of maximum length MAX_PATH to contain the path of the root drive on which the Recycle Bin is located. This parameter can contain the address of a string formatted with the drive, folder, and subfolder names (C:\Windows\System...).

### `pSHQueryRBInfo` [in, out]

Type: **LPSHQUERYRBINFO**

The address of a [SHQUERYRBINFO](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-shqueryrbinfo) structure that receives the Recycle Bin information. The **cbSize** member of the structure must be set to the size of the structure before calling this API.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

With Windows 2000, if **NULL** is passed in the *pszRootPath* parameter, the function fails and returns an E_INVALIDARG error code. In earlier versions of the operating system, you can pass an empty string or **NULL**. If *pszRootPath* contains an empty string or **NULL**, information is retrieved for all Recycle Bins on all drives.

> [!NOTE]
> The shellapi.h header defines SHQueryRecycleBin as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SHEmptyRecycleBin](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shemptyrecyclebina)