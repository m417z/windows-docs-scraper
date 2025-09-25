# ldap_search_init_pageA function

## Description

The **ldap_search_init_page** function initializes a search block for a simple paged-results search. This function is supported in LDAP 3.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `DistinguishedName` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry at which to start the search.

### `ScopeOfSearch` [in]

A data type that specifies one of the following values to indicate the scope of the search.

#### LDAP_SCOPE_BASE

Search the base entry only.

#### LDAP_SCOPE_ONELEVEL

Search all entries in the first level below the base entry, excluding the base entry.

#### LDAP_SCOPE_SUBTREE

Search the base entry and all entries in the tree below the base.

### `SearchFilter` [in]

A pointer to a null-terminated string that specifies the search filter. For more information, see
[Search Filter Syntax](https://learn.microsoft.com/windows/desktop/ADSI/search-filter-syntax).

### `AttributeList` [in]

A null-terminated array of null-terminated strings indicating which attributes to return for each matching entry. Pass **NULL** to retrieve all available attributes.

### `AttributesOnly` [in]

A Boolean value that should be zero if both attribute types and values are to be returned, nonzero if only types are to be returned.

### `ServerControls` [in]

A list of LDAP server controls.

### `ClientControls` [in]

A list of client controls.

### `PageTimeLimit` [in]

The time value, in seconds, that the client will wait for the server to return a page.

### `TotalSizeLimit` [in]

The maximum number of entries the client will accept. The *TotalSizeLimit* value affects only the individual pages within the paged search (not the overall paged search). So if *TotalSizeLimit* is greater than page size, then *TotalSizeLimit* will have no effect.

### `SortKeys` [in]

A pointer to an
[LDAPSortKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapsortkeya) structure, which specifies the attribute type, the ordering rule, and the direction for the search.

##### - ScopeOfSearch.LDAP_SCOPE_BASE

Search the base entry only.

##### - ScopeOfSearch.LDAP_SCOPE_ONELEVEL

Search all entries in the first level below the base entry, excluding the base entry.

##### - ScopeOfSearch.LDAP_SCOPE_SUBTREE

Search the base entry and all entries in the tree below the base.

## Return value

If the function succeeds, it returns a pointer to an
[LDAPSearch](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366129(v=vs.85)) structure.

If the function fails, the return value is **NULL**. Use
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) or
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to retrieve the error code.

Call the [ldap_search_abandon_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_abandon_page) to free the returned structure.

## Remarks

The
**ldap_search_init_page** function creates an LDAPSearch structure for managing paged searches and returns a handle to the structure. The
[ldap_get_next_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page),
[ldap_get_next_page_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page_s), and
[ldap_get_paged_count](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_paged_count) functions require this search handle as a parameter. When the paged search is completed, call
[ldap_search_abandon_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_abandon_page) to free this structure and its handle.

To determine whether a server supports paged-results searches, check the supportedControl property off of the root for an object identifier (OID) of 1.2.840.113556.1.4.319.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[LDAPSearch](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366129(v=vs.85))

[LDAPSortKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapsortkeya)

[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror)

[ldap_get_next_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page)

[ldap_get_next_page_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_next_page_s)

[ldap_search_abandon_page](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_abandon_page)