# NET_VALIDATE_AUTHENTICATION_INPUT_ARG structure

## Description

A client application passes the **NET_VALIDATE_AUTHENTICATION_INPUT_ARG** structure to the [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) function when the application requests an authentication validation.

## Members

### `InputPersistedFields`

Specifies a [NET_VALIDATE_PERSISTED_FIELDS](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_persisted_fields) structure that contains persistent password-related information about the account being logged on.

### `PasswordMatched`

BOOLEAN value that indicates the result of the client application's authentication of the password supplied by the user. If this parameter is **FALSE**, the password has not been authenticated.

## See also

[NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)