# ldap_dn2ufnW function

## Description

The **ldap_dn2ufn** function converts a distinguished name to a user-friendly format.

## Parameters

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name to convert.

## Return value

If the function is successful, the user-friendly name is returned as a pointer to a null-terminated character string.

If the function fails, **NULL** is returned.

## Remarks

When given an entry distinguished name, **ldap_dn2ufn** returns a null-terminated character string that contains the entry name in a user-friendly format. The composition of the user-friendly format is based on the format described in RFC 1781, and depends upon the directory service implementation and the type of entry. The return value remains in memory-allocated space until you call
[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree).

> [!NOTE]
> The winldap.h header defines ldap_dn2ufn as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree)