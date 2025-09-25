# USER_MODALS_INFO_1003 structure

## Description

The
**USER_MODALS_INFO_1003** structure contains the minimum duration for passwords in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Members

### `usrmod1003_min_passwd_age`

Specifies the minimum number of seconds that can elapse between the time a password changes and when it can be changed again. A value of zero indicates that no delay is required between password updates. The value specified must be less than or equal to the value for the usrmod*X*_max_passwd_age member.

## See also

[NetUserModalsSet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsset)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Modal Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)