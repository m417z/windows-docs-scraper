# ldap_modrdn_sA function

## Description

The **ldap_modrdn_s** function changes the relative distinguished name of an LDAP entry.

This function is obsolete and is provided for backward compatibility with earlier versions of LDAP. For LDAP 3 or later, use the
[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext) or
[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s) function.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `DistinguishedName` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to be changed.

### `NewDistinguishedName` [out]

A pointer to a null-terminated string that contains the new relative distinguished name to give the entry.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Use the **ldap_modrdn_s** function, or its asynchronous equivalent,
[ldap_modrdn](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn), to change the name of an LDAP entry. This function provides compatibility with LDAP 1. Otherwise, use
[ldap_modrdn2](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2) or
[ldap_modrdn2_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2_s).

Be aware that the [ldap_modrdn](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn) functions enable you to change only the relative distinguished name, which is the least significant component of the object's distinguished name. Effective with version 3, LDAP provides the Modify Distinguished Name protocol operation that allows more general name change access. This feature is available by calling
[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext) or
[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s). These functions are recommended, instead of the **ldap_modrdn_s** function, to change an entry name.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_modrdn](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn)

[ldap_modrdn2](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2)

[ldap_modrdn2_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modrdn2_s)

[ldap_rename_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext)

[ldap_rename_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_rename_ext_s)