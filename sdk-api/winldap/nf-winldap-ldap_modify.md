# ldap_modify function

## Description

The **ldap_modify** function changes an existing entry.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the name of the entry to modify.

### `mods` [in]

A null-terminated array of modifications to make to the entry.

## Return value

If the function succeeds, it returns the message ID of the modify operation.

If the function fails, it returns –1 and sets the session error parameters in the
[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) data structure.

## Remarks

The **ldap_modify** function initiates an asynchronous operation to modify an existing entry. If values are being added to or replaced in the entry, the function creates the attribute, if necessary. If values are being deleted, and no values remain, the function removes the attribute. All modifications are performed in the order in which they are listed.

As an asynchronous function, **ldap_modify** returns a message ID for the operation. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to get the result of the operation. To cancel an asynchronous operation before it has completed, call
[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon).

If you prefer to have the function return the results directly, use the synchronous routine
[ldap_modify_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_s). Use
[ldap_modify_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_ext) or
[ldap_modify_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_ext_s) if you need support for LDAP 3 server and client controls.

Multithreading: Calls to **ldap_modify** are thread-safe, provided that
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) is used to retrieve the actual session error code when the function call returns the -1 failure code.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation (by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines) before attempting any other operations.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_modify_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_ext)

[ldap_modify_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_ext_s)

[ldap_modify_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_s)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)