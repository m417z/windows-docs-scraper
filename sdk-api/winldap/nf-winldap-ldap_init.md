# ldap_init function

## Description

The **ldap_init** function initializes a session with an LDAP server.

## Parameters

### `HostName` [in]

A pointer to a null-terminated string that contains a domain name, or a space-separated list of host names or dotted strings that represent the IP address of hosts running an LDAP server to which to connect. Each host name in the list can include an optional port number which is separated from the host itself with a colon (:). For more information about the use of the **LDAP_OPT_AREC_EXCLUSIVE** option when connecting to Active Directory servers, see the Remarks section.

### `PortNumber` [in]

Contains the TCP port number to which to connect. Set to **LDAP_PORT** to obtain the default port, 389. This parameter is ignored if a host name includes a port number.

## Return value

If the function succeeds, it returns a session handle, in the form of a pointer to an
[LDAP](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldap) data structure. The session handle must be freed with a call to [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind) when it is no longer required.

If the function fails, it returns **NULL**. Use
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) to retrieve the error code.

## Remarks

Call **ldap_init** to create a connection block to an LDAP server. Unlike
[ldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_open), a call to **ldap_init** does not open the connection. You can call [ldap_connect](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_connect) explicitly to have the library contact the server. This is useful when you want to specify a local timeout in which case you would call
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option), with the connection block from **ldap_init**, before calling **ldap_connect**. Typically, however, this call is unnecessary because the first operation function that requires an open connection calls **ldap_connect** internally if it has not been called.

The function allocates an LDAP data structure to maintain state data for the session, and returns a handle to this structure. Pass this handle to LDAP function calls during the session.

The *HostName* parameter can be **NULL**, in which case the run time attempts to find the "default" LDAP server. When
[ldap_connect](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_connect) is called, the hosts are attempted in the order listed, stopping with the first successful connection. For Active Directory servers, the [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function can be used to obtain name of the server, which can then be passed as the *HostName* parameter instead of using **NULL**.

Even when the [ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option) function is used to set the **LDAP_OPT_GETDSNAME_FLAGS** option, which in turn specifies the flags that will be passed to [DsGetDCName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) to discover which DC to connect to. The LDAP client also passes the **DS_ONLY_LDAP_NEEDED** flag to **DsGetDCName** in addition to the flags that **LDAP_OPT_GETDSNAME_FLAGS** specifies.

If **NULL** is passed for the *HostName* parameter and the calling computer is a member of an Active Directory domain, then the runtime will search for a DC in the domain in which the current computer is a member when attempting to connect.

If **NULL** is passed for the *HostName* parameter and the calling computer is a DC of an Active Directory domain, then the runtime will switch **NULL** with 127.0.0.1 and connect to the local computer using loopback when attempting to connect.

If an Active Directory domain name is passed for the *HostName* parameter, then **ldap_init** will find the "default" LDAP server in that domain.

If the *HostName* was set to either **NULL** or the domain name, automatic reconnect applies. If the connected DC stops functioning for some reason during the connection's lifetime, LDAP will automatically reconnect to another DC in the specified domain. This behavior can be toggled off or on using the **LDAP_OPT_AUTO_RECONNECT** session option, which is on by default.

If an Active Directory DNS server name is passed for the *HostName* parameter, then
[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option) should be called to set the **LDAP_OPT_AREC_EXCLUSIVE** flag on before calling any LDAP function that creates the actual connection. This forces an A-record lookup and bypasses any SRV record lookup when resolving the host name. In the case of a branch office with a dial-up connection, using A-Record lookup can avoid forcing the dialup to query a remote DNS server for SRV records when resolving names.

If a Global Catalog port number is passed to **ldap_init** as one of the arguments, then the *HostName* passed for that port number must be the name of the forest for the underlying call to [DsGetDcName()](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) to correctly find the GC in the enterprise.

Multithreading: A call to **ldap_init** is thread safe.

**Note** **ldap_init** is the preferred method of initializing an LDAP session. The use of [ldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_open) is heavily deprecated by the current LDAP RFC because it precludes the use of setting any session options.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[Initializing a Session](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/initializing-a-session)

[ldap_connect](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_connect)

[ldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_open)

[ldap_set_option](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_set_option)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)