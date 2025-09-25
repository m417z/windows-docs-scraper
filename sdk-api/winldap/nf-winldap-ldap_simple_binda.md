# ldap_simple_bindA function

## Description

The **ldap_simple_bind** functionasynchronously authenticates a client to a server, using a plaintext password.

**Caution** This function sends the name and password without encrypting them, and therefore someone eavesdropping on the network could read the password. Unless a TLS (SSL) encrypted session has been established, do not use this function. For more information about how to set up an encrypted session, see [Initializing a Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/initializing-a-session).

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

The name of the user to bind as. The bind operation uses the *dn* and *passwd* parameters to authenticate the user.

### `passwd` [in]

The password of the user specified in the *dn* parameter.

## Return value

If the function succeeds, it returns the message ID of the operation initiated.

If the function fails, it returns -1 and sets the session error parameters in the LDAP data structure.

## Remarks

The **ldap_simple_bind** function initiates a simple asynchronous bind operation to authenticate a client to an LDAP server. Subsequent bind calls can be used to reauthenticate using the same connection.

To authenticate as a specific user, provide both the name of the entry (user) and the password for that entry. To authenticate an anonymous user, when no access permissions are required, pass **NULL** to both the *dn* and *passwd* parameters.

As an asynchronous function, **ldap_simple_bind** returns a message ID for the operation. Call
[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result) with the message ID to get the result of the operation. To cancel an asynchronous bind operation before it has completed, call
[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon). Be aware that if an LDAP 2 server is contacted, do not attempt other operations over the connection until the bind call has successfully completed.

To return the results directly, use the synchronous routine
[ldap_simple_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind_s).

Multithreading: Bind calls are not safe because they apply to the connection as a whole. Use caution if threads share connections and try to thread binds with other operations.

**Note** The Microsoft LDAP client uses a default timeout value of 120 seconds (2 minutes) for each bind-response roundtrip. This timeout value can be changed using the **LDAP_OPT_TIMELIMIT** session option. Other operations do not have a timeout unless specified using
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option).

When all of the operations on the session handle are completed, terminate the session by passing the [LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) session handle to the [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) function. Also, if the **ldap_simple_bind** call fails, the session handle should be freed with a call to **ldap_unbind** when no longer required for error recovery.

The **ldap_simple_bind** function is designed to bind to the local domain. The function cannot be used for cross forest authentication.

## See also

[Establishing an LDAP Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/establishing-an-ldap-session)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ldap_abandon](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_abandon)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind_s)

[ldap_result](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_result)

[ldap_simple_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind_s)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)