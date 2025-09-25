# ldap_first_reference function

## Description

The **ldap_first_reference** function returns the first reference from a message.

## Parameters

### `ld` [in]

The session handle.

### `res` [in]

The search result, as obtained by a call to one of the synchronous search routines or
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result).

## Return value

If the search returned valid results, this function returns a pointer to the first result reference. If no entry or reference exists in the result set, it returns **NULL**. This is the only error return; the session error parameter in the LDAP data structure is cleared to 0 in either case.

## Remarks

Use **ldap_first_reference** in conjunction with
[ldap_next_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_reference) to step through and retrieve a list of continuation references from a search result chain.

The function returns subordinate referrals (references) that are returned in search responses. A subordinate referral is one in which the server has returned some data and the referral has been passed to other naming contexts below the current level in the tree. To step through external references in which the naming context does not reside on the server, use
[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result) instead.

You do not have to explicitly free the returned reference as it is freed when the message itself is freed.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_next_reference](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_reference)

[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)