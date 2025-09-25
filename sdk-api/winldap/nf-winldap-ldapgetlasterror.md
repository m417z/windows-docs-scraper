# LdapGetLastError function

## Description

The **LdapGetLastError** function retrieves the last error code returned by an LDAP call.

## Return value

An LDAP error code.

## Remarks

The **LdapGetLastError** function returns the LDAP error code for the last LDAP operation on the thread that is calling it. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for a list of possible error codes.

Multithreading: The **LdapGetLastError** function is thread-safe.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)