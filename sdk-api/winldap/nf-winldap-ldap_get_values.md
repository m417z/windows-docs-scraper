# ldap_get_values function

## Description

The **ldap_get_values** function retrieves the list of values of a given attribute.

## Parameters

### `ld` [in]

The session handle.

### `entry` [in]

The entry from which to retrieve values.

### `attr` [in]

A pointer to a null-terminated string that contains the attribute whose values are to be retrieved.

## Return value

If the function succeeds, it returns a null-terminated list of pointers to values. If no attribute values were found, it usually returns **NULL**. But in some cases it may return a list one pointer that is **NULL**. Always make sure to use [ldap_count_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_count_values) to get the count of values in the returned list, as noted in Remarks. The session error parameter in the LDAP data structure is set to 0 in either case.

If the function fails, it returns **NULL** and the session error parameter in the LDAP data structure is set to the LDAP error code.

## Remarks

Use **ldap_get_values** when parsing a search response to obtain the value or values of an attribute. Use this function only when the attribute contains null-terminated character strings; for binary data, use
[ldap_get_values_len](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values_len) instead.

The entry is obtained by calling
[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry) or
[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry). The attribute should be one returned by a call to
[ldap_first_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_attribute),
[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute), or a caller-supplied string (for example, "mail").

Use [ldap_count_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_count_values) to get the count of values in the returned list.
Call
[ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free) to release the returned value when it is no longer required.

Certain LDAP servers place limits on the number of attribute string values that are returned in a single call. For more information about using range retrieval specifiers, see [Searching Using Range Retrieval](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/searching-using-range-retrieval).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Searching a Directory](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/searching-a-directory)

[ldap_first_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_attribute)

[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry)

[ldap_get_values_len](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values_len)

[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute)

[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry)

[ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free)