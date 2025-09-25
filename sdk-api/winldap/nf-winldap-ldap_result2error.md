# ldap_result2error function

## Description

The **ldap_result2error** function parses a message and returns the error code.

## Parameters

### `ld` [in]

The session handle.

### `res` [in]

The result of an LDAP operation, as returned by

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result), or one of the synchronous API operation calls.

### `freeit` [in]

Determines whether the [LDAPMessage](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldapmessage), pointed to by the *res* parameter, is freed. Setting *freeit* to **TRUE** frees the message by calling the
[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree) function.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Multithreading: Calls to **ldap_result2error** are thread-safe.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)