# NPFMXEditPerm function

## Description

Enables network vendors to supply their own permission editor dialog boxes.

## Parameters

### `lpDriveName` [in]

Pointer to the current drive name selected in File Manager.

### `hwndFMX` [in]

A handle to the FMX window which can be used to query selections.

### `nDialogType` [in]

Specifies the type of permission dialog box to bring up. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WNPERM_DLG_PERM** | Brings up the **Permissions** dialog box. |
| **WNPERM_DLG_AUDIT** | Brings up the **Auditing** dialog box. |
| **WNPERM_DLG_OWNER** | Brings up the **Owner** dialog box. |

## Return value

If the function succeeds, the function should return WN_SUCCESS.

If the function fails, it should call
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) to set extended error information, which may include the following values.

| Return code | Description |
| --- | --- |
| **WN_NOT_SUPPORTED** | [NPFMXEditPerm](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npfmxeditperm) is not supported in the provider. |
| **WN_BAD_VALUE** | Some parameter takes an unexpected form or value. |
| **WN_OUT_OF_MEMORY** | Not enough memory to display the dialog box. |
| **WN_NET_ERROR** | Some other network error occurred. |