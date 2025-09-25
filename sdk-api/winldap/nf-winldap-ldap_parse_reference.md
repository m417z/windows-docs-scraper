# ldap_parse_reference function

## Description

The **ldap_parse_reference** function returns a list of subordinate referrals in a search response message.

## Parameters

### `Connection` [in]

The session handle.

### `ResultMessage` [in]

A pointer to an
[LDAPMessage](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldapmessage) structure containing the search response.

### `Referrals` [out]

A pointer to the list of subordinate referrals. Free with [ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free).

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

The **ldap_parse_reference** function returns a list of referrals in the form of URLs. Call this function if a call to
[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result) indicates that there are referrals.

When it is no longer needed, free the *Referrals* pointer by calling
[ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAPMessage](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldapmessage)

[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result)

[ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free)