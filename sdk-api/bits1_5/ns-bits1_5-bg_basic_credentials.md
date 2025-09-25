# BG_BASIC_CREDENTIALS structure

## Description

Identifies the user name and password to authenticate.

## Members

### `UserName`

A null-terminated string that contains the user name to authenticate. The user name is limited to 300 characters, not including the null terminator. The format of the user name depends on the authentication scheme requested. For example, for Basic, NTLM, and Negotiate authentication, the user name is of the form *DomainName***\\***UserName*. For Passport authentication, the user name is an email address. For more information, see Remarks.

If **NULL**, default credentials for this session context are used.

### `Password`

A null-terminated string that contains the password in plaintext. The password is limited to 65536 characters, not including the null terminator. The password can be blank. Set it to **NULL** if **UserName** is **NULL**. BITS encrypts the password before persisting the job if a network disconnect occurs or the user logs off.

Live ID encoded passwords are supported through Negotiate 2. For more information about Live IDs, see the [Windows Live ID SDK](https://learn.microsoft.com/office/).

## Remarks

The following list identifies when the **UserName** and **Password** members are required based on the authentication scheme requested:

To protect the user name and password information, call the **SecureZeroMemory** function, defined in Winbase.h, to clear the **UserName** and **Password** buffers after you use the structure.

You can specify the user name like this.

* *DomainName***\***UserName*. Use *DomainName***\***UserName* if the server is in a domain and the *DomainName* is the domain to which the server belongs or is a trusted domain.
* *ServerName***\***UserName*. Use *ServerName***\***UserName* if the account is a local account on the server. The *ServerName* is the name of the computer that is authenticating the credentials.
* *UserName*. If you specify only *UserName*, the user's default domain name is prefixed to the user's name and the rules for the *DomainName***\***UserName* form apply. Use this option only if the user is a member of a domain.
* **NULL**. To use the user's logon credentials for NTLM or Kerberos authentication, set **UserName** to **NULL**. This works only if the user is in a trusted domain. Setting **UserName** to **NULL** for services running as a system account passes the computer's credentials for authentication. This option works only if the domain enables Kerberos authentication and you select Negotiate as the authentication scheme.

## See also

[BG_AUTH_CREDENTIALS_UNION](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_auth_credentials_union)