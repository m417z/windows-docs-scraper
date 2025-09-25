# ldap_next_reference function

## Description

The **ldap_next_reference** function retrieves a reference from a search result chain.

## Parameters

### `ld` [in]

The session handle.

### `entry` [in]

The entry returned by a previous call to
[ldap_first_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_reference) or **ldap_next_reference**.

## Return value

If the search returned valid results, this function returns a pointer to the next result entry in the results set. If no further entries or references exist in the result set, it returns **NULL**. This is the only error return; the session error parameter in the LDAP data structure is cleared to 0 in either case.

## Remarks

Use **ldap_next_reference** in conjunction with
[ldap_first_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_reference) to step through and retrieve a list of continuation references from a search result chain.

The function returns subordinate referrals (references) that are returned in search responses. A subordinate referral is one in which the server has returned some data and the referral has been passed to other naming contexts below the current level in the tree. To step through external references in which the naming context does not reside on the server, use
[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result).

You are not required to explicitly free the returned reference, as it is freed when the message itself is freed.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_first_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_reference)

[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result)