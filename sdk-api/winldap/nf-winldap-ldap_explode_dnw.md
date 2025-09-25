# ldap_explode_dnW function

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

> [!NOTE]
> The winldap.h header defines ldap_explode_dn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free)