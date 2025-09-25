# USER_MODALS_INFO_1005 structure

## Description

The
**USER_MODALS_INFO_1005** structure contains password history information for users and global groups in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Members

### `usrmod1005_password_hist_len`

Specifies the length of password history that the system maintains. A new password cannot match any of the previous usrmod*X*_password_hist_len passwords. Valid values for this element are zero through DEF_MAX_PWHIST.

## See also

[NetUserModalsSet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsset)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Modal Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)