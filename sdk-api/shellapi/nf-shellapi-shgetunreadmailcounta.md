# SHGetUnreadMailCountA function

## Description

Retrieves a specified user's unread message count for any or all email accounts.

## Parameters

### `hKeyUser` [in, optional]

Type: **HKEY**

A valid HKEY for a given user. This parameter should be **NULL** if the function is called in a user's environment, in which case **HKEY_CURRENT_USER** is used. This parameter should be **NULL** if the function is called from the SYSTEM context, in which case **HKEY_USERS**\*{SID}* is used.

### `pszMailAddress` [in, optional]

Type: **LPCTSTR**

A pointer to a string in Unicode that specifies the email address of an account belonging to the specified user. When this parameter is **NULL**, *pdwCount* returns the total count of unread messages for all accounts owned by the designated user.

### `pdwCount` [out, optional]

Type: **DWORD***

Pointer to a DWORD value which receives the unread message count.

### `pFileTime` [out, optional]

Type: **FILETIME***

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure. The use of this parameter is determined by whether *pszMailAddress* is **NULL**. If *pszMailAddress* is **NULL**, then this parameter is treated as an [in] parameter, which specifies a filter, so that only unread mail newer than the specified time appears. If *pszMailAddress* is not **NULL**, then this parameter is treated as an [out] parameter, which points to a **FILETIME** structure into which the function places the **timestamp** of the last [SHSetUnreadMailCount](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shsetunreadmailcounta) call for the specified user and email account.

### `pszShellExecuteCommand` [out, optional]

Type: **LPCTSTR**

A pointer to a string that returns the ShellExecute command statement passed into the last [SHSetUnreadMailCount](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shsetunreadmailcounta) call for the specified user and email account. This command string starts the email application that owns the account referenced by *pszMailAddress*. If the ShellExecute command is not required, this parameter can be **NULL**. If *pszMailAddress* is **NULL**, this parameter is ignored and must be **NULL**.

### `cchShellExecuteCommand`

Type: **int**

The maximum size, in characters, of the ShellExecute command buffer pointed to by *pszShellExecuteCommand*. This parameter must be zero for total counts when *pszMailAddress* is **NULL**. It can also be **NULL** whenever the ShellExecute command string is not required.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.