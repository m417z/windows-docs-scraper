# NET_VALIDATE_OUTPUT_ARG structure

## Description

The **NET_VALIDATE_OUTPUT_ARG** structure contains information about persistent password-related data that has changed since the user's last logon as well as the result of the function's password validation check.

## Members

### `ChangedPersistedFields`

A structure that contains changes to persistent information about the account being logged on. For more information, see the following Remarks section.

### `ValidationStatus`

The result of the password validation check performed by the [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) function. The status depends on the value specified in the *ValidationType* parameter to that function.

**Authentication.** When you call [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) and specify the *ValidationType* parameter as NetValidateAuthentication, this member can be one of the following values.

| Value | Meaning |
| --- | --- |
| NERR_AccountLockedOut | Validation failed. The account is locked out. |
| NERR_PasswordMustChange | Validation failed. The password must change at the next logon. |
| NERR_PasswordExpired | Validation failed. The password has expired. |
| NERR_BadPassword | Validation failed. The password is invalid. |
| NERR_Success | The password passes the validation check. |

**Password change.** When you call [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) and specify the *ValidationType* parameter as NetValidatePasswordChange, this member can be one of the following values.

| Value | Meaning |
| --- | --- |
| NERR_AccountLockedOut | Validation failed. The account is locked out. |
| NERR_PasswordTooRecent | Validation failed. The password for the user is too recent to change. |
| NERR_BadPassword | Validation failed. The password is invalid. |
| NERR_PasswordHistConflict | Validation failed. The password cannot be used at this time. |
| NERR_PasswordTooShort | Validation failed. The password does not meet policy requirements because it is too short. |
| NERR_PasswordTooLong | Validation failed. The password does not meet policy requirements because it is too long. |
| NERR_PasswordNotComplexEnough | Validation failed. The password does not meet policy requirements because it is not complex enough. |
| NERR_PasswordFilterError | Validation failed. The password does not meet the requirements of the password filter DLL. |
| NERR_Success | The password passes the validation check. |

**Password reset.** When you call **NetValidatePasswordPolicy** and specify the *ValidationType* parameter as NetValidatePasswordReset, this member can be one of the following values.

| Value | Meaning |
| --- | --- |
| NERR_PasswordTooShort | Validation failed. The password does not meet policy requirements because it is too short. |
| NERR_PasswordTooLong | Validation failed. The password does not meet policy requirements because it is too long. |
| NERR_PasswordNotComplexEnough | Validation failed. The password does not meet policy requirements because it is not complex enough. |
| NERR_PasswordFilterError | Validation failed. The password does not meet the requirements of the password filter DLL. |
| NERR_Success | The password passes the validation check. |

## Remarks

The [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) function outputs the **NET_VALIDATE_OUTPUT_ARG** structure.

Note that it is the application's responsibility to save all the data in the **ChangedPersistedFields** member of the **NET_VALIDATE_OUTPUT_ARG** structure as well as any User object information. The next time the application calls [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) on the same instance of the User object, the application must provide the required fields from the persistent information.

## See also

[NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)