# ldap_compare_ext_s function

## Description

Use the **ldap_compare_ext_s** function to determine if an attribute, for a given entry, holds a known value.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry to compare.

### `Attr` [in]

A pointer to a null-terminated string that contains the attribute to compare.

### `Value` [in]

A pointer to a null-terminated string that contains the string attribute value to be compared to the attribute value. Set to **NULL** if not used.

### `Data` [in]

The
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) attribute value to be compared to the attribute value. Set to **NULL** if not used.

### `ServerControls` [in]

Optional. A list of LDAP server controls. Set to **NULL** if not used.

### `ClientControls` [in]

Optional. A list of LDAP client controls. Set to **NULL** if not used.

## Return value

If the function succeeds, and the attribute and known values match, **LDAP_COMPARE_TRUE** is returned; if the values do not match, **LDAP_COMPARE_FALSE** is returned.

If the function fails, an error code is returned. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_compare_ext_s** function initiates a synchronous compare operation, comparing the value of an attribute to a known value. The parameters and effects of **ldap_compare_ext_s** subsume those of
[ldap_compare_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare_s). The extended routine includes additional parameters to support client and server controls, and comparison of binary values.

Use the *Value* parameter for comparing string values or use the *Data* parameter for comparing raw binary data. Set the unused parameter to **NULL**. If neither parameter is **NULL**, the compare operation will use the value in the *Data* parameter.

Multithreading: Calls to **ldap_compare_ext_s** are thread-safe.

## See also

[Extended Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/extended-controls)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[Using Controls](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/using-controls)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)

[ldap_compare_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare_s)