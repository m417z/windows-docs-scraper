# ldap_parse_resultA function

## Description

The **ldap_parse_result** function parses responses from the server and returns the appropriate fields.

## Parameters

### `Connection` [in]

The session handle.

### `ResultMessage` [in]

The result of an LDAP operation as returned by one of the synchronous operation calls or by
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) for an asynchronous operation.

### `ReturnCode` [out, optional]

Indicates the outcome of the server operation that generated the original result message. Pass **NULL** to ignore this field.

### `MatchedDNs` [out, optional]

A pointer to a wide, null-terminated string. In the case of a return of **LDAP_NO_SUCH_OBJECT**, this result parameter is filled in with a distinguished name indicating how much of the name in the request was recognized. Pass **NULL** to ignore this field.

### `ErrorMessage` [out, optional]

A pointer to a wide, null-terminated string that contains the contents of the error message field from the *ResultMessage* parameter. Pass **NULL** to ignore this field.

### `Referrals` [out, optional]

A pointer to a wide, null-terminated string that contains the contents of the referrals field from the *ResultMessage* parameter, indicating zero or more alternate LDAP servers where the request should be retried. Pass **NULL** to ignore this field.

### `ServerControls` [out, optional]

This result parameter is filled in with an allocated array of controls copied from the *ResultMessage* parameter.

### `Freeit` [in]

Determines whether the *ResultMessage* parameter is freed. You can pass any nonzero value to the *Freeit* parameter to free the *ResultMessage* pointer when it is no longer needed, or you can call
[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree) to free the result later.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. See
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values) for more information.

## Remarks

The **ldap_parse_result** function traverses a chain of server responses looking for result messages to parse. Use this function if you want to access the referrals, matching distinguished names, or server controls returned. The function skips over messages of type **LDAP_RES_SEARCH_ENTRY** and **LDAP_RES_SEARCH_REFERENCE**.

When they are no longer needed, free the *ErrorMessage* and *MatchedDNs* strings by calling
[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree). Free the *Referrals* array by calling
[ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free). Free the *ServerControls* by calling
[ldap_controls_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_controls_free).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_controls_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_controls_free)

[ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree)

[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_value_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_value_free)