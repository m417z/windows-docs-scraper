# ldap_parse_sort_controlW function

## Description

The **ldap_parse_sort_control** function parses the sort control returned by the server.

## Parameters

### `ExternalHandle` [in]

The session handle.

### `Control` [in]

The control returned from the server, as obtained from a call to
[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result).

### `Result` [out]

The result code.

### `Attribute` [out]

A pointer to a null-terminated string that contains the name of the attribute that caused the operation to fail.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

When the server returns the results, it returns a control in the SearchResultDone message. Call **ldap_parse_sort_control** to parse this sort control.

If the sort operation failed, the server may return the name of the attribute that caused the failure. In this case, call
[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree) to free the attribute value

> [!NOTE]
> The winldap.h header defines ldap_parse_sort_control as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree)

[ldap_parse_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_result)