# ldap_get_next_page function

## Description

The **ldap_get_next_page** function returns the next page in a sequence of asynchronous paged search results.

## Parameters

### `ExternalHandle` [in]

Session handle.

### `SearchHandle` [in]

Search block handle.

### `PageSize` [in]

The number of entries to return in a single page.

### `MessageNumber` [out]

The message ID for the request.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code return value. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_get_next_page** function is part of the interface for simple, asynchronous paging of search results. Use the search handle returned from an initial call to
[ldap_search_init_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_init_page) and specify, in the *PageSize* parameter, the number of entries to be returned in a page. Set *PageSize* to zero to abandon a search.

Be aware that after each call to **ldap_get_next_page**, you must call
[ldap_get_paged_count](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_paged_count) for each set of results returned from the server using [ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result). This enables the LDAP run time to save the cookie that the server passed back to maintain the search state. Other than calling **ldap_get_paged_count**, the results returned from **ldap_get_next_page** can be handled as any other search result, and must be freed when complete by calling
[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree).

When parsing the results set, be aware that it is possible for the server to return an empty page of results and yet still respond with an **LDAP_SUCCESS** return value. This indicates that the server was unable to retrieve a page of results, due to a timeout or other reason, but has not finished the search request. The proper behavior, in this instance, is to continue to call **ldap_get_next_page** until either another page of results are successfully retrieved, an error code is returned, or **LDAP_NO_RESULTS_RETURNED** is returned to indicate that the search is complete.

If you prefer to retrieve paged search results synchronously, use
[ldap_get_next_page_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page_s).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_get_next_page_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page_s)

[ldap_get_paged_count](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_paged_count)

[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_search_init_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_init_page)