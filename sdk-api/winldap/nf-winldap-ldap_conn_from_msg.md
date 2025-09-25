# ldap_conn_from_msg function

## Description

The **ldap_conn_from_msg** function returns the [LDAP](https://learn.microsoft.com/windows/desktop/api/winldap/ns-winldap-ldap) session handle (connection pointer) for a particular message.

## Parameters

### `PrimaryConn` [in]

A pointer to the [LDAP](https://learn.microsoft.com/windows/desktop/api/winldap/ns-winldap-ldap) session handle of the message, if known. If the **LDAP** session handle for the message is unknown, then **NULL** may be passed for this parameter provided that the
[LDAP_OPT_REF_DEREF_CONN_PER_MSG](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options) session option had been previously set for the message session.

### `res` [in]

The **LDAP** message queried. If **NULL** is passed for this parameter, then the function will respond with a **NULL** return value.

## Return value

The return value is the [LDAP](https://learn.microsoft.com/windows/desktop/api/winldap/ns-winldap-ldap) session handle (connection pointer) where the message originated from. This function returns **NULL** if the originating session has closed or if a **NULL** **LDAPMessage** pointer is passed to the function and the [LDAP_OPT_REF_DEREF_CONN_PER_MSG](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options) session option was not previously set for the message session.

## Remarks

This function is used to identify the [LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) session handle associated with the specified **LDAP** message. It returns a valid **LDAP** session handle only if one of the following conditions are met:

* The [LDAPMessage](https://learn.microsoft.com/windows/desktop/api/winldap/ns-winldap-ldapmessage) originated from the same [LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) session handle passed to the function in the *PrimaryConn* parameter.

* The [LDAP_OPT_REF_DEREF_CONN_PER_MSG](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options) session option was previously enabled on the [LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) session associated with the message.

If neither of these conditions are met, the function returns a **NULL** session handle.

## See also

[Establishing an LDAP Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/establishing-an-ldap-session)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/windows/desktop/api/winldap/ns-winldap-ldap)

[LDAPMessage](https://learn.microsoft.com/windows/desktop/api/winldap/ns-winldap-ldapmessage)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init)

[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option)

[structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures)