# NET_VALIDATE_PASSWORD_RESET_INPUT_ARG structure

## Description

A client application passes the **NET_VALIDATE_PASSWORD_RESET_INPUT_ARG** structure to the [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) function when the application requests a password reset validation.

## Members

### `InputPersistedFields`

Specifies a [NET_VALIDATE_PERSISTED_FIELDS](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_persisted_fields) structure that contains persistent password-related information about the account being logged on.

### `ClearPassword`

Pointer to a Unicode string specifying the new password, in plaintext format.

### `UserAccountName`

Pointer to a Unicode string specifying the name of the user account.

### `HashedPassword`

Specifies a [NET_VALIDATE_PASSWORD_HASH](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_password_hash) structure that contains a hash of the new password.

### `PasswordMustChangeAtNextLogon`

BOOLEAN value that indicates whether the user must change his or her password at the next logon. If this parameter is **TRUE**, the user must change the password at the next logon.

### `ClearLockout`

BOOLEAN value that can reset the "lockout state" of the user account. If this member is **TRUE**, the account will no longer be locked out. Note that an application cannot directly lock out an account. An account can be locked out only as a result of exceeding the maximum number of invalid password authentications allowed for the account.

## See also

[NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)