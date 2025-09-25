## Description

A client application passes the **NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG** structure to the [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) function when the application requests a password change validation.

## Members

### `InputPersistedFields`

Specifies a [NET_VALIDATE_PERSISTED_FIELDS](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_persisted_fields) structure that contains persistent password-related information about the account being logged on.

### `ClearPassword`

Pointer to a Unicode string specifying the new password, in plaintext format.

### `UserAccountName`

Pointer to a Unicode string specifying the name of the user account.

### `HashedPassword`

Specifies a [NET_VALIDATE_PASSWORD_HASH](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_password_hash) structure that contains a hash of the new password.

### `PasswordMatch`

BOOLEAN value that indicates the result of the application's attempt to validate the old password supplied by the user. If this parameter is **FALSE**, the password was not validated.

## See also

[NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)