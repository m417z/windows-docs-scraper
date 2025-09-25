# ldap_modrdn2_sW function

## Description

The **ldap_modrdn2_s** function changes the relative distinguished name of an LDAP entry.

This function is obsolete. For LDAP 3 or later, use the
[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext) or
[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s) functions.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `DistinguishedName` [in]

A pointer to a null-terminated string that contains the distinguished name to change.

### `NewDistinguishedName` [in]

A pointer to a null-terminated string that contains the new relative distinguished name to give the entry.

### `DeleteOldRdn` [in]

**TRUE** if the old relative distinguished name should be deleted; **FALSE** if the old relative distinguished name should be retained.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Be aware that the various [ldap_modrdn](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn) functions allow you to change only the relative distinguished name, which is the least significant component of the object's distinguished name. Effective with version 3, LDAP provides the Modify Distinguished Name protocol operation that allows access to name-change functions. This feature is available by calling
[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext) or
[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s). These functions are recommended, rather than the **ldap_modrdn2_s** function, to change an entry name.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation, by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines, before attempting any other operations.

> [!NOTE]
> The winldap.h header defines ldap_modrdn2_s as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Modifying a Directory Entry](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/modifying-a-directory-entry)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_modrdn2](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2)

[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext)

[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)