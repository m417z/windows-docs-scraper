# cldap_openA function

## Description

The **cldap_open** function establishes a session with an LDAP server over a connectionless User Datagram Protocol (UDP) service. This is an alternate to using TCP/IP.

## Parameters

### `HostName` [in]

A pointer to a null-terminated string that contains a list of host names or dotted strings that represent the IP address of LDAP server hosts. Use a single space to separate the host names in the list. Each host name in the list may be followed by a port number. The optional port number is separated from the host itself with a colon (:). The LDAP run time attempts connection with the hosts in the order listed, stopping when a successful connection is made.

### `PortNumber` [in]

The port number to be used. If no port number is specified, the default is port 389, which is defined as LDAP_PORT. If port numbers are included in the *HostName* parameter, this parameter is ignored.

## Return value

If the function succeeds, a session handle, in the form of a pointer to an LDAP structure is returned. Free the session handle with a call to [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) when it is no longer required.

If the function fails, the return value is **NULL**. To get the error code, call
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) or the Win32 function
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **cldap_open** function, unlike
[ldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_open), creates a connection block for UDP-based connectionless LDAP services. No TCP session is maintained. Like **ldap_open**, **cldap_open** allocates an LDAP structure to maintain state data for the session, and then attempts to make the connection before returning to the caller. The call returns a session handle, which you pass to subsequent LDAP function calls in the course of the session. When finished with the session, always free the allocated session handle by using [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind).

Using LDAP over UDP does not support binding and does not support TLS (SSL) or SASL.

Multithreading: Calls to **cldap_open** are thread-safe.

**Note** When using **cldap_open**, the connection is opened by an anonymous user. The only available operations are those that an anonymous user can run.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror)

[ldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_open)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)