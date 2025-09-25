# ldap_add_ext_s function

## Description

The **ldap_add_ext_s** function initiates a synchronous add operation to a tree. For an add operation to succeed, the parent of the entry added must exist, or the parent must be empty (equal to the distinguished name of the root).

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to add.

### `attrs` [in]

An array of pointers to
[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda) structures. Each structure specifies a single attribute. For more information, see the Remarks section.

### `ServerControls` [in]

A list of LDAP server controls.

### `ClientControls` [in]

A list of client controls.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see [Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The parameters and effects of **ldap_add_ext_s** include those of
[ldap_add_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_s). The extended routine includes additional parameters to support client and server controls.

Before calling **ldap_add_ext_s**, create an entry by specifying its attributes in
[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda) structures. Set the **mod_op** member of the each structure to **LDAP_MOD_ADD**, and set the **mod_type** and **mod_vals** members as appropriate for your entry.

Upon completion of the add operation, **ldap_add_ext_s** returns to the caller. Use
[ldap_add_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_ext) if you prefer to have the operation completed asynchronously.

Multithreading: Calls to **ldap_add_ext_s** are thread-safe.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation, by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines, before attempting other operations.

*ServerControls* and *ClientControls* are optional and should be set to **NULL** if not used.

## See also

[Extended Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/extended-controls)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)

[ldap_add_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_ext)

[ldap_add_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_add_s)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)