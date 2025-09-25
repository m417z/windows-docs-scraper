# ldap_delete_s function

## Description

The **ldap_delete_s** function is a synchronous operation that removes a leaf entry from the directory tree.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to delete.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Call **ldap_delete_s** to remove a leaf entry from the directory tree. Be aware that LDAP does not support deletion of entire subtrees in a single operation. As a synchronous operation, **ldap_delete_s** does not return until the operation is compete. Use
[ldap_delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete) or
[ldap_delete_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_ext) to perform the delete operation asynchronously.

Multithreading: The **ldap_delete_s** function is thread-safe.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation, by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines, before attempting any other operations.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete)

[ldap_delete_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_ext)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)