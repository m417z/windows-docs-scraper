# ldap_compare_s function

## Description

Use the **ldap_compare_s** function to determine whether
an attribute for a given entry holds a known value.

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

A pointer to a null-terminated string that contains the distinguished name of the entry.

### `attr` [in]

A pointer to a null-terminated string that contains the attribute to compare.

### `value` [in]

A pointer to a null-terminated string that contains the string attribute value to compare to the attribute
value.

## Return value

If the function succeeds, and the attribute and known values match, the return value is
**LDAP_COMPARE_TRUE**. If the values do not match, the return value is
**LDAP_COMPARE_FALSE**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

The **ldap_compare_s** function initiates a synchronous
compare operation, comparing the value of an attribute to a known string value. Use
[ldap_compare_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare_ext_s) if you need to compare binary
values. Use [ldap_compare](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare) or
[ldap_compare_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare_ext) to carry out an asynchronous compare
operation.

Multithreading: Calls to **ldap_compare_s** are
thread-safe.

**Note** When connecting to an LDAP 2 server, the application must perform a bind operation (by calling one of the
[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind) or
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) routines) before attempting any
other operations.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_compare](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare)

[ldap_compare_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare_ext)

[ldap_compare_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_compare_ext_s)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)