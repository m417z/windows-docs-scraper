# ber_bvdup function

## Description

The **ber_bvdup** function creates a copy of the supplied
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structure.

## Parameters

### `pBerVal` [in]

Pointer to the source [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structure.

## Return value

If the function succeeds, the return value is a pointer to the newly allocated [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structure.

If the function fails, it returns a **NULL** pointer.

## Remarks

The allocated [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) should be freed with [ber_bvfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_bvfree).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)