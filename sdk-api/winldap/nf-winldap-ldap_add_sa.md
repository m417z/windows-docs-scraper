# ldap_add_sA function

## Description

The **ldap_add_s** function initiates a synchronous add operation that adds an entry to a tree. The parent of the entry being added must already exist or the parent must be empty (equal to the root distinguished name) for an add operation to succeed.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to add.

### `attrs` [in]

A null-terminated array of pointers to
[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda) structures. Each structure specifies a single attribute. See Remarks for more information.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

Before calling **ldap_add_s**. you must create an entry by specifying its attributes in
[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda) structures. Set the **mod_op** member of each structure to LDAP_MOD_ADD, and set the **mod_type** and **mod_vals** members as appropriate for your entry. See
[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry) for more information.

Upon completion of the add operation, **ldap_add_s** returns to the caller. Use
[ldap_add](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add) if you prefer to have the operation carried out asynchronously.

Multithreading: Calls to **ldap_add_s** are thread-safe.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation (by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines) before attempting any other operations.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_add](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)