# ldap_delete_extA function

## Description

The **ldap_delete_ext** function is an extended routine that removes a leaf entry from the directory tree.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to delete.

### `ServerControls` [in]

Optional. List of LDAP server controls. If not used, set this parameter to NULL.

### `ClientControls` [in]

Optional. List of client controls. If not used, set this parameter to **NULL**.

### `MessageNumber` [out]

Message ID for the request.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_delete_ext** function removes a leaf entry from the directory tree. LDAP does not support deletion of entire subtrees in a single operation, however there is an extended control, [LDAP_SERVER_TREE_DELETE_OID](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-server-tree-delete-oid), used to perform this operation.

The parameters and effects of **ldap_delete_ext** include those of
[ldap_delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete). The extended routine includes parameters to support client and server controls and thread safety.

If the operation succeeds, **ldap_delete_ext** passes the message ID to the caller as a parameter when the operation returns successfully. To get the result of the operation, call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID.

To have the function return the results directly, use the synchronous routine
[ldap_delete_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_ext_s).

Multithreading: Calls to **ldap_delete_ext** are thread-safe.

## See also

[Extended Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/extended-controls)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)

[ldap_delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete)

[ldap_delete_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_ext_s)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)