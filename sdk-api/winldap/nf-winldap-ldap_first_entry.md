# ldap_first_entry function

## Description

The **ldap_first_entry** function returns the first entry of a message.

## Parameters

### `ld` [in]

The session handle.

### `res` [in]

The search result, as obtained by a call to one of the synchronous search routines or
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result).

## Return value

If the search returned valid results, this function returns a pointer to the first result entry. If no entry or reference exists in the result set, it returns **NULL**. This is the only error return; the session error parameter in the LDAP data structure is cleared to 0 in either case.

## Remarks

Use **ldap_first_entry** in conjunction with
[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry) to step through and retrieve the list of entries from a search result chain.

You do not have to explicitly free the returned entry as it is freed when the message itself is freed.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)