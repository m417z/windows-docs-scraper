# ldap_get_dn function

## Description

The **ldap_get_dn** function retrieves the distinguished name for a given entry.

## Parameters

### `ld` [in]

The session handle.

### `entry` [in]

The entry whose distinguished name is to be retrieved.

## Return value

If the function succeeds, it returns the distinguished name as a pointer to a null-terminated character string.

If the function fails, it returns **NULL** and sets the session error parameters in the
[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) data structure.

## Remarks

The **ldap_get_dn** function retrieves the distinguished name for an entry that was returned by
[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry), or
[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry). When the returned name is no longer needed, free the string by calling
[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry)

[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree)

[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry)