# ldap_explode_dnA function

## Description

The **ldap_explode_dn** function breaks up an entry name into its component parts.

## Parameters

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name to explode. The string that this pointer refers to cannot be a constant string.

### `notypes` [in]

Indicates whether the type information components should be removed.

## Return value

If the function succeeds, it returns a null-terminated character array containing the relative distinguished name components of the distinguished name supplied.

## Remarks

Call **ldap_explode_dn** to separate a distinguished name into its component parts. Set the *notypes* parameter to a nonzero value to remove type information, such as "cn=" from the components. The components of the relative distinguished name are returned in a character array. Free this array when it is no longer needed by calling
[ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free).

Calling **ldap_explode_dn** with a pointer to a constant string will cause the function to fail.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free)