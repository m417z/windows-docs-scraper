# ldap_value_freeA function

## Description

The **ldap_value_free** function frees a structure returned by
[ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values).

## Parameters

### `vals`

The structure to free.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see [Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Call **ldap_value_free** to free a structure returned by [ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Searching a Directory](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/searching-a-directory)

[ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values)