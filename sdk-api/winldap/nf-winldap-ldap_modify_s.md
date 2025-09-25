# ldap_modify_s function

## Description

The **ldap_modify_s** function changes an existing entry.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the name of the entry to modify.

### `mods` [in]

A null-terminated array of modifications to make to the entry.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

The **ldap_modify_s** function initiates a synchronous operation to modify an existing entry. If values are being added to or replaced in the entry, the function creates the attribute, if necessary. If values are being deleted, the function removes the attribute if no values remain. All modifications are performed in the order in which they are listed.

Multithreading: Calls to **ldap_modify_s** are thread-safe.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation (by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines) before attempting any other operations.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_modify](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify)

[ldap_modify_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_ext)

[ldap_modify_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_ext_s)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)