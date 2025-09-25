# ber_bvfree function

## Description

The **ber_bvfree** function frees a
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structure.

## Parameters

### `bv`

TBD

#### - pBerVal [in]

Pointer to the [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structure to be deallocated.

## Return value

None.

## Remarks

Applications should not call this function to free [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structures that they themselves have allocated.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)