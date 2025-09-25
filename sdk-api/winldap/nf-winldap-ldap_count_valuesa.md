# ldap_count_valuesA function

## Description

The **ldap_count_values** function counts the number of values in a list.

## Parameters

### `vals` [in]

An array of null-terminated strings (values) returned by
[ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values).

## Return value

This function returns the number of values in the array. There is no error return.

If a **NULL** pointer is passed as the argument, 0 is returned. If an invalid argument is passed, the value returned is undefined.

## Remarks

The **ldap_count_values** function returns the number of values in an array of strings. To count binary values in an array of
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structures, call
[ldap_count_values_len](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_count_values_len).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[Searching a Directory](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/searching-a-directory)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)

[ldap_count_values_len](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_count_values_len)

[ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values)