# LDAP structure

## Description

The **LDAP** structure represents an LDAP session. Typically, a session corresponds to a connection to a single server. However, in the case of referrals, an LDAP session may encompass several server connections. The ability to track referrals is available in LDAP 3.

## Members

## Remarks

An **LDAP** structure is an opaque data type allocated and initialized by a call to
[ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init),
[cldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-cldap_open), or
[ldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_open). Subsequent LDAP calls pass a handle to this structure, which maintains the state of an LDAP session for the duration of the connection. When the session ends, call
[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) to destroy the connection handle.

Although this is an opaque data type, it is documented in Winldap.h. This is primarily of value in porting applications written using other LDAP client implementations. Call
[ldap_get_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option) or
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option) to access or change the values associated with the LDAP connection handle (this structure). Using these two functions also expose settings not directly accessible from the **LDAP** structure. For more information about session options, see [Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options).

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures)

[cldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-cldap_open)

[ldap_get_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option)

[ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init)

[ldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_open)

[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)