# ldap_search_st function

## Description

The **ldap_search_st** function synchronously searches the LDAP directory and returns a requested set of attributes for each entry matched. An additional parameter specifies a local time-out for the search. The function is identical to
[ldap_search_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_s), except for the additional local time-out parameter.

## Parameters

### `ld` [in]

Session handle.

### `base` [in]

Pointer to a null-terminated string that contains the distinguished name of the entry at which to start the search.

### `scope` [in]

Specifies one of the following values to indicate the search scope.

#### LDAP_SCOPE_BASE

Search the base entry only.

#### LDAP_SCOPE_ONELEVEL

Search all entries in the first level below the base entry, excluding the base entry.

#### LDAP_SCOPE_SUBTREE

Search the base entry and all entries in the tree below the base.

### `filter` [in]

Pointer to a null-terminated string that specifies the search filter. For more information, see
[Search Filter Syntax](https://learn.microsoft.com/windows/desktop/ADSI/search-filter-syntax).

### `attrs` [in]

A null-terminated array of null-terminated strings that indicate which attributes to return for each matching entry. Pass **NULL** to retrieve all available attributes.

### `attrsonly` [in]

Boolean value that must be zero if both attribute types and values are to be returned, nonzero if only types are required.

### `timeout` [in]

The local search time-out value, in seconds.

### `res` [out]

Contains the results of the search upon completion of the call. Can also contain partial results or extended data when the function call fails with an error code. Any results returned must be freed with a call to [ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree) when no longer required by the application.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code, however **ldap_search_st** can fail and can still allocate *pMsg*. For example, both **LDAP_PARTIAL_RESULTS** and **LDAP_REFERRAL** error code allocate *pMsg*. For more information, see the following code example. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_search_st** function initiates a synchronous search operation.

Use the
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option) function with the *ld* session handle to set the **LDAP_OPT_SIZELIMIT** and **LDAP_OPT_DEREF** options that determine how the search is performed. For more information, see
[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options). The *timeout* parameter in **ldap_search_st** overrides the **LDAP_OPT_TIMELIMIT**.

Upon completion of the search operation, **ldap_search_st** returns to the caller. Use
[ldap_search](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search) or
[ldap_search_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext) to have the operation performed asynchronously.

Multithreading: Calls to **ldap_search_st** are thread-safe.

The following code example shows how to free *pMsg* if **ldap_search_st** fails.

```cpp
// Initialize return value to NULL.
LDAPMessage *pMsg = NULL;

// Perform the search request.
dwErr = ldap_search_st (i_pldap,
        i_lpszBase,
        i_ulScope,
        i_lpszSearchFilter,
        lpszAttributes,
        0,
        lpsTimeout,
        &pMsg
        );

// Cleanup calling parameters.
if (lpszAttributes != NULL)
    delete [] lpszAttributes;

// Convert error code and cleanup pMsg if necessary.
if (dwErr != LDAP_SUCCESS)
{
    DebugOutLDAPError(i_pldap, dwErr, _T("ldap_search_st"));
    hr = HRESULT_FROM_WIN32(dwErr);

    // Be aware that pMsg can contain valid data, even if the
    // call to ldap_search_st returned an error code.
    // This can be caused by the server returning codes,
    // such as LDAP_RESULTS_TOO_LARGE or other codes,
    // that indicate that the search returned partial
    // results. The user code can handle these cases
    // if required, this example just frees pMsg on any
    // error code.

    if (pMsg != NULL)
      ldap_msgfree(pMsg);
}

else
{
    // Process the search results.
    ...
    // Free the results when complete.
    if (pMsg != NULL) ldap_msgfree(pMsg);
}
```

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options)

[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree)

[ldap_search](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search)

[ldap_search_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext)

[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s)

[ldap_search_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_s)