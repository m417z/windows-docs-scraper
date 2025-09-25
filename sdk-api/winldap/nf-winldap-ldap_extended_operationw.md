# ldap_extended_operationW function

## Description

The **ldap_extended_operation** function enables you to pass extended LDAP operations to the server.

## Parameters

### `ld` [in]

The session handle.

### `Oid` [in]

A pointer to a null-terminated string that contains the dotted object identifier text string that names the request.

### `Data` [in]

The arbitrary data required by the operation. If **NULL**, no data is sent to the server.

### `ServerControls` [in]

Optional. A list of LDAP server controls. Set this parameter to **NULL**, if not used.

### `ClientControls` [in]

Optional. A list of client controls. Set this parameter to **NULL**, if not used.

### `MessageNumber` [out]

The message ID for the request.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_extended_operation** function enables a client to send an extended request (free for all) to an LDAP 3 (or later) server. The functionality is open and the client request can be for any operation.

As an asynchronous function, **ldap_extended_operation** returns a message ID for the operation. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to get the result of the operation. To cancel an asynchronous operation, call
[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon).

Because of the open nature of the request, the client must call
[ldap_close_extended_op](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_close_extended_op) to terminate the request.

Multithreading: The **ldap_extended_operation** function is thread-safe.

> [!NOTE]
> The winldap.h header defines ldap_extended_operation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon)

[ldap_close_extended_op](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_close_extended_op)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)