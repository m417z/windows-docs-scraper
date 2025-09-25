# NPFMXGetPermHelp function

## Description

Retrieves the help file and help context of the permission editor dialog boxes when a menu item in the **Security** menu of File Manager is selected and F1 is pressed.

## Parameters

### `lpDriveName` [in]

Pointer to the name of the drive currently selected in File Manager.

### `nDialogType` [in]

Specifies the menu item in the **Security** menu of File Manager on which to bring up Help. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WNPERM_DLG_PERM** | Show help on the **Permissions** menu item. |
| **WNPERM_DLG_AUDIT** | Show help on the **Auditing** menu item. |
| **WNPERM_DLG_OWNER** | Show help on the **Owner** menu item. |

### `fDirectory` [in]

Specifies whether the selected item is a directory. This should be set to **TRUE** if the selected item in File Manager is a directory, and **FALSE** if it is a file.

### `lpFileNameBuffer` [in, out]

Pointer to a buffer that will receive the help file name.

### `lpBufferSize` [in, out]

Pointer to a **DWORD** that specifies the size of the buffer passed in. If *lpBuffer* is not large enough, on return, this contains the size of buffer needed.

### `lpnHelpContext` [out]

Pointer to a **DWORD** that will receive the help context for the given *nType*.

## Return value

If the function succeeds, the function should return WN_SUCCESS.

If the function fails, it should call
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set extended error information, which may include the following values.

| Return code | Description |
| --- | --- |
| **WN_NOT_SUPPORTED** | The [NPFMXGetPermHelp](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npfmxgetpermhelp) function is not supported in the provider. |
| **WN_BAD_VALUE** | One or more parameters is an unexpected form or value. |
| **WN_MORE_DATA** | The input buffer is too small. |