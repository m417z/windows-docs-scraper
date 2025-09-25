# ldap_memfreeW function

## Description

The **ldap_memfree** function frees memory allocated from the LDAP heap.

## Parameters

### `Block` [in]

A pointer to a null-terminated string that contains a pointer to memory allocated by the LDAP library.

## Return value

None.

## Remarks

Call **ldap_memfree** to free strings, such as the attribute names returned by **ldap_*_attribute**, or distinguished names returned by
[ldap_get_dn](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_dn). Do not free the static buffers used by
[ldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_open),
[ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values), and others.

> [!NOTE]
> The winldap.h header defines ldap_memfree as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_get_dn](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_dn)

[ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values)

[ldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_open)