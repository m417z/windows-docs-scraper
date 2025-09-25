# ldap_result function

## Description

The **ldap_result** function obtains the result of an asynchronous operation.

## Parameters

### `ld` [in]

The session handle.

### `msgid` [in]

The message ID of the operation, or the constant LDAP_RES_ANY if any result is required.

### `all` [in]

Specifies how many messages are retrieved in a single call to **ldap_result**. This parameter only has meaning for search results. Pass the constant LDAP_MSG_ONE (0x00) to retrieve one message at a time. Pass LDAP_MSG_ALL (0x01) to request that all results of a search be received before returning all results in a single chain. Pass LDAP_MSG_RECEIVED (0x02) to indicate that all results retrieved so far should be returned in the result chain.

### `timeout` [in]

A timeout that specifies how long, in seconds, to wait for results to be returned. A **NULL** value causes **ldap_result** to block until results are available. A timeout value of zero seconds specifies a polling behavior.

### `res` [out]

Contains the result(s) of the operation. Any results returned should be freed with a call to [ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree) once they are no longer required by the application.

## Return value

If the function succeeds, it returns one of the following values to indicate the type of the first result in the *res* parameter. If the time-out expires, the function returns 0.

If the function fails, it returns –1 and sets the session error parameters in the LDAP data structure.

## Remarks

The **ldap_result** function retrieves the result of a previous, asynchronously initiated operation. Be aware that, depending on the way it is called, **ldap_result** may actually return a list or "chain" of messages.

For connectionless LDAP, you must pass both an LDAP connection handle and a message ID to ensure that you get the correct results. The LDAP run time continues to send the request until it receives a response.

Multithreading: Calls to **ldap_result** are thread safe.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_msgfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_msgfree)