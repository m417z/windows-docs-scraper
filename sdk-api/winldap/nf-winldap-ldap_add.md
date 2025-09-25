# ldap_add function

## Description

The **ldap_add** function initiates an asynchronous add operation to a directory tree. For an add operation to succeed, the parent of the entry added must exist, or the parent must be empty (equal to the distinguished name of the root).

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to add.

### `attrs` [in]

An array of pointers to
[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda) structures. Each structure specifies a single attribute.

## Return value

If the function succeeds, the message ID of the add operation is returned.

If the function fails, it returns –1 and sets the session error parameters in the
[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) data structure. To retrieve the error data, use [LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror).

## Remarks

Before calling **ldap_add**, create an entry by specifying its attributes in
[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda) structures. Set the **mod_op** member of each structure to LDAP_MOD_ADD, and set the **mod_type** and **mod_vals** members as appropriate for your entry.

As an asynchronous function, **ldap_add** returns a message ID for the operation. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to get the result of the operation. To cancel an asynchronous add operation before it has been completed, call
[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon).

To have the results returned directly, use the synchronous function
[ldap_add_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_s). Use
[ldap_add_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_ext) or
[ldap_add_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_ext_s) to enable support for LDAP 3 server and client controls.

Multithreading: Calls to **ldap_add** are thread-safe, provided that
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) is used to retrieve the actual session error code when the function call returns the -1 failure code.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation, by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines, before attempting other operations.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[Synchronous and Asynchronous Calls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/synchronous-vs--asynchronous-calls)

[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon)

[ldap_add_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_ext)

[ldap_add_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_ext_s)

[ldap_add_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_s)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)