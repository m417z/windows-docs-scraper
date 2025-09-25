# USER_MODALS_INFO_1002 structure

## Description

The
**USER_MODALS_INFO_1002** structure contains the maximum duration for passwords in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Members

### `usrmod1002_max_passwd_age`

Specifies, in seconds, the maximum allowable password age. A value of TIMEQ_FOREVER indicates that the password never expires. The minimum valid value for this element is ONE_DAY. The value specified must be greater than or equal to the value for the usrmod*X*_min_passwd_age member.

## See also

[NetUserModalsSet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsset)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Modal Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)