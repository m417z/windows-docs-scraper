# ldap_count_references function

## Description

The **ldap_count_references** function counts the number of subordinate references that were returned by the server in a response to a search request.

## Parameters

### `ld` [in]

The session handle.

### `res` [in]

The search result obtained by a call to one of the synchronous search routines or to
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result).

## Return value

If the function succeeds, it returns the number of references.

If the function fails, it returns –1 and sets the session error parameters in the LDAP data structure.

## Remarks

The **ldap_count_references** function returns the number of references contained in a chain of search results. It can also be used to count the number of references that remain in a chain. Call the function with the return value from
[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry),
[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry),
[ldap_first_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_reference),
[ldap_next_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_reference), or
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_count_entries](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_count_entries)

[ldap_count_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_count_values)

[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry)

[ldap_first_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_reference)

[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry)

[ldap_next_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_reference)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)