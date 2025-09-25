# USER_MODALS_INFO_0 structure

## Description

The
**USER_MODALS_INFO_0** structure contains global password information for users and global groups in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Members

### `usrmod0_min_passwd_len`

Specifies the minimum allowable password length. Valid values for this element are zero through LM20_PWLEN.

### `usrmod0_max_passwd_age`

Specifies, in seconds, the maximum allowable password age. A value of TIMEQ_FOREVER indicates that the password never expires. The minimum valid value for this element is ONE_DAY. The value specified must be greater than or equal to the value for the **usrmod0_min_passwd_age** member.

### `usrmod0_min_passwd_age`

Specifies the minimum number of seconds that can elapse between the time a password changes and when it can be changed again. A value of zero indicates that no delay is required between password updates. The value specified must be less than or equal to the value for the **usrmod0_max_passwd_age** member.

### `usrmod0_force_logoff`

Specifies, in seconds, the amount of time between the end of the valid logon time and the time when the user is forced to log off the network. A value of TIMEQ_FOREVER indicates that the user is never forced to log off. A value of zero indicates that the user will be forced to log off immediately when the valid logon time expires.

### `usrmod0_password_hist_len`

Specifies the length of password history maintained. A new password cannot match any of the previous **usrmod0_password_hist_len** passwords. Valid values for this element are zero through DEF_MAX_PWHIST.

## See also

[NetUserModalsGet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsget)

[NetUserModalsSet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsset)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Modal Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)