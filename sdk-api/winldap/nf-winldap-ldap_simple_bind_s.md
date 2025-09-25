# ldap_simple_bind_s function

## Description

The **ldap_simple_bind_s** function synchronously authenticates a client to a server, using a plaintext password.

**Caution** This function sends the name and password without encrypting them, and an unauthorized user, on the network, could read the password. Unless a TLS (SSL) encrypted session has been established, do not this function. For more information about how to set up an encrypted session, see [Initializing a Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/initializing-a-session).

## Parameters

### `ld` [in]

The session handle.

### `dn` [in]

The name of the user to bind as. The bind operation uses the *dn* and *passwd* parameters to authenticate the user.

### `passwd` [in]

The password of the user specified in the *dn* parameter.

## Return value

If the function succeeds, the return value is **LDAP_SUCCESS**.

If the function fails, it returns an error code. For more information, see
[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

The **ldap_simple_bind_s** function initiates a simple synchronous bind operation to authenticate a client to an LDAP server. Subsequent bind calls can be used to reauthenticate using the same connection.

Upon completion of the bind operation, **ldap_simple_bind_s** returns to the caller. Use
[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind) if you prefer to have the operation carried out asynchronously. Be aware that if an LDAP 2 server is contacted, do not attempt other operations over the connection until the bind call has completed successfully.

Multithreading: Bind calls are unsafe because they apply to the connection as a whole. Use caution if threads share connections, and try to thread binds with other operations.

**Note** The Microsoft LDAP client uses a default timeout value of 120 seconds (2 minutes) for each bind-response roundtrip. This timeout value can be changed using the **LDAP_OPT_TIMELIMIT** session option. Other operations do not have a timeout unless specified using
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option).

When all of the operations on the session handle are completed, terminate the session by passing the [LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) session handle to the [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) function. Also, if the **ldap_simple_bind_s** call fails, the session handle should be freed with a call to **ldap_unbind** when no longer required for error recovery.

## See also

[Establishing an LDAP Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/establishing-an-ldap-session)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind)

[ldap_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind_s)

[ldap_simple_bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_simple_bind)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)