# ldap_err2stringW function

## Description

The **ldap_err2string** function converts a numeric LDAP error code into a null-terminated character string that describes the error.

## Parameters

### `err` [in]

An LDAP error code as returned by another LDAP function.

## Return value

If the function succeeds, a pointer to a null-terminated character string that describes the error, is returned.

If the function fails, a pointer to **NULL** is returned.

## Remarks

Call **ldap_err2string** to convert any numeric LDAP error code into an informative, null-terminated character string message that describes the error. Be aware that some of the asynchronous calls return -1. In this case, use [LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) to retrieve the LDAP error code, and then use **ldap_err2string** on that value.

The return value is a static pointer to the character string. Do not free this string.

> [!NOTE]
> The winldap.h header defines ldap_err2string as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)