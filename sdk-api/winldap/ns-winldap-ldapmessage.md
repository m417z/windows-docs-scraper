# LDAPMessage structure

## Description

The **LDAPMessage** structure is used by an LDAP function to return results and error data.

## Members

## Remarks

The **LDAPMessage** structure is an opaque data type returned from a server when you call a search or a traversal function. For example, after performing an asynchronous operation, [ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) can be called to get the server **LDAPMessage** response. Another example is a call to [ldap_search_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_s), which also returns an **LDAPMessage**.

To free the **LDAPMessage** structure when it is no longer required, call
[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree).

There are no client-accessible fields in this structure.

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures)

[functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_count_entries](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_count_entries)

[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_search](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search)