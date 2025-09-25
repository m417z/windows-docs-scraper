# WLX_MPR_NOTIFY_INFO structure

## Description

[The WLX_MPR_NOTIFY_INFO structure is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WLX_MPR_NOTIFY_INFO** structure provides identification and authentication information to network providers.

 Your [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL returns this information to Winlogon following a successful authentication. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) is responsible for freeing both the main structure and all strings pointed to from within the structure.

## Members

### `pszUserName`

A pointer to the name of the account logged onto (for example "user_name").

The string pointed to by **pszUserName** must be separately allocated by your GINA DLL. It will be deallocated by Winlogon.

### `pszDomain`

A pointer to the name of the domain used to log on.

The string pointed to by pszDomain must be separately allocated by your GINA DLL. It will be deallocated by Winlogon.

### `pszPassword`

A pointer to the plaintext password of the user account. If **pszOldPassword** is not **NULL**, **pszPassword** contains the new password from a password-change operation.

The string pointed to by **pszPassword** must be separately allocated by your GINA DLL. It will be deallocated by Winlogon.

 For information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `pszOldPassword`

A pointer to the plaintext old password of the user account whose password has just been changed (in this case, *pszPassword* contains the new password).

The string pointed to by **pszOldPassword** must be separately allocated by your GINA DLL. It will be deallocated by Winlogon.