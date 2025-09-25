# SHSetUnreadMailCountW function

## Description

Stores the current user's unread message count for a specified email account in the registry.

## Parameters

### `pszMailAddress` [in]

Type: **LPCTSTR**

A pointer to a string in Unicode that contains the current user's full email address.

### `dwCount`

Type: **DWORD**

The number of unread messages.

### `pszShellExecuteCommand` [in]

Type: **LPCTSTR**

A pointer to a string in Unicode that contains the full text of a command that can be passed to ShellExecute. This command should start the email application that owns the account referenced by *pszMailAddress*.

## Return value

Type: **HRESULT**

**HRESULT**, which includes the following possible values.

| Return code | Description |
| --- | --- |
| **S_OK** | The call completed successfully. |
| **E_OUTOFMEMORY** | Insufficient memory available. |
| **E_INVALIDARG** | Invalid string argument in either the *pszMailAddress* or *pszShellExecuteCommand* parameters. |

## Remarks

When this function updates the registry, the new registry entry is automatically stamped with the current time and date.

If this function is called by different independent software vendors (ISVs) that specify the same email name, only the last call is saved. That is, calls to this function overwrite any previously saved value for the same email address, even if the calls are made by different ISVs.

It is recommended that the count of unread messages be set only for the main Inbox of the users account. Mail in sub-folders such as Drafts or Deleted Items should be ignored.

It is important that email clients do not set the number of unread messages to 0 when the application exits, because this causes the number of unread messages to be erroneously reported as 0.

Because this function uses HKEY_CURRENT_USER, it should not be called by a system process impersonating a user.