# ldap_controls_freeA function

## Description

The **ldap_controls_free** function frees
an array of [LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structures.

## Parameters

### `Controls` [in]

The array of [LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structures to free.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Use this function to free an array of [LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola)
structures previously allocated by LDAP function calls, such as the array returned by
[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result).

**Note** This function should only be used to free controls created internally by LDAP API functions. It is not used
to free memory that is explicitly allocated by the user application.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result)