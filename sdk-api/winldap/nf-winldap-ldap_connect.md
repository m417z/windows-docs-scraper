# ldap_connect function

## Description

The **ldap_connect** function establishes a connection with the server.

## Parameters

### `ld` [in]

The session handle obtained from [ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init).

### `timeout` [in]

A pointer to an [LDAP_TIMEVAL](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_timeval) structure that specifies the number of seconds to spend in an attempt to establish a connection before a timeout. If **NULL**, the function uses a default timeout value.

## Return value

If the function succeeds, **LDAP_SUCCESS** is returned.

If the function fails, an error code is returned. For more information, see [Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values).

## Remarks

Although it is not required that a client call **ldap_connect** to establish a connection to the server, it is good programming practice to do so. If the connection does not exist, other functions, for example, [ldap_bind_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_bind_s), perform the call internally. However, if you have to troubleshoot this part of your application, establishing the connection prior to making the call to some other function, for example **ldap_bind_s**, will also separate the possible problems if the connection fails. Alternately, you can specify additional options on the connection block. For example, a client can call
[ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init) to initialize a session, then call
**ldap_connect**, with a non-**NULL** timeout parameter value, to connect to the server with a specified time-out.

If the call to **ldap_connect** succeeds, the client is connected to the LDAP server as an anonymous user. The session handle should be freed with a call to [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) when it is no longer required.

If the **ldap_connect** call fails, the session handle should be freed with a call to [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) when no longer required for error recovery.

## See also

[Establishing an LDAP Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/establishing-an-ldap-session)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LDAP_TIMEVAL](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_timeval)

[Return Values](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/return-values)

[ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)