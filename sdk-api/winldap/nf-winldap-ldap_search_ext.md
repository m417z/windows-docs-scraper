# ldap_search_ext function

## Description

The **ldap_search_ext** function searches the LDAP directory and returns a requested set of attributes for each matched entry.

## Parameters

### `ld` [in]

The session handle.

### `base` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry at which to start the search.

### `scope` [in]

Specifies one of the following values to indicate the search scope.

#### LDAP_SCOPE_BASE

Search the base entry only.

#### LDAP_SCOPE_ONELEVEL

Search all entries in the first level below the base entry, excluding the base entry.

#### LDAP_SCOPE_SUBTREE

Search the base entry and all entries in the tree below the base.

### `filter` [in]

A pointer to a null-terminated string that specifies the search filter. For more information, see
[Search Filter Syntax](https://learn.microsoft.com/windows/desktop/ADSI/search-filter-syntax).

### `attrs` [in]

A null-terminated array of null-terminated strings that indicate which attributes to return for each matching entry. To retrieve all available attributes, pass **NULL**.

### `attrsonly` [in]

A Boolean value that should be zero if both attribute types and values are to be returned, nonzero if only types are to be returned.

### `ServerControls` [in]

A list of LDAP server controls.

### `ClientControls` [in]

A list of client controls.

### `TimeLimit` [in]

Specifies both the local search time-out value in seconds and the operation time limit sent to the server within the search request.

### `SizeLimit` [in]

A limit on the number of entries to return from the search. A value of zero indicates no limit.

### `MessageNumber` [out]

The request message ID.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_search_ext** function initiates an asynchronous search operation. The parameters and effects of **ldap_search_ext** include those of
[ldap_search](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search). The extended function includes additional parameters to support client and server controls and thread safety, and to specify size and time limits for each search operation.

Use the
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option) function with the *ld* session handle to set the **LDAP_OPT_DEREF** option that determine how the search is performed. For more information, see
[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options). Two other session options, **LDAP_OPT_SIZELIMIT** and **LDAP_OPT_TIMELIMIT**, are ignored in favor of the *SizeLimit* and *TimeLimit* parameters in this function.

If the operation succeeds, **ldap_search_ext** passes the message ID to the caller as a parameter when the operation returns successfully. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to get the result of the operation.

An LDAP client application that must control the rate at which results are returned may specify the search request to provide a paged results control with size set to the desired page size and cookie set to the zero-length string. The page size specified may be greater than zero and less than the *SizeLimit* value specified in the search request.

If the page size is greater than or equal to the *SizeLimit* value option described in
[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options), the server should ignore the control because the request can be satisfied in a single page. If the server does not support this control, the server must return an error of unsupported Critical Extension if the client requested it as critical, otherwise the server should ignore the control. The remainder of this section assumes the server does not ignore the client's paged results control.

The client sends the server a search request with the simple paged results control, along with an empty previous enumeration key, also known as a "cookie," and the initial page size. The server then returns the number of entries specified by the page size and also returns a cookie issued on the next client request to get the next page of results. The client then issues a search, with the cookie included, optionally resetting the page size. The server then responds by returning the results, up to the specified number of entries. To instruct the function to return the results directly, use the synchronous routine
[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s).

Multithreading: Calls to **ldap_search_ext** are thread-safe.

## See also

[Change Notifications in Active Directory](https://learn.microsoft.com/windows/desktop/AD/change-notifications-in-active-directory-domain-services)

[Extended Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/extended-controls)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_search](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search)

[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s)