# WerRemoveExcludedApplication function

## Description

Removes the specified application from the list of applications that are to be excluded by [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER).

## Parameters

### `pwzExeName` [in]

A pointer to a Unicode string that specifies the name of the executable file for the application, including the file name extension. The maximum length of this path is MAX_PATH characters.

This file must have been excluded using the [WerAddExcludedApplication](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-weraddexcludedapplication) function or **WerRemoveExcludedApplication** fails.

### `bAllUsers` [in]

If this parameter is **TRUE**, the application name is removed from the list of excluded applications for all users. Otherwise, it is only removed from the list of excluded applications for the current user.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

|Return code|Description|
|--- |--- |
|**E_ACCESSDENIED**|The process does not have access to update the list in the registry. See the Remarks section for additional information.|

## Remarks

This function removes applications that were added to the excluded applications list using the [WerAddExcludedApplication](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-weraddexcludedapplication) function.

If *bAllUsers* is **TRUE**, the list of excluded applications is stored under the HKEY_LOCAL_MACHINE registry hive. The calling process must have permissions to write to HKLM registry hive.
If *bAllUsers* is **FALSE**, the list of excluded applications is stored under the HKEY_CURRENT_USER registry hive.

## See also

[WerAddExcludedApplication](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-weraddexcludedapplication), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)