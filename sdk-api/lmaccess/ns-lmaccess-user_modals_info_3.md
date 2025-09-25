# USER_MODALS_INFO_3 structure

## Description

The
**USER_MODALS_INFO_3** structure contains lockout information for users and global groups in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Members

### `usrmod3_lockout_duration`

Specifies, in seconds, how long a locked account remains locked before it is automatically unlocked.

### `usrmod3_lockout_observation_window`

Specifies the maximum time, in seconds, that can elapse between any two failed logon attempts before lockout occurs.

### `usrmod3_lockout_threshold`

Specifies the number of invalid password authentications that can occur before an account is marked "locked out."

## See also

[NetUserModalsGet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsget)

[NetUserModalsSet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsset)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Modal Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)