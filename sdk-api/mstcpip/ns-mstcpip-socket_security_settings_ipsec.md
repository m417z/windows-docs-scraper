# SOCKET_SECURITY_SETTINGS_IPSEC structure

## Description

The **SOCKET_SECURITY_SETTINGS_IPSEC** structure specifies various security requirements and settings that are specific to IPsec.

## Members

### `SecurityProtocol`

Type: **SOCKET_SECURITY_PROTOCOL**

A [SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol) value that identifies the type of security protocol to be used on the socket. This member must be set to **SOCKET_SECURITY_PROTOCOL_IPSEC**.

### `SecurityFlags`

Type: **ULONG**

A set of flags that allow applications to set specific security requirements on a socket. The possible values are defined in the *Mstcpip.h* header file.

| Value | Meaning |
| --- | --- |
| **SOCKET_SETTINGS_GUARANTEE_ENCRYPTION**<br><br>0x00000001 | Indicates that guaranteed encryption of traffic is required. This flag should be set if the default policy prefers methods of protection that do not use encryption. If this flag is set and encryption is not possible for any reason, no packets will be sent and a connection will not be established. |
| **SOCKET_SETTINGS_ALLOW_INSECURE**<br><br>0x00000002 | Indicates that clear text connections are allowed. If this flag is set, some or all of the sent packets will be sent in clear text, especially if security with the peer could not be negotiated.<br><br>**Note** If this flag is not set, it is guaranteed that packets will never be sent in clear text, even if security negotiation fails. |

### `IpsecFlags`

Type: **ULONG**

Flags for IPsec security settings. The possible values are defined in the *Mstcpip.h* header file.

| Value | Meaning |
| --- | --- |
| **SOCKET_SETTINGS_IPSEC_SKIP_FILTER_INSTANTIATION**<br><br>0x00000001 | When this flag is set, IPsec filter instantiation is omitted for the socket. This flag should be set when an application knows that IPsec filters and policy already exist for its traffic. Applications running on a domain with IPsec policy in place can also set this flag. |

### `AuthipMMPolicyKey`

Type: **GUID**

The GUID for the Windows Filtering Platform key of the AuthIP main mode provider context. If an application wishes to use a custom main mode policy, it should first use the [FwpmProviderContextAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd0) function to add the corresponding provider context and specify the returned key in this member. This field is ignored for a GUID of zero.

### `AuthipQMPolicyKey`

Type: **GUID**

The Windows Filtering Platform key of the AuthIp quick mode provider context. If an application wishes to use a custom quick mode policy, it should first use the [FwpmProviderContextAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd0) function to add the corresponding provider context and specify the returned key in this field. This field is ignored for a GUID of zero.

### `Reserved`

Type: **GUID**

Reserved for future use.

### `Reserved2`

Type: **UINT64**

Reserved for future use.

### `UserNameStringLen`

Type: **ULONG**

The length, in bytes, of the user name in the **AllStrings** member.

### `DomainNameStringLen`

Type: **ULONG**

The length, in bytes, of the domain name in the **AllStrings** member.

### `PasswordStringLen`

Type: **ULONG**

The length, in bytes, of the password in the **AllStrings** member.

### `AllStrings`

Type: **wchar_t[]**

A string that contains the user name, the domain name, and the password concatenated in this order.

## Remarks

The **SOCKET_SECURITY_SETTINGS_IPSEC** structure is supported on Windows Vista and later.

The **SOCKET_SECURITY_SETTINGS_IPSEC** structure is meant to be used by an advanced application that requires more flexibility and wishes to customize IPSec policy for their traffic. The pointer to the **SOCKET_SECURITY_SETTINGS_IPSEC** structure needs to cast to the [SOCKET_SECURITY_SETTINGS](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings) structure type when calling the [WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity) function to enable and apply security on a socket.

The **SecurityProtocol**
member of the **SOCKET_SECURITY_SETTINGS_IPSEC** structure must be set to **SOCKET_SECURITY_PROTOCOL_IPSEC**, not **SOCKET_SECURITY_PROTOCOL_DEFAULT**.

To simplify Internet Protocol security (IPsec) deployment, Windows Vista and later support an enhanced version of the Internet Key Exchange (IKE) protocol known as Authenticated Internet Protocol (AuthIP). AuthIP provides simplified IPsec policy configuration and maintenance in many configurations and additional flexibility for IPsec peer authentication.

There is a possibility that some of the IPsec settings specified in the **SOCKET_SECURITY_SETTINGS_IPSEC** structure may end up being different from the actual settings applied to the network traffic on a socket. For example, this could happen when an application specifies custom main mode or quick mode policy, but a different policy with a higher priority (a domain policy, for example) specifies conflicting settings for the same traffic. To be aware of such conflicts, an application can use the Windows Filtering Platform API to query the policy being applied and subscribe for notifications.

## See also

[About Windows Filtering Platform](https://learn.microsoft.com/windows/desktop/FWP/about-windows-filtering-platform)

[FwpmProviderContextAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd0)

[SOCKET_SECURITY_PROTOCOL](https://learn.microsoft.com/windows/desktop/api/mstcpip/ne-mstcpip-socket_security_protocol)

[SOCKET_SECURITY_SETTINGS](https://learn.microsoft.com/windows/desktop/api/mstcpip/ns-mstcpip-socket_security_settings)

[Using Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/using-secure-socket-extensions)

[WSASetSocketSecurity](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-wsasetsocketsecurity)

[Windows Filtering Platform](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page)

[Windows Filtering Platform API Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)

[Winsock Secure Socket Extensions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-secure-socket-extensions)