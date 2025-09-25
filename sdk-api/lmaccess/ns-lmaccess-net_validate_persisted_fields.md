# NET_VALIDATE_PERSISTED_FIELDS structure

## Description

The **NET_VALIDATE_PERSISTED_FIELDS** structure contains information about a user's password properties. Input to and output from the [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) function contain persistent password-related data. When the function outputs this structure, it identifies the persistent data that has changed in this call.

## Members

### `PresentFields`

Type: **ULONG**

A set of bit flags identifying the persistent password-related data that has changed. This member is valid only when this structure is output from the **NetValidatePasswordPolicy** function. This member is ignored when this structure is input to the function. For more information, see the following Remarks section.

| Value | Meaning |
| --- | --- |
| **NET_VALIDATE_PASSWORD_LAST_SET** | The **PasswordLastSet** member contains a new value. |
| **NET_VALIDATE_BAD_PASSWORD_TIME** | The **BadPasswordTime** member contains a new value. |
| **NET_VALIDATE_LOCKOUT_TIME** | The **LockoutTime** member contains a new value. |
| **NET_VALIDATE_BAD_PASSWORD_COUNT** | The **BadPasswordCount** member contains a new value. |
| **NET_VALIDATE_PASSWORD_HISTORY_LENGTH** | The **PasswordHistoryLength** member contains a new value. |
| **NET_VALIDATE_PASSWORD_HISTORY** | The **PasswordHistory** member contains a new value. |

### `PasswordLastSet`

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)**

The date and time (in GMT) when the password for the account was set or last changed.

### `BadPasswordTime`

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)**

The date and time (in GMT) when the user tried to log on to the account using an incorrect password.

### `LockoutTime`

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)**

The date and time (in GMT) when the account was last locked out. If the account has not been locked out, this member is zero. A lockout occurs when the number of bad password logins exceeds the number allowed.

### `BadPasswordCount`

Type: **ULONG**

The number of times the user tried to log on to the account using an incorrect password.

### `PasswordHistoryLength`

Type: **ULONG**

The number of previous passwords saved in the history list for the account. The user cannot reuse a password in the history list.

### `PasswordHistory`

Type: **PNET_VALIDATE_PASSWORD_HASH**

A pointer to a [NET_VALIDATE_PASSWORD_HASH](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_password_hash) structure that contains the password hashes in the history list.

## Remarks

Note that it is the application's responsibility to save all changed persistent data as well as any user object information. The next time the application calls [NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy) on the same instance of the user object, the application must provide the required fields from the persistent information.

The [NET_VALIDATE_AUTHENTICATION_INPUT_ARG](https://learn.microsoft.com/windows/win32/api/lmaccess/ns-lmaccess-net_validate_authentication_input_arg), [NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_password_change_input_arg), [NET_VALIDATE_PASSWORD_RESET_INPUT_ARG](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_password_reset_input_arg), and [NET_VALIDATE_OUTPUT_ARG](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_output_arg) structures contain a **NET_VALIDATE_PERSISTED_FIELDS** structure.

## See also

[NetValidatePasswordPolicy](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicy)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)