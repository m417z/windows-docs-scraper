# ldap_get_next_page_s function

## Description

The **ldap_get_next_page_s** function returns the next page in a sequence of synchronous paged search results.

## Parameters

### `ExternalHandle` [in]

Session handle.

### `SearchHandle` [in]

Search block handle.

### `timeout` [in]

The time value, in seconds, that the client will wait for the call to return.

### `PageSize` [in]

The number of entries to return in a single page.

### `TotalCount` [out]

The server estimate of the total number of entries in the entire result set. A value of zero indicates that the server cannot provide an estimate.

### `Results` [out]

A pointer to the
[LDAPMessage](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldapmessage) structure that contains the results.

## Return value

If the server returns a null cookie (non-continuation), the value is **LDAP_NO_RESULTS_RETURNED**. Otherwise, the client signals a continuation (more data available) by returning **LDAP_SUCCESS**.

If the function otherwise fails, it returns the error code return value related to the failure. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_get_next_page_s** function is part of the interface for simple, synchronous paging of search results. Use the search handle returned from an initial call to
[ldap_search_init_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_init_page) and specify, in the *PageSize* parameter, the number of entries to be returned in a page. Set *PageSize* to zero to quit a search.

The results returned from **ldap_get_next_page_s** can be handled as any other search result, and should be freed, when finished, by calling
[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree).

When parsing the results set, it is possible for the server to return an empty page of results and yet still respond with an **LDAP_SUCCESS** return code. This indicates that the server was unable to retrieve a page of results, due to a timeout or other reason, but has not completed the search request. The proper behavior in this instance is to continue to call **ldap_get_next_page_s** until either another page of results are successfully retrieved, an error code is returned, or **LDAP_NO_RESULTS_RETURNED** is returned to indicate the search is complete.

To retrieve paged search result asynchronously, use
[ldap_get_next_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page).

If **ldap_get_next_page_s** is used, it is not required that
[ldap_get_paged_count](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_paged_count) is called to record the number of paged results returned by a server.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAPMessage](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldapmessage)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_get_next_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page)

[ldap_get_paged_count](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_paged_count)

[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree)

[ldap_search_init_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_init_page)