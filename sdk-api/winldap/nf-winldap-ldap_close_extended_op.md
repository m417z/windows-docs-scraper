# ldap_close_extended_op function

## Description

The **ldap_close_extended_op** function ends a request that was made by calling
[ldap_extended_operation](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_extended_operation).

## Parameters

### `ld` [in]

The session handle.

### `MessageNumber` [in]

The message ID for the request.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

After sending an extended request, or a series of such requests, to an LDAP server, call **ldap_close_extended_op** to notify the server that the client has finished making requests. Be aware that these extended operation functions are available only with LDAP, version 3 or later. These functions allow a client to send a "free-for-all" request, for any sort of data or action, to an LDAP 3 server.

Multithreading: Calls to **ldap_close_extended_op** are thread-safe.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_extended_operation](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_extended_operation)