# RAS_USER_1 structure

## Description

The
**RAS_USER_1** structure contains information for a particular Remote Access Service user. The
**RAS_USER_1** structure is similar to the
[RAS_USER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_user_0) structure, except that
**RAS_USER_1** supports an additional member, **bfPrivilege2**.

## Members

### `bfPrivilege`

Specifies the types of remote access privilege available to the RAS user.

The following remote access privilege constants are defined in Mprapi.h.

| Value | Meaning |
| --- | --- |
| **RASPRIV_DialinPrivilege** | The user has permission to dial in to the RAS server. |
| **RASPRIV_NoCallback** | The RAS server will not call back the user to establish a connection. |
| **RASPRIV_AdminSetCallback** | When the user calls, the RAS server hangs up and calls a preset call-back phone number stored in the user account database. The **wszPhoneNumber** member of the [RAS_USER_0](https://learn.microsoft.com/windows/desktop/RRAS/ras-user-0-str) structure contains the user's call-back phone number. |
| **RASPRIV_CallerSetCallback** | When the user calls, the RAS server provides the option of specifying a call-back phone number. The user can also choose to connect immediately without a call back. The **wszPhoneNumber** member contains a default number that the user can override. |

Use the following constant as a mask to isolate the call back privilege. (This constant is also defined in Mprapi.h.)

RASPRIV_CallbackType

### `wszPhoneNumber`

Pointer to a Unicode string containing the phone number at which the RAS user should be called back.

### `bfPrivilege2`

Specifies flags that grant additional remote access privileges to the RAS user.

The following remote access privilege constants are defined in Mprapi.h.

| Value | Meaning |
| --- | --- |
| **RASPRIV2_DialinPolicy** | Remote access policies determine whether the user is allowed dial-in access. |

## See also

[MprAdminUserGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminusergetinfo)

[MprAdminUserSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminusersetinfo)

[RAS
Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[RAS_USER_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_user_0)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)