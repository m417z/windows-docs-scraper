# ldap_first_attributeA function

## Description

For a given directory entry, the **ldap_first_attribute** function returns the first attribute.

## Parameters

### `ld` [in]

The session handle.

### `entry` [in]

The entry whose attributes are to be stepped through, as returned by
[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry) or
[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry).

### `ptr` [out]

The address of a pointer used internally to track the current position in the entry.

## Return value

A pointer to a null-terminated string. If the function succeeds, it returns a pointer to an allocated buffer that contains the current attribute name. When there are no more attributes to step through, it returns **NULL**. The session error parameter in the LDAP data structure is set to 0 in either case.

If the function fails, it returns **NULL** and sets the session error parameter in the LDAP data structure to the LDAP error code.

## Remarks

Use
**ldap_first_attribute** in conjunction with
[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute) to step through the list of attribute types returned with an entry. You can then pass these attribute names in a call to
[ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values) to retrieve their associated values.

A call to
**ldap_first_attribute** allocates, and returns through the *ptr* parameter, a pointer to a
[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure. Pass this pointer to
[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute) to track the current position in the list of attributes. When you have finished stepping through a list of attributes and *ptr* is non-**NULL**, free the pointer by calling
[ber_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_free)( ptr, 0 ). Be aware that you must pass the second parameter as 0 (zero) in this call.

Both
**ldap_first_attribute** and
[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute) return a pointer to an allocated buffer containing the current attribute name. Free this buffer, when no longer required, by calling
[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree). Because this buffer is overwritten on the next call to either
**ldap_first_attribute** or
**ldap_next_attribute**, the user should make a copy of the attribute name if it must be preserved for processing.

## See also

[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Searching a Directory](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/searching-a-directory)

[ber_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_free)

[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry)

[ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values)

[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree)

[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute)

[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry)