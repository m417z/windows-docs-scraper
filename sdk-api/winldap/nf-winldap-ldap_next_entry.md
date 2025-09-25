# ldap_next_entry function

## Description

The **ldap_next_entry** function retrieves an entry from a search result chain.

## Parameters

### `ld` [in]

The session handle.

### `entry` [in]

The entry returned by a previous call to
[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry) or **ldap_next_entry**.

## Return value

If the search returned valid results, this function returns a pointer to the next result entry in the results set. If no further entries or references exist in the result set, it returns **NULL**. This is the only error return; the session error parameter in the LDAP data structure is cleared to 0 in either case.

## Remarks

Use **ldap_next_entry** in conjunction with
[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry) to step through and retrieve the list of entries from a search result chain.

You are not required to explicitly free the returned entry because it is freed when the message itself is freed.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry)