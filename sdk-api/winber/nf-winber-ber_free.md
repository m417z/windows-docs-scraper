# ber_free function

## Description

The **ber_free** function frees a
[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure that was previously allocated with
[ber_alloc_t](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_alloc_t),
[ber_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_init), or the
[ldap_first_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_attribute)/
[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute) search functions.

## Parameters

### `pBerElement` [in]

Pointer to the [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure to be deallocated.

### `fbuf` [in]

Must be set to 0 if freeing structures allocated by
[ldap_first_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_attribute)/
[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute), otherwise it must be set to 1.

## Return value

None.

## See also

[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ber_alloc_t](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_alloc_t)