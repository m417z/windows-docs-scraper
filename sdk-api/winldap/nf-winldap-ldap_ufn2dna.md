# ldap_ufn2dnA function

## Description

The **ldap_ufn2dn** function converts a user-friendly name to a distinguished name.

## Parameters

### `ufn` [in]

Pointer to a null-terminated string that contains the user-friendly name to convert.

### `pDn` [out]

Pointer to a variable that receives a pointer to a null-terminated string that contains the resulting distinguished name.

If the *pDn* parameter returns non-**NULL**, free it with a call to
[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree).

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_ufn2dn** function attempts to normalize a user-specified name to a distinguished name. For example, consider an LDAP directory format for a common name of *LastName***,** *FirstName*. Given a directory name of "Jeff Smith," **ldap_ufn2dn** will attempt to normalize this to "Smith, Jeff." The function follows RFC 1781; add CN= if not present, add OU= if none present, and so on. If it runs into any errors while normalizing, the function returns a copy of what was passed. It then allocates the output string from the LDAP memory pool.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree)