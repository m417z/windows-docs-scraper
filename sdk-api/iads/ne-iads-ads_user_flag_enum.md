# ADS_USER_FLAG_ENUM enumeration

## Description

The **ADS_USER_FLAG_ENUM** enumeration
defines the flags used for setting user properties in the directory. These flags correspond to
values of the **userAccountControl** attribute in Active Directory when using the LDAP
provider, and the **userFlags** attribute when using the WinNT system provider.

## Constants

### `ADS_UF_SCRIPT:0x1`

The logon script is executed. This flag does not work for the ADSI LDAP provider on either read or write
operations. For the ADSI WinNT provider, this flag is read-only data, and it cannot be set for user
objects.

### `ADS_UF_ACCOUNTDISABLE:0x2`

The user account is disabled.

### `ADS_UF_HOMEDIR_REQUIRED:0x8`

The home directory is required.

### `ADS_UF_LOCKOUT:0x10`

The account is currently locked out.

### `ADS_UF_PASSWD_NOTREQD:0x20`

No password is required.

### `ADS_UF_PASSWD_CANT_CHANGE:0x40`

The user cannot change the password. This flag can be read, but not set directly. For more information and
a code example that shows how to prevent a user from changing the password, see
[User Cannot Change Password](https://learn.microsoft.com/windows/desktop/ADSI/user-cannot-change-password).

### `ADS_UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED:0x80`

The user can send an encrypted password.

### `ADS_UF_TEMP_DUPLICATE_ACCOUNT:0x100`

This is an account for users whose primary account is in another domain. This account provides user access
to this domain, but not to any domain that trusts this domain. Also known as a local user account.

### `ADS_UF_NORMAL_ACCOUNT:0x200`

This is a default account type that represents a typical user.

### `ADS_UF_INTERDOMAIN_TRUST_ACCOUNT:0x800`

This is a permit to trust account for a system domain that trusts other domains.

### `ADS_UF_WORKSTATION_TRUST_ACCOUNT:0x1000`

This is a computer account for a Windows or Windows Server that is a member of this domain.

### `ADS_UF_SERVER_TRUST_ACCOUNT:0x2000`

This is a computer account for a system backup domain controller that is a member of this domain.

### `ADS_UF_DONT_EXPIRE_PASSWD:0x10000`

When set, the password will not expire on this account.

### `ADS_UF_MNS_LOGON_ACCOUNT:0x20000`

This is an Majority Node Set (MNS) logon account. With MNS, you can configure a multi-node Windows cluster
without using a common shared disk.

### `ADS_UF_SMARTCARD_REQUIRED:0x40000`

When set, this flag will force the user to log on using a smart card.

### `ADS_UF_TRUSTED_FOR_DELEGATION:0x80000`

When set, the service account (user or computer account), under which a service runs, is trusted for
Kerberos delegation. Any such service can impersonate a client requesting the service. To enable a service for
Kerberos delegation, set this flag on the **userAccountControl** property of the
service account.

### `ADS_UF_NOT_DELEGATED:0x100000`

When set, the security context of the user will not be delegated to a service even if the service account
is set as trusted for Kerberos delegation.

### `ADS_UF_USE_DES_KEY_ONLY:0x200000`

Restrict this principal to use only Data Encryption Standard (DES) encryption types for keys.

### `ADS_UF_DONT_REQUIRE_PREAUTH:0x400000`

This account does not require Kerberos preauthentication for logon.

### `ADS_UF_PASSWORD_EXPIRED:0x800000`

The user password has expired. This flag is created by the system using data from the password last set
attribute and the domain policy. It is read-only and cannot be set. To manually set a user password as expired,
use the [NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) function with the
[USER_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_3)
(**usri3_password_expired** member) or
[USER_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-user_info_4)
(**usri4_password_expired** member) structure.

### `ADS_UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION:0x1000000`

The account is enabled for delegation. This is a security-sensitive setting; accounts with this option
enabled should be strictly controlled. This setting enables a service running under the account to assume a
client identity and authenticate as that user to other remote servers on the network.

## Remarks

For more information, see [Managing Users](https://learn.microsoft.com/windows/desktop/AD/managing-users).

For more information, and a code example that shows how to set the
**ADS_UF_DONT_EXPIRE_PASSWD** value on a user
**userAccountControl** attribute, see
[Password Never Expires](https://learn.microsoft.com/windows/desktop/ADSI/password-never-expires).

**Note** Because VBScript cannot read data from a type library, VBScript applications do not understand the symbolic
constants as defined above. Use the numerical constants, instead, to set the appropriate flags in your VBScript
applications. To use the symbolic constants as a good programming practice, create explicit declarations of such
constants, as done here, in your VBScript applications.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[Managing Users](https://learn.microsoft.com/windows/desktop/AD/managing-users)

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)