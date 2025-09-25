# ldap_msgfree function

## Description

The **ldap_msgfree** function frees the results obtained from a previous call to
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result), or to one of the synchronous search routines.

## Parameters

### `res` [in]

The result, or chain of results, to free.

## Return value

Returns **LDAP_SUCCESS**.

## Remarks

Call **ldap_msgfree** to free the result structure pointed to by the *res* parameter.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s)

[ldap_search_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_s)

[ldap_search_st](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_st)