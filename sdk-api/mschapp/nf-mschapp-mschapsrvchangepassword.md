# MSChapSrvChangePassword function

## Description

The
**MSChapSrvChangePassword** function changes the password of a user account.

## Parameters

### `ServerName` [in]

A pointer to a null-terminated Unicode string that specifies the Universal Naming Convention (UNC) name of the server on which to operate. If this parameter is **NULL**, the function operates on the local computer.

### `UserName` [in]

A pointer to a null-terminated Unicode string that specifies the name of the user whose password is being changed.

### `LmOldPresent` [in]

A **BOOLEAN** that specifies whether the password designated by *LmOldOwfPassword* is valid. *LmOldPresent* is **FALSE** if the *LmOldOwfPassword* password is greater than 128-bits in length, and therefore cannot be represented by a Lan Manager (LM) one-way function (OWF) password. Otherwise, it is **TRUE**.

### `LmOldOwfPassword` [in]

A pointer to a [LM_OWF_PASSWORD](https://learn.microsoft.com/windows/desktop/api/mschapp/ns-mschapp-lm_owf_password) structure that contains the OWF of the user's current LM password. This parameter is ignored if *LmOldPresent* is **FALSE**.

### `LmNewOwfPassword` [in]

A pointer to a [LM_OWF_PASSWORD](https://learn.microsoft.com/windows/desktop/api/mschapp/ns-mschapp-lm_owf_password) structure that contains the OWF of the user's new LM password.

### `NtOldOwfPassword` [in]

A pointer to a [NT_OWF_PASSWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc325731(v=vs.85)) structure that contains the OWF of the user's current NT password.

### `NtNewOwfPassword` [in]

A pointer to a [NT_OWF_PASSWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc325731(v=vs.85)) structure that contains the OWF of the user's new NT password.

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
| **STATUS_INVALID_PARAMETER_MIX**<br><br>0xC0000030 | The value of the *LmOldPresent* parameter is not correct for the contents of the old and new parameter pairs. |

## Remarks

The value specified by *LmNewOwfPassword* must always contain a valid OWF. If the new password is greater than 128-bits long, and therefore cannot be represented by a LAN Manager (LM) password, then *LmNewOwfPassword* should be the LM OWF of a **NULL** password.

This function allows users to change their own passwords only if they have the access: [USER_CHANGE_PASSWORD](https://learn.microsoft.com/windows/win32/adschema/r-user-change-password).

This function fails with **STATUS_PASSWORD_RESTRICTION** if the attempt to change the password conflicts with an administrative password restriction.

## See also

[MS-CHAP Password Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mschap/ms-chap-password-management-functions)

[MSChapSrvChangePassword2](https://learn.microsoft.com/previous-versions/windows/desktop/api/mschapp/nf-mschapp-mschapsrvchangepassword2)