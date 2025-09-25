# ldap_check_filterA function

## Description

The **ldap_check_filter** function is used to verify filter syntax.

## Parameters

### `ld` [in]

The session handle.

### `SearchFilter` [in]

A pointer to a wide, null-terminated string that contains the name of the filter to check.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Use **ldap_check_filter** to verify the syntax of a search filter before initiating a search. This syntax check does not perform a full verification of the search filter syntax against RFC 2254 rules. Rather, it verifies that the filter meets the minimum syntactic requirements for encoding required by the wldap32 search-filter-encoding routines. As a result, a search filter can pass an **ldap_check_filter** operation, and can be encoded by wldap32, but the server may still detect a RFC 2254 compliance violation and reject the search filter.

> [!NOTE]
> The winldap.h header defines ldap_check_filter as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_search](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search)