# WSASetSocketSecurity function

## Description

The **WSASetSocketSecurity** function enables and applies security for a socket.

## Parameters

### `Socket` [in]

A descriptor that identifies a socket on which security settings are being applied.

### `SecuritySettings` [in, optional]

A pointer to a [SOCKET_SECURITY_SETTINGS](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings) structure that specifies the security settings to be applied to the socket's traffic. If this parameter is **NULL**, default settings will be applied to the socket.

### `SecuritySettingsLen` [in]

The size, in bytes, of the *SecuritySettings* parameter.

### `Overlapped` [in, optional]

A pointer to a [WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure. This parameter is ignored for non-overlapped sockets.

### `CompletionRoutine` [in, optional]

A pointer to the completion routine called when the operation has been completed. This parameter is ignored for non-overlapped sockets.

## Return value

If the function succeeds, the return value is zero. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

Some possible error codes are listed below.

| Error code | Meaning |
| --- | --- |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified address family is not supported. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid parameter was passed. This error is returned if the socket passed in the *Socket* parameter was not created with an address family of the **AF_INET** or **AF_INET6** and a socket type of **SOCK_DGRAM** or **SOCK_STREAM**. This error is also returned if the [SOCKET_SECURITY_SETTINGS](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings) structure pointed to by the *SecuritySettings* parameter has an incorrect value. |
| **[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is connected. This function is not permitted with a connected socket, whether the socket is connection oriented or connectionless. |
| **[WSAEMSGSIZE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A buffer passed was too small. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor passed in the *Socket* parameter is not a valid socket. |

## Remarks

The primary purpose of the **WSASetSocketSecurity** function is to turn on security for a socket if it is not already enabled by administrative policy. For IPsec, this means that appropriate IPsec filters and policies will be instantiated that will be used to secure this socket. the **WSASetSocketSecurity** function can also be used to set specific security requirements for the socket.

This function simplifies having to call the [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) function with a *dwIoControlCode* parameter set to **SIO_SET_SECURITY**.

The **WSASetSocketSecurity** function may be called on a *Socket* parameter created with an address family of **AF_INET** or **AF_INET6**.

For a client application using connection-oriented sockets (protocol of **IPPROTO_TCP**), the **WSASetSocketSecurity** function should be called before the [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect), [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex), or [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) function is called. If the **WSASetSocketSecurity** function is called after the **connect**, **ConnectEx**, or **WSAConnect** function, **WSASetSocketSecurity** should fail.

For a server application using connection-oriented sockets (protocol of **IPPROTO_TCP**), the **WSASetSocketSecurity** function should be called before the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function is called. If the **WSASetSocketSecurity** function is called after the **bind** function, **WSASetSocketSecurity** should fail.

For connectionless sockets (protocol of **IPPROTO_UDP**), the application should call the **WSASetSocketSecurity** function immediately after [socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) or [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) call returns.

Server applications should call the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function to acquire exclusive access to the port used by the socket. This prevents other applications from using the same port. The **setsockopt** function would be called with the *level* parameter set to SOL_SOCKET, the *optname* parameter set to [SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/so-exclusiveaddruse), and the *value*  parameter set to nonzero. The **WSASetSocketSecurity** function internally calls the **setsockopt** with SO_EXCLUSIVEADDRUSE to obtain exclusive access to the port. This is to ensure that the socket is not vulnerable to attacks by other applications running on the local computer.

Security settings not set using the **WSASetSocketSecurity** are derived from the system default policy or the administratively configured policy. It is recommended that most applications specify a value of **SOCKET_SECURITY_PROTOCOL_DEFAULT** for the [SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol) enumeration in the **SecurityProtocol** member of the **SOCKET_SECURITY_PROTOCOL** pointed to by the *SecuritySettings* parameter. This makes the application neutral to security protocols and allows easier deployments among different systems.

When the *SecuritySettings* parameter points to a [SOCKET_SECURITY_SETTINGS_IPSEC](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings_ipsec) structure, the **SecurityProtocol**
member of the structure must be set to **SOCKET_SECURITY_PROTOCOL_IPSEC**, not **SOCKET_SECURITY_PROTOCOL_DEFAULT**.

An error will be returned if the following conditions are not met.

* The address family of the *Socket* parameter must be either AF_INET or AF_INET6.
* The socket type must be either SOCK_STREAM or SOCK_DGRAM.
* The application must set its security settings before calling the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect), [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex), or [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) functions.
* The **WSASetSocketSecurity** function can only be called once per socket.

### Default Secure Socket IPsec Policy

If the *SecuritySettings* parameter is set to **NULL**, and there is no other administratively specified IPsec policy on the computer, a default security policy based on IPsec will be used to secure the application's traffic. Some type of authentication credential (a user certificate or domain membership, for example) must be present for IPsec to succeed with a default policy.

The default IPsec policy has been designed so that IPsec security can be negotiated in as many scenarios as possible.

``` syntax
Authip MM policy =
{
 Auth methods = {IKE_ANONYMOUS}
 No impersonation
 Proposals =
 {
   {
     Crypto algos =
     IKE_CIPHER_AES_128,
     IKE_INTEGRITY_SHA1,
     IKE_DH_ECP_256
     MM lifetime = 2 hrs
     QM = 0 (infinite)
   }
   {
     Crypto algos =
     IKE_CIPHER_3DES,
     IKE_INTEGRITY_SHA1,
     IKE_DH_GROUP_2
     MM lifetime = 2 hrs
     QM = 0 (infinite)
   }
 }
}

Authip QM policy =
{
 QM proposals =
 {
   QM lifetime = 1 hr, 55GB,
   Crypto algos =
   IPSEC_TRANSFORM_ESP_AUTH,
   IPSEC_AUTH_TRANSFORM_ID_HMAC_SHA_1_96
   No PFS
 }
 {
   QM lifetime = 1 hr, 55GB,
   Crypto algos =
   IPSEC_TRANSFORM_ESP_AUTH_AND_CIPHER,
   IPSEC_AUTH_TRANSFORM_ID_HMAC_SHA_1_96,
   IPSEC_CIPHER_TRANSFORM_ID_AES_128
   No PFS
 }
 {
   QM lifetime = 1 hr, 55GB,
   Crypto algos =
   IPSEC_TRANSFORM_ESP_AUTH_AND_CIPHER,
   IPSEC_AUTH_TRANSFORM_ID_HMAC_SHA_1_96,
   IPSEC_CIPHER_TRANSFORM_ID_CBC_3DES
   No PFS
 }
 {
   QM lifetime = 1 hr, 55GB,
   Crypto algos =
   IPSEC_TRANSFORM_AH,
   IPSEC_AUTH_TRANSFORM_ID_HMAC_SHA_1_96
   No PFS
 }
 IPSEC_POLICY_FLAG_ND_BOUNDARY
 ndAllowClearTimeoutSeconds = 10
 saIdleTimeout = {5mins, 1min}
 UM policy =
 {
   {IKE_SSL, Null-Root-Config}
   {IKE_KERBEROS}
   {IKE_SSL, Null-Root-Config}
   No impersonation
 }
}

```

## See also

[SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol)

[SOCKET_SECURITY_SETTINGS](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings)

[SOCKET_SECURITY_SETTINGS_IPSEC](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings_ipsec)

[SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/so-exclusiveaddruse)

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSADeleteSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsadeletesocketpeertargetname)

[WSAImpersonateSocketPeer](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaimpersonatesocketpeer)

[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped)

[WSAQuerySocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsaquerysocketsecurity)

[WSARevertImpersonation](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsarevertimpersonation)

[WSASetSocketPeerTargetName](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketpeertargetname)

[WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)