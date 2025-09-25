# ldap_get_paged_count function

## Description

The **ldap_get_paged_count** function records the number of paged results that the server has returned for a search.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `SearchBlock` [in]

Handle to an
[LDAPSearch](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366129(v=vs.85)) structure.

### `TotalCount` [out]

The total pages in the search results.

### `Results` [out]

A pointer to the
[LDAPMessage](https://learn.microsoft.com/windows/desktop/api/winldap/ns-winldap-ldapmessage) structure that contains the results of the operation.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Call **ldap_get_paged_count** for each result set received after calling
[ldap_get_next_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page). This allows the LDAP runtime to save from the cookie that the server uses to track the search.

If you call
[ldap_get_next_page_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page_s), a call to **ldap_get_paged_count** is not required.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAPMessage](https://learn.microsoft.com/windows/desktop/api/winldap/ns-winldap-ldapmessage)

[LDAPSearch](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366129(v=vs.85))

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_get_next_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page)

[ldap_get_next_page_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page_s)