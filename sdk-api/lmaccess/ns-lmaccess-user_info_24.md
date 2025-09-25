# USER_INFO_24 structure

## Description

The
**USER_INFO_24** structure contains user account information on an account which is connected to an Internet identity. This information includes the Internet provider name for the user, the user's Internet name, and the user's security identifier (SID).

## Members

### `usri24_internet_identity`

A boolean value that indicates whether an account is connected to an Internet identity.

This member is true if the account is connected to an Internet identity. The other members in this structure can be used.

If this member is false, then the account is not connected to an Internet identity and other members in this structure should be ignored.

### `usri24_flags`

A set of flags. This member must be zero.

### `usri24_internet_provider_name`

A pointer to a Unicode string that specifies the Internet provider name.

### `usri24_internet_principal_name`

A pointer to a Unicode string that specifies the user's Internet name.

### `usri24_user_sid`

The local account SID of the user.

## Remarks

A user's account for logging onto Windows can be connected to an Internet identity. The user account can be a local account on a computer or a domain account for computers joined to a domain. The **USER_INFO_24** structure is used to provide information on an account which is connected to an Internet identity.

On Windows 8 and Windows Server 2012, the Internet identity for a connected account can often be used instead of the computer account.

## See also

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)