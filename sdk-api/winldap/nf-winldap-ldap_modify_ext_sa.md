# ldap_modify_ext_sA function

## Description

The **ldap_modify_ext_s** function changes an existing entry.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the name of the entry to modify.

### `mods` [in]

A null-terminated array of modifications to make to the entry.

### `ServerControls` [in]

A list of LDAP server controls.

### `ClientControls` [in]

A list of client controls.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

The **ldap_modify_ext_s** function initiates a synchronous operation to modify an existing entry. If values are being added or replaced in the entry, the function creates the attribute, if necessary. If values are being deleted, and no values remain, the function removes the attribute. All modifications are performed in the order in which they are listed.

The parameters and effects of **ldap_modify_ext_s** subsume those of
[ldap_modify_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_s). The extended routine includes additional parameters to support client and server controls.

Multithreading: Calls to **ldap_modify_ext_s** are thread-safe.

## See also

[Extended Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/extended-controls)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[LDAPMod](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapmoda)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)

[ldap_modify](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify)

[ldap_modify_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify_s)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)