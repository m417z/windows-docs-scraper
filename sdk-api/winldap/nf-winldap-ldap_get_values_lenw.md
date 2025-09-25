# ldap_get_values_lenW function

## Description

The **ldap_get_values_len** function retrieves the list of values for a given attribute.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `Message` [in]

Handle to the
[LDAPMessage](https://learn.microsoft.com/windows/desktop/api/winldap/ns-winldap-ldapmessage) structure.

### `attr` [in]

A pointer to a null-terminated string that contains the attribute whose values are to be retrieved.

## Return value

If the function succeeds, it returns a null-terminated list of pointers to
[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) structures that contain the values of the specified attribute. If no attribute values were found, it returns **NULL**. The session error parameter in the LDAP data structure is set to 0 in either case.

If the function fails, it returns **NULL** and the session error parameter in the LDAP data structure is set to the LDAP error code.

## Remarks

Use **ldap_get_values_len** when parsing a search response to obtain the value or values of an attribute. Use this function when the attribute contains binary data; for attributes whose values are null-terminated character strings, use
[ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values).

The entry is obtained by calling
[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry) or
[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry). The attribute should be one returned by a call to
[ldap_first_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_attribute),
[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute), or a caller-supplied string (for example, "mail").

Call
[ldap_value_free_len](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free_len) to release the returned value when it is no longer required.

> [!NOTE]
> The winldap.h header defines ldap_get_values_len as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAPMessage](https://learn.microsoft.com/windows/desktop/api/winldap/ns-winldap-ldapmessage)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)

[ldap_first_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_attribute)

[ldap_first_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_first_entry)

[ldap_get_values](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_values)

[ldap_next_attribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_attribute)

[ldap_next_entry](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_next_entry)

[ldap_value_free_len](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free_len)