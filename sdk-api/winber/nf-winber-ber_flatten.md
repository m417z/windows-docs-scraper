# ber_flatten function

## Description

The **ber_flatten** function allocates a new
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structure containing the data taken from the supplied
[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

## Parameters

### `pBerElement` [in]

Pointer to the source [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

### `pBerVal` [out]

Pointer to the newly allocated [berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structure, which should be freed using
[ber_bvfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_bvfree).

## Return value

The function returns 0 on success and -1 on failure.

## Remarks

The use of **ber_flatten** on a [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) in which all **{** and **}** format modifiers have not been properly matched will cause the function to return an error.

## See also

[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ber_bvfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_bvfree)

[ber_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_init)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)