# SHEmptyRecycleBinW function

## Description

Empties the Recycle Bin on the specified drive.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to the parent window of any dialog boxes that might be displayed during the operation. This parameter can be **NULL**.

### `pszRootPath` [in, optional]

Type: **LPCTSTR**

The address of a null-terminated string of maximum length MAX_PATH that contains the path of the root drive on which the Recycle Bin is located. This parameter can contain the address of a string formatted with the drive, folder, and subfolder names, for example c:\windows\system\. It can also contain an empty string or **NULL**. If this value is an empty string or **NULL**, all Recycle Bins on all drives will be emptied.

### `dwFlags`

Type: **DWORD**

One or more of the following values.

#### SHERB_NOCONFIRMATION

No dialog box confirming the deletion of the objects will be displayed.

#### SHERB_NOPROGRESSUI

No dialog box indicating the progress will be displayed.

#### SHERB_NOSOUND

No sound will be played when the operation is complete.

##### - dwFlags.SHERB_NOCONFIRMATION

No dialog box confirming the deletion of the objects will be displayed.

##### - dwFlags.SHERB_NOPROGRESSUI

No dialog box indicating the progress will be displayed.

##### - dwFlags.SHERB_NOSOUND

No sound will be played when the operation is complete.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[SHQueryRecycleBin](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shqueryrecyclebina)

## Remarks

> [!NOTE]
> The shellapi.h header defines SHEmptyRecycleBin as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).