# ldap_openA function

## Description

[[ldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-cldap_open) is available for use in the operating systems specified in the Requirements section; however, it is not recommended. Instead, use [ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init).]

The **ldap_open** function creates and initializes a connection block, then opens the connection to an LDAP server.

## Parameters

### `HostName` [in]

A pointer to a null-terminated string. A domain name, a list of host names, or dotted strings that represent the IP address of LDAP server hosts. Use a single space to separate the host names in the list. Each host name in the list may be followed by a port number. The optional port number is separated from the host itself with a colon (:). The LDAP run time attempts connection with the hosts in the order listed, stopping when a successful connection is made. Be aware that only **ldap_open** attempts to make the connection before returning to the caller. The function
[ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init) does not connect to the LDAP server.

### `PortNumber` [in]

Contains the TCP port number to which to connect. The default LDAP port, 389, can be obtained by supplying the constant **LDAP_PORT**. If a host name includes a port number then this parameter is ignored.

## Return value

If the function succeeds, it returns a session handle, in the form of a pointer to an LDAP data structure. Free the session handle, when no longer required, with a call to [ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind).

If the function fails, it returns **NULL**. Use the
[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror) function to retrieve the error code.

## Remarks

Call **ldap_open** to create a connection block to an LDAP server. The *HostName* can be **NULL** in which case the run time attempts to find the default LDAP server. The host names are tried in the order listed, stopping with the first successful connection. For Active Directory servers, the [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function can be used to obtain name of the server, which can then be passed as the *HostName* parameter instead of using **NULL**.

If the *HostName* was set to either **NULL** or the domain name, automatic reconnect applies. If the connected DC stops functioning for some reason during the connection's lifetime, LDAP will automatically reconnect to another DC in the specified domain. This behavior can be toggled off or on using the **LDAP_OPT_AUTO_RECONNECT** session option, which is on by default.

The default LDAP server is a Microsoft specific option when you use **LDAP_OPT_HOST_NAME**. This option specifies the host name of the default LDAP server and returns the host name of the server in Unicode or ANSI, contingent on the use of [ldap_get_optionW](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_get_option) or **ldap_get_optionA**, respectively.

If a Global Catalog port number is passed to **ldap_open** as one of the arguments, then the *HostName* passed for that port number must be the name of the forest for the underlying call to [DsGetDcName()](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) to correctly find the GC in the enterprise.

The **ldap_open** function allocates an LDAP data structure to maintain state data for the session and returns a handle to this structure. Pass this handle to subsequent LDAP function calls during the course of the session.

Multithreading: Calls to **ldap_open** are thread-safe.

**Note** **ldap_open** is heavily deprecated by the current LDAP RFC because it immediately opens a session to the domain controller without giving the calling application a chance to configure any session options, for example (and most importantly) security-related session options. Users are encouraged to use
[ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init) as the preferred method of initializing an LDAP session.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[LdapGetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldapgetlasterror)

[cldap_open](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-cldap_open)

[ldap_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_init)

[ldap_unbind](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_unbind)