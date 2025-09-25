# ldap_control_freeW function

## Description

The **ldap_control_free** function frees an
[LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structure.

## Parameters

### `Control` [in]

The [LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structure to free.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Use this function to free an [LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola) structure
previously allocated by an LDAP function call, such as one allocated by a call to
[ldap_create_page_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_page_control) or
[ldap_create_vlv_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_vlv_controla).

**Note** This function should only be used to free a control created internally by LDAP API functions. It is not used
to free memory that is explicitly allocated by the user program.

> [!NOTE]
> The winldap.h header defines ldap_control_free as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_create_page_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_page_control)

[ldap_create_vlv_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_vlv_controla)