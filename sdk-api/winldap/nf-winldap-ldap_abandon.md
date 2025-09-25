# ldap_abandon function

## Description

A client calls **ldap_abandon** to cancel an in-process asynchronous LDAP call.

## Parameters

### `ld` [in]

The session handle.

### `msgid` [in]

The message ID of the call to be canceled. Asynchronous functions, such as [ldap_search](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search) and [ldap_modify](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_modify), return this message ID when they initiate an operation.

## Return value

If the function succeeds, that is, if the cancel operation is successful, the return value is zero.

If the function fails, the return value is –1.

## Remarks

The **ldap_abandon** function first verifies that the operation has been completed. If it has, the message ID is deleted; otherwise, the call goes to the server to cancel the operation. Be aware that a successful call to **ldap_abandon** destroys the message ID. Therefore, you cannot call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) to obtain results with that message ID, even if the server completed the operation.

There is no server response to **ldap_abandon**; thus, there is no guarantee that the call reached the server.

Multithreading: Calls to **ldap_abandon** are thread-safe.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)