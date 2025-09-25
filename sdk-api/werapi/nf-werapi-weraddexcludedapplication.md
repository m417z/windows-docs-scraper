# WerAddExcludedApplication function

## Description

Adds the specified application to the list of applications that are to be excluded from [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER).

## Parameters

### `pwzExeName` [in]

A pointer to a Unicode string that specifies the name of the executable file for the application, including the file name extension. The maximum length of this path is MAX_PATH characters.

### `bAllUsers` [in]

If this parameter is **TRUE**, the application name is added to the list of excluded applications for all users. Otherwise, it is only added to the list of excluded applications for the current user.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error code.

| Return code | Description |
| ----------- | ----------- |
| **E_ACCESSDENIED** | The process does not have permissions to update the list in the registry. See the Remarks section for additional information. |

## Remarks

If *bAllUsers* is **TRUE**, the list of excluded applications is stored under the HKEY_LOCAL_MACHINE registry hive. The calling process must have permissions to write to the HKLM registry hive.

If *bAllUsers* is **FALSE**, the list of excluded applications is stored under the HKEY_CURRENT_USER registry hive.

To remove the application from the list of excluded applications, call the [WerRemoveExcludedApplication](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werremoveexcludedapplication) function.

## See also

[WerRemoveExcludedApplication](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werremoveexcludedapplication), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)