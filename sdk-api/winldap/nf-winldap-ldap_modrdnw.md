# ldap_modrdnW function

## Description

The **ldap_modrdn** function changes the relative distinguished name of an LDAP entry.

This function is obsolete and is provided for backward compatibility with earlier versions of LDAP. For LDAP 3 or later, use the
[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext) or
[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s) functions.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `DistinguishedName` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to be changed.

### `NewDistinguishedName` [out]

A pointer to a null-terminated string that contains the new relative distinguished name to give the entry.

## Return value

If the function succeeds, it returns the message ID of the modify operation.

If the function fails, it returns –1 and sets the session error parameters in the LDAP data structure.

## Remarks

Use the **ldap_modrdn** function, or its synchronous equivalent,
[ldap_modrdn_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn_s), to change the name of an LDAP entry. LDAP 2 supports additional features through
[ldap_modrdn2](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2) and
[ldap_modrdn2_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2_s).

As an asynchronous function, **ldap_modrdn** returns a message ID for the operation. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to get the result of the operation. To cancel an asynchronous add operation before it has completed, call
[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon).

Be aware that the various **ldap_modrdn** functions allow you to change only the relative distinguished name, which is the least significant component of the object's distinguished name. Effective with version 3, LDAP provides the Modify Distinguished Name protocol operation that allows more general name change access. This feature is available by calling
[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext) or
[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s). These functions are recommended, instead of the **ldap_modrdn** function, to change an entry name.

Multithreading: Calls to **ldap_modrdn** are thread-safe, provided that
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) is used to retrieve the actual session error code when the function call returns the -1 failure code.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation, by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines, before attempting other operations. **ldap_modrdn** is obsolete and provided solely for compatibility with LDAP 1 implementations.

> [!NOTE]
> The winldap.h header defines ldap_modrdn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_modrdn2](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2)

[ldap_modrdn2_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2_s)

[ldap_modrdn_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn_s)

[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext)

[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)