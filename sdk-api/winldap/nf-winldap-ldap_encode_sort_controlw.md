# ldap_encode_sort_controlW function

## Description

The **ldap_encode_sort_control** function formats a list of sort keys into a search control. This function is obsolete. Instead, use
[ldap_create_sort_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_sort_control).

## Parameters

### `ExternalHandle` [in]

The session handle.

### `SortKeys` [in]

A list of
[LDAPSortKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapsortkeya) structures.

### `Control` [out]

Pointer to the new control.

### `Criticality` [in]

Notifies the server whether this control is critical to the search.

## Return value

If the call completed successfully, **LDAP_SUCCESS** is returned. Other standard LDAP return values, such as **LDAP_NO_MEMORY** or **LDAP_PARAM_ERROR**, may also be returned.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAPSortKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapsortkeya)

[ldap_create_sort_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_sort_control)

## Remarks

> [!NOTE]
> The winldap.h header defines ldap_encode_sort_control as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).