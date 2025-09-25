# ldap_modrdn2 function

## Description

The **ldap_modrdn2** function changes the relative distinguished name of an LDAP entry.

This function is obsolete. For LDAP 3 or later, use the
[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext) or
[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s) functions.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `DistinguishedName` [in]

A null-terminated string that contains the distinguished name to change.

### `NewDistinguishedName` [in]

A null-terminated string that contains the new relative distinguished name to give the entry.

### `DeleteOldRdn` [in]

**TRUE** if the old relative distinguished name should be deleted; **FALSE** if the old relative distinguished name should be retained.

## Return value

If the function succeeds, it returns the message ID of the modify operation.

If the function fails, it returns –1 and sets the session error parameters in the LDAP data structure.

## Remarks

Use the **ldap_modrdn2** function, or its synchronous equivalent,
[ldap_modrdn2_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2_s), to change the name of an LDAP entry.

As an asynchronous function, **ldap_modrdn2** returns a message ID for the operation. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to get the result of the operation. To cancel an asynchronous add operation before it has completed, call
[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon).

Be aware that the various [ldap_modrdn](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn) functions enable you to change only the relative distinguished name, which is the least significant component of the object's distinguished name. Effective with version 3, LDAP provides the Modify Distinguished Name protocol operation, which enables more general name-change access. This functionality is available by calling
[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext) or
[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s). These functions are recommended, instead of the **ldap_modrdn2** function, to change an entry name.

Multithreading: Calls to **ldap_modrdn2** are thread-safe, provided that
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) is used to retrieve the actual session error code when the function call returns the -1 failure code.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation, by calling one of the [ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or [ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines, before attempting other operations.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon)

[ldap_modrdn2_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2_s)

[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext)

[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)