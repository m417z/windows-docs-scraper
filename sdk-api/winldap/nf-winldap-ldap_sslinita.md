# ldap_sslinitA function

## Description

The **ldap_sslinit** function initializes a Secure Sockets Layer (SSL) session with an LDAP server.

## Parameters

### `HostName` [in]

A pointer to a null-terminated string that contains a space-separated list of host names or dotted strings representing the IP address of hosts running an LDAP server to which to connect. Each host name in the list can include an optional port number which is separated from the host itself with a colon (:) character.

### `PortNumber` [in]

Contains the TCP port number to which to connect. Set to **LDAP_SSL_PORT** to obtain the default port, 636. This parameter is ignored if a host name includes a port number.

### `secure` [in]

If nonzero, the function uses SSL encryption. If the value is 0, the function establishes a plain TCP connection and uses clear text (no encryption).

## Return value

If the function succeeds, it returns a session handle, in the form of a pointer to an
[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) structure. The session handle must be freed with a call to [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) when it is no longer needed.

If the function fails, the return value is **NULL**. Use
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) to retrieve the error code.

## Remarks

Call **ldap_sslinit** to create a connection block to a secured LDAP server. The *HostName* parameter can be **NULL** in which case the run time attempts to find the "default" LDAP server. The hosts are tried in the order listed, stopping with the first one to which a successful connection is made.

If the *HostName* was set to either **NULL** or the domain name, automatic reconnect applies. If the connected DC stops functioning for some reason during the connection's lifetime, LDAP will automatically reconnect to another DC in the specified domain. This behavior can be toggled off or on using the **LDAP_OPT_AUTO_RECONNECT** session option, which is on by default.

If a Global Catalog port number is passed to **ldap_sslinit** as one of the arguments, then the *HostName* passed for that port number must be the name of the forest for the underlying call to [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) to correctly find the GC in the enterprise.

The function allocates an LDAP structure to maintain state information for the session, and returns a handle to this structure. You pass this handle to subsequent LDAP function calls during the course of the session.

Multithreading: Calls to **ldap_sslinit** are thread-safe.

Microsoft implements security features, like SSL, through its SSPI capabilities.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Initializing a Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/initializing-a-session)

[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap)

[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror)

[SSPI Options for Distributed Applications](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-options-for-distributed-applications)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)