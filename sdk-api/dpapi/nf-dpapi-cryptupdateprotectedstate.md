# CryptUpdateProtectedState function

## Description

The **CryptUpdateProtectedState** function migrates the current user's master keys after the user's [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) has changed. This function can be used to preserve encrypted data after a user has been moved from one domain to another.

## Parameters

### `pOldSid` [in]

The address of a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that contains the user's previous SID. This SID is used to locate the old master keys. If this parameter is **NULL**, the master keys for the current user SID are migrated.

Either this parameter or the *pwszOldPassword* parameter may be **NULL**, but not both.

### `pwszOldPassword` [in]

A pointer to a null-terminated Unicode string that contains the user's password before the SID was changed. This password is used to decrypt the old master keys. If this parameter is **NULL**, the password of the current user will be used.

Either this parameter or the *pOldSid* parameter may be **NULL**, but not both.

### `dwFlags` [in]

Not used. Must be zero.

### `pdwSuccessCount` [out]

The address of a **DWORD** variable that receives the number of master keys that were successfully migrated.

### `pdwFailureCount` [out]

The address of a **DWORD** variable that receives the number of master keys that could not be decrypted.

It is not necessarily an error if one or more master keys cannot be decrypted. Some users may possess master keys that are stagnant and could not have been decrypted for a long time. One way that this can happen is when the password of a local user has been administratively reset.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters contains a value that is not valid. |
| **ERROR_OUTOFMEMORY** | A memory allocation failure occurred. |
| **ERROR_ENCRYPTION_FAILED** | The old password could not be encrypted. |

## Remarks

This function decrypts all of the user's master keys in the old master key directory, using the previous password, and stores them in the user's current master key directory, encrypted with the user's current password.

 This function must be called from the user account that the keys are being migrated to.

If this function is able to successfully migrate an old master key, it will automatically delete the old master key.
Master keys that cannot be decrypted are not deleted.