# ber_bvecfree function

## Description

The **ber_bvecfree** function frees an array of
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structures.

## Parameters

### `pBerVal` [in]

Pointer to a NULL-terminated array of [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structures to be deallocated.

## Return value

None.

## Remarks

Use this function only to free an array of
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structures returned by [ber_scanf](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_scanf) with the **V** character included in the format string.

An application should not call this function to free a [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structures that it has allocated.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)