# ldap_deleteW function

## Description

The **ldap_delete** function deletes an entry from the directory tree.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to delete.

## Return value

If the function succeeds, it returns the message ID of the delete operation.

If the function fails, the return value is –1 and the function sets the session error parameters in the
[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) data structure. To retrieve this value, use [LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror).

## Remarks

Call **ldap_delete** to remove a leaf entry from the directory tree. Be aware that LDAP does not support deletion of entire subtrees in a single operation. As an asynchronous function, **ldap_delete** returns a message ID for the operation. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to get the result of the operation. To cancel an asynchronous delete operation before it has completed, call
[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon).

To have the function return the results directly, use the synchronous routine
[ldap_delete_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_s). Use
[ldap_delete_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_ext) or
[ldap_delete_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_ext_s) to enable support for LDAP 3 server and client controls.

Multithreading: Calls to **ldap_delete** are thread-safe, provided that
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) is used to retrieve the actual session error code when the function call returns the -1 failure code.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation, by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines, before attempting any other operations.

> [!NOTE]
> The winldap.h header defines ldap_delete as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_delete_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_ext)

[ldap_delete_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_ext_s)

[ldap_delete_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_delete_s)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)