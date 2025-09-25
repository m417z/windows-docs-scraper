# MSChapSrvChangePassword2 function

## Description

The
**MSChapSrvChangePassword2** function changes the password of a user account while supporting mutual encryption.

## Parameters

### `ServerName` [in]

A pointer to a null-terminated Unicode string that specifies the Universal Naming Convention (UNC) name of the server on which to operate. If this parameter is **NULL**, the function operates on the local computer.

### `UserName` [in]

A pointer to a null-terminated Unicode string that specifies the name of the user whose password is being changed.

### `NewPasswordEncryptedWithOldNt` [in]

A pointer to a [SAMPR_ENCRYPTED_USER_PASSWORD](https://learn.microsoft.com/windows/desktop/api/mschapp/ns-mschapp-sampr_encrypted_user_password) structure that contains the new clear text password encrypted using the current NT one-way function (OWF) password hash as the encryption key.

**Note** Use the **NewPasswordEncryptedWithOldNtPasswordHash()** function as defined in [RFC 2433](https://www.ietf.org/rfc/rfc2433.txt), section A.11 to calculate the cipher for *NewPasswordEncryptedWithOldNt*.

### `OldNtOwfPasswordEncryptedWithNewNt` [in]

A pointer to an [ENCRYPTED_NT_OWF_PASSWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc325729(v=vs.85)) structure that contains the old NT OWF password hash encrypted using the new NT OWF password hash as the encryption key.

### `LmPresent` [in]

A **BOOLEAN** that specifies if the current Lan Manager (LM) or NT OWF password hashes are used as the encryption keys to generate the *NewPasswordEncryptedWithOldNt* and *OldNtOwfPasswordEncryptedWithNewNt* ciphers. If **TRUE**, the LM OWF password hashes are used rather than the NT OWF password hashes.

### `NewPasswordEncryptedWithOldLm` [in]

A pointer to a [SAMPR_ENCRYPTED_USER_PASSWORD](https://learn.microsoft.com/windows/desktop/api/mschapp/ns-mschapp-sampr_encrypted_user_password) structure that contains the new clear text password encrypted using the current LM OWF password hash.

**Note** Use the **NewPasswordEncryptedWithOldLmPasswordHash()** function as defined in [RFC 2433](https://www.ietf.org/rfc/rfc2433.txt), section A.15 to calculate the cipher for *NewPasswordEncryptedWithOldLm*.

### `OldLmOwfPasswordEncryptedWithNewLmOrNt` [in]

A pointer to a [ENCRYPTED_LM_OWF_PASSWORD](https://learn.microsoft.com/windows/desktop/api/mschapp/ns-mschapp-encrypted_lm_owf_password) structure that contains the current LM OWF password hash encrypted using the new LM OWF password hash.

## Return value

If the function succeeds, the return value is **STATUS_SUCCESS (0x00000000)**.

If the function fails, the return value is one of the following error codes from ntstatus.h.

| Return code/value | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED**<br><br>0xC0000022 | The calling application does not have the appropriate privilege to complete the operation. |
| **STATUS_INVALID_HANDLE**<br><br>0xC0000008 | The specified server or user name was not valid. |
| **STATUS_ILL_FORMED_PASSWORD**<br><br>0xC000006B | New password is poorly formed, for example, it contains characters that cannot be entered from the keyboard. |
| **STATUS_PASSWORD_RESTRICTION**<br><br>0xC000006C | A restriction prevents the password from being changed. Possible restrictions include time restrictions on how often a password is allowed to be changed or length restrictions on the provided password. This error is also returned if the new password matched a password in the recent history log for the account. Security administrators specify how many of the most recently used passwords are not available for re-use. These are kept in the password recent history log. |
| **STATUS_WRONG_PASSWORD**<br><br>0xC000006A | The old password parameter does not match the user's current password. |
| **STATUS_INVALID_DOMAIN_STATE**<br><br>0xC00000DD | The domain controller is not in an enabled state. The domain controller must be enabled for this operation. |
| **STATUS_INVALID_DOMAIN_ROLE**<br><br>0xC00000DE | The domain controller is serving in the incorrect role to perform the requested operation. The operation can only be performed by the primary domain controller. |

## Remarks

This function allows users to change their own passwords only if they have the access: [USER_CHANGE_PASSWORD](https://learn.microsoft.com/windows/win32/adschema/r-user-change-password).

This function fails with **STATUS_PASSWORD_RESTRICTION** if the attempt to change the password conflicts with an administrative password restriction.

## See also

[MS-CHAP Password Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mschap/ms-chap-password-management-functions)

[MSChapSrvChangePassword](https://learn.microsoft.com/previous-versions/windows/desktop/api/mschapp/nf-mschapp-mschapsrvchangepassword)