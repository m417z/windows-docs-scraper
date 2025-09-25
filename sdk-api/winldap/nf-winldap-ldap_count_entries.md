# ldap_count_entries function

## Description

The **ldap_count_entries** function counts the number of search entries that a server returned.

## Parameters

### `ld` [in]

The session handle.

### `res` [in]

The search result obtained by a call to one of the synchronous search routines or to
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result).

## Return value

If the function succeeds, it returns the number of entries.

If the function fails, the return value is –1 and the function sets the session error parameters in the LDAP data structure.

## Remarks

The **ldap_count_entries** function returns the number of entries contained, or remaining in a chain of entries. Call the function with the return value from
[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry),
[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry),
[ldap_first_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_reference),
[ldap_next_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_reference), or
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_count_references](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_count_references)

[ldap_count_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_count_values)

[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry)

[ldap_first_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_reference)

[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry)

[ldap_next_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_reference)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)