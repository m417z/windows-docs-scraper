# ldap_delete_ext_s function

## Description

The **ldap_delete_ext_s** function is an extended routine that performs a synchronous operation to remove a leaf entry from the directory tree.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to delete.

### `ServerControls` [in]

Optional. List of LDAP server controls. Set this parameter to **NULL** if not used.

### `ClientControls` [in]

Optional. List of client controls. Set this parameter to **NULL** if not used.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Call **ldap_delete_ext_s** to remove a leaf entry from the directory tree. LDAP does not support deletion of entire subtrees in a single operation, however there is an extended control, [LDAP_SERVER_TREE_DELETE_OID](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-server-tree-delete-oid), that does provide this. The parameters and effects of **ldap_delete_ext_s** include those of
[ldap_delete_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_s). The extended routine includes additional parameters to support client and server controls and thread safety.

As a synchronous function, **ldap_delete_ext_s** returns when the delete operation is complete. Use
[ldap_delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete) or
[ldap_delete_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_ext) to have the delete operation performed asynchronously.

Multithreading: Calls to **ldap_delete_ext_s** are thread-safe.

## See also

[Extended Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/extended-controls)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)

[ldap_delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete)

[ldap_delete_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_ext)

[ldap_delete_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_s)