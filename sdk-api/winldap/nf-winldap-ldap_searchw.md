# ldap_searchW function

## Description

The **ldap_search** function searches the LDAP directory and returns a requested set of attributes for each matched entry.

## Parameters

### `ld` [in]

A session handle.

### `base` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry at which to start the search.

### `scope` [in]

A data type that specifies one of the following values to indicate the search scope.

#### LDAP_SCOPE_BASE

Search only the base entry.

#### LDAP_SCOPE_ONELEVEL

Search all entries in the first level below the base entry, excluding the base entry.

#### LDAP_SCOPE_SUBTREE

Search the base entry and all entries in the tree below the base.

### `filter` [in]

A pointer to a null-terminated string that specifies the search filter. For more information, see
[Search Filter Syntax](https://learn.microsoft.com/windows/desktop/ADSI/search-filter-syntax).

### `attrs` [in]

A null-terminated array of null-terminated strings that indicate which attributes to return for each matching entry. Pass **NULL** to retrieve available attributes.

### `attrsonly` [in]

Boolean value that should be zero if both attribute types and values are to be returned, nonzero if only types are required.

##### - scope.LDAP_SCOPE_BASE

Search only the base entry.

##### - scope.LDAP_SCOPE_ONELEVEL

Search all entries in the first level below the base entry, excluding the base entry.

##### - scope.LDAP_SCOPE_SUBTREE

Search the base entry and all entries in the tree below the base.

## Return value

If the function succeeds, it returns the message ID of the search operation.

If the function fails, it returns –1 and sets the session error parameters in the LDAP data structure.

## Remarks

The **ldap_search** function initiates an asynchronous search operation.

Use the
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option) function with the *ld* session handle to set the LDAP_OPT_SIZELIMIT, LDAP_OPT_TIMELIMIT, and LDAP_OPT_DEREF options that determine how the search is performed. For more information, see
[Session Options](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/session-options).

As an asynchronous function, **ldap_search** returns a message ID for the operation. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to get the result of the operation. To cancel an asynchronous search operation before it has completed, call
[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon).

To have the function return the results directly, use the synchronous routine
[ldap_search_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_s). Use
[ldap_search_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext) or
[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s) to implement support for LDAP 3 server and client controls.

Multithreading: Calls to **ldap_search** are thread-safe, provided that
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) is used to retrieve the actual session error code when the function call returns the -1 failure code.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation, by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines, before attempting other operations.

> [!NOTE]
> The winldap.h header defines ldap_search as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_search_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext)

[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s)

[ldap_search_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_s)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)