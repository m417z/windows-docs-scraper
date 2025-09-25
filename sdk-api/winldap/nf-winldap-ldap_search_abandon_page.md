# ldap_search_abandon_page function

## Description

The **ldap_search_abandon_page** function terminates a paged-results search.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `SearchBlock` [in]

A handle to the search block for the current search.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

Call **ldap_search_abandon_page** after a search has completed (when the server returns **LDAP_NO_RESULTS_RETURNED**) to perform necessary cleanup. You can also use this function to abandon a search at any time after the search block has been allocated.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)