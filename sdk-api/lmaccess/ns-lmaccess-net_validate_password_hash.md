# NET_VALIDATE_PASSWORD_HASH structure

## Description

The **NET_VALIDATE_PASSWORD_HASH** structure contains a password hash.

## Members

### `Length`

Specifies the length of this structure.

### `Hash`

Password hash.

## Remarks

The [NET_VALIDATE_PASSWORD_RESET_INPUT_ARG](https://learn.microsoft.com/windows/win32/api/lmaccess/ns-lmaccess-net_validate_password_change_input_arg) and [NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_password_change_input_arg) structures contain a **NET_VALIDATE_PASSWORD_HASH** structure. The [NET_VALIDATE_PERSISTED_FIELDS](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_persisted_fields) structure contains a pointer to this structure.

## See also

[NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)