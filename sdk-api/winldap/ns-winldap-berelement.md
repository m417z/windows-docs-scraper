# BerElement structure

## Description

A **BerElement** structure is a C++ class object that performs basic encoding rules (BER) encoding.

## Members

### `opaque`

Pointer to an opaque buffer. Do not attempt to access it.

## Remarks

This is an opaque data structure that the
[ldap_first_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_attribute) function allocates and returns to indicate the current position during a traversal of an attribute list. Pass the pointer to this structure to the
[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute) function.

**Caution** When allocated by one of the two previous functions, you do not free the memory associated with this structure or its pointer when the **BerElement** is no longer required.

A **BerElement** structure can also be allocated by calling the [ber_alloc_t](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_alloc_t) or the [ber_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_init) function. In such cases, free the memory allocated to the **BerElement** structure by using the [ber_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_free) function.

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures)

[ldap_first_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_attribute)

[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute)