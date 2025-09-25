# USER_MODALS_INFO_1004 structure

## Description

The
**USER_MODALS_INFO_1004** structure contains forced logoff information for users and global groups in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Members

### `usrmod1004_force_logoff`

Specifies, in seconds, the amount of time between the end of the valid logon time and the time when the user is forced to log off the network. A value of TIMEQ_FOREVER indicates that the user is never forced to log off. A value of zero indicates that the user will be forced to log off immediately when the valid logon time expires.

## See also

[NetUserModalsSet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsset)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Modal Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)