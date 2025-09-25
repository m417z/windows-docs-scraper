# ldap_value_free_len function

## Description

The **ldap_value_free_len** frees
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structures that were returned by
[ldap_get_values_len](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values_len).

## Parameters

### `vals` [in]

The structure to free.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

Call **ldap_value_free_len** to free [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structures returned by [ldap_get_values_len](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values_len).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)

[ldap_get_values_len](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values_len)