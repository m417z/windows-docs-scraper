# ber_init function

## Description

The **ber_init** function allocates a new
[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure containing the data taken from the supplied
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structure.

## Parameters

### `pBerVal` [in]

Pointer to the source [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structure.

## Return value

If the function succeeds, the return value is a pointer to the newly allocated [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

If the function fails, it returns a **NULL** pointer.

## Remarks

Call
[ber_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_free) to free a [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure allocated with this function.

## See also

[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ber_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_free)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)