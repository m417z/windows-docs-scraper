# RAS_AUTH_ATTRIBUTE_TYPE enumeration

## Description

The
**RAS_AUTH_ATTRIBUTE_TYPE** enumerated type specifies attribute values used for session authentication. Further details for values in this enumerated type are obtained by referring to one of the four following references:
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt),
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt),
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt), or
[RFC 2868](https://www.ietf.org/rfc/rfc2868.txt).

## Constants

### `raatMinimum:0`

Specifies a value equal to zero, and used as the **NULL** terminator in any array of
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) structures.

### `raatUserName`

Specifies the name of the user to be authenticated. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatUserPassword`

Specifies the password of the user to be authenticated. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatMD5CHAPPassword`

Specifies the password provided by the user in response to an MD5 Challenge Handshake Authentication Protocol (CHAP) challenge. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatNASIPAddress`

Specifies the Network Access Server (NAS) IP address. An Access-Request should specify either an NAS IP address or an NAS identifier. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatNASPort`

Specifies the physical or virtual private network (VPN) through which the user is connecting to the NAS. Note that this value is not a port number in the sense of TCP or UDP. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatServiceType`

Specifies the type of service the user has requested or the type of service to be provided. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFramedProtocol`

Specifies the type of framed protocol to use for framed access, for example SLIP, PPP, or ARAP (AppleTalk Remote Access Protocol). The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFramedIPAddress`

Specifies the IP address that is configured for the user requesting authentication. This attribute is typically returned by the authentication provider. However, the NAS may use it in an authentication request to specify a preferred IP address. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFramedIPNetmask`

Specifies the IP network mask for a user that is a router to a network. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFramedRouting:10`

Specifies the routing method for a user that is a router to a network. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFilterId`

Specifies the filter list for the user requesting authentication. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFramedMTU`

Specifies the Maximum Transmission Unit (MTU) for the user. This attribute is used in cases where the MTU is not negotiated through some other means, such as PPP. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFramedCompression`

Specifies a compression protocol to use for the connection. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatLoginIPHost`

Specifies the system with which to connect the user. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatLoginService`

Specifies the service to use to connect the user to the host specified by **raatLoginIPHost**. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatLoginTCPPort`

Specifies the port to which to connect the user. This attribute is present only if the **raatLoginService** attribute is present. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatUnassigned17`

This value is currently unassigned.

### `raatReplyMessage`

Specifies a message to display to the user. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatCallbackNumber`

Specifies a callback number. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatCallbackId:20`

Specifies a location to call back. The value of this attribute is interpreted by the NAS. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatUnassigned21`

This value is currently unassigned. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is also undefined.

### `raatFramedRoute`

Specifies routing information to configure on the NAS for the user. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFramedIPXNetwork`

Specifies the IPX network number to configure for the user. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatState`

Specifies state information provided to the client by the server. Refer to
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for detailed information about this value. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer.

### `raatClass`

Specifies a value that is provided to the NAS by the authentication provider. The NAS should use this value when communicating with the accounting provider. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatVendorSpecific`

Specifies a field for vendor-supplied extended attributes. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatSessionTimeout`

Specifies the maximum number of seconds for which to provide service to the user. After this time, the session is terminated. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatIdleTimeout`

Specifies the maximum number of consecutive seconds the session can be idle. If the idle time exceeds this value, the session is terminated. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatTerminationAction`

Specifies an action the server performs when time the connection terminates. Refer to the above-referenced files for detailed information about this value. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatCalledStationId:30`

Specifies the number that the user dialed to connect to the NAS. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatCallingStationId`

Specifies the number from which the user is calling. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatNASIdentifier`

Specifies the NAS identifier. An Access-Request should specify either an NAS identifier or an NAS IP address. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatProxyState`

Specifies a value that a proxy server includes when forwarding an authentication request. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatLoginLATService`

Specifies an attribute that is not currently used for authentication on Windows 2000. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatLoginLATNode`

Specifies an attribute that is not currently used for authentication on Windows 2000. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatLoginLATGroup`

Specifies an attribute that is not currently used for authentication on Windows 2000. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFramedAppleTalkLink`

Specifies the AppleTalk network number for the user when the user is another router. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFramedAppleTalkNetwork`

Specifies the AppleTalk network number that the NAS should use to allocate an AppleTalk node for the user. This attribute is used only when the user is not another router. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatFramedAppleTalkZone`

Specifies the AppleTalk default zone for the user. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatAcctStatusType:40`

Specifies whether the accounting provider should start or stop accounting for the user. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctDelayTime`

Specifies the length of time that the client has been attempting to send the current request. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctInputOctets`

Specifies the number of octets that have been received during the current accounting session. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctOutputOctets`

Specifies the number of octets that were sent during the current accounting session. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctSessionId`

Specifies a value to enable the identification of matching start and stop records within a log file. The start and stop records are sent in the **raatAcctStatusType** attribute. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctAuthentic`

Specifies, to the accounting provider, how the user was authenticated; for example by Windows 2000 Directory Services, RADIUS, or some other authentication provider. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctSessionTime`

Specifies the number of seconds that have elapsed in the current accounting session. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctInputPackets`

Specifies the number of packets that have been received during the current accounting session. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctOutputPackets`

Specifies the number of packets that have been sent during the current accounting session. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctTerminateCause`

Specifies how the current accounting session was terminated. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctMultiSessionId:50`

Specifies a value to enable the identification of related accounting sessions within a log file. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctLinkCount`

Specifies the number of links if the current accounting session is using a multilink connection. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `raatAcctEventTimeStamp:55`

Specifies an attribute that is included in an accounting request packet. It specifies the time that the event took place. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see the
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt) Internet draft.

### `raatMD5CHAPChallenge:60`

Specifies the CHAP challenge sent by the NAS to a CHAP user. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatNASPortType`

Specifies the type of the port through which the user is connecting, for example, asynchronous, ISDN, virtual. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatPortLimit`

Specifies the number of ports the NAS should make available to the user for multilink sessions. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatLoginLATPort`

Specifies an attribute that is not currently used for authentication on Windows 2000. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `raatTunnelType`

Specifies the tunneling protocol used. The following table lists valid tunnel types.

| Tunnel Type Value | Description |
| --- | --- |
| 1 | Point-to-Point Tunneling Protocol (PPTP) |
| 2 | Layer Two Forwarding (L2F) |
| 3 | Layer Two Tunneling Protocol (L2TP) |
| 4 | Ascend Tunnel Management Protocol (ATMP) |
| 5 | Virtual Tunneling Protocol (VTP) |
| 6 | IP Authentication Header in the Tunnel-mode |
| 7 | IP-in-IP Encapsulation (IP-IP) |
| 8 | Minimal IP-in-IP Encapsulation (MIN-IP-IP) |
| 9 | IP Encapsulating Security Payload in the Tunnel-mode (ESP) |
| 10 | Generic Route Encapsulation (GRE) |
| 11 | Bay Dial Virtual Services (DVS) |
| 12 | IP-in-IP Tunneling |

### `raatTunnelMediumType`

Specifies which transport medium to use when creating a tunnel for those protocols (such as L2TP) that can operate over multiple transports. The following table lists valid medium types.

| Medium Type Value | Description |
| --- | --- |
| 1 | IPv4 (IP version 4) |
| 2 | IPv6 (IP version 6) |
| 3 | NSAP |
| 4 | HDLC (8-bit multidrop) |
| 5 | BBN 1822 |
| 6 | 802 (includes all 802 media plus Ethernet "canonical format") |
| 7 | E.163 (POTS) |
| 8 | E.164 (SMDS, Frame Relay, ATM) |
| 9 | F.69 (Telex) |
| 10 | X.121 (X.25, Frame Relay) |
| 11 | IPX |
| 12 | Appletalk |
| 13 | Decnet IV |
| 14 | Banyan Vines |
| 15 | E.164 with NSAP format subaddress |

### `raatTunnelClientEndpoint`

Points to the address of the initiator end of the tunnel.

### `raatTunnelServerEndpoint`

Points to the address of the server end of the tunnel.

### `raatARAPPassword:70`

Specifies a password to use for AppleTalk Remote Access Protocol (ARAP) authentication. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt) .

### `raatARAPFeatures`

Specifies information that an NAS should send back to the user in an ARAP "feature flags" packet. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatARAPZoneAccess`

Specifies how to use the ARAP zone list for the user. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatARAPSecurity`

Specifies an ARAP security module to use during a secondary authentication phase between the NAS and the user. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatARAPSecurityData`

Specifies the data to use with an ARAP security module. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatPasswordRetry`

Specifies the number of password retry attempts to permit the user access. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value.

### `raatPrompt`

Specifies whether the NAS should echo the user response to a challenge. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatConnectInfo`

Specifies information about the type of connection the user is using. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a Pointer. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatConfigurationToken`

Specifies user-profile information in communications between RADIUS Proxy Servers and RADIUS Proxy Clients. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatEAPMessage`

Specifies that EAP information be sent directly between the user and the authentication provider. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatSignature:80`

Specifies a signature to include with CHAP, EAP, or ARAP packets. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information,
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatARAPChallengeResponse:84`

Specifies the response to a Apple Remote Access Protocol (ARAP) challenge. In ARAP, either the server or the client may respond to challenges. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a pointer. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatAcctInterimInterval:85`

Specifies the time, in seconds, between accounting updates. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatNASIPv6Address:95`

### `raatFramedInterfaceId`

### `raatFramedIPv6Prefix`

### `raatLoginIPv6Host`

### `raatFramedIPv6Route`

### `raatFramedIPv6Pool`

### `raatARAPGuestLogon:8096`

Specifies a Apple Remote Access Protocol (ARAP) guest logon. The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is a 32-bit integral value. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `raatCertificateOID`

Reserved for internal use only.

### `raatEAPConfiguration`

Reserved for internal use only.

### `raatPEAPEmbeddedEAPTypeId:8099`

Reserved for internal use only.

### `raatInnerEAPTypeId:8099`

### `raatPEAPFastRoamedSession:8100`

Reserved for internal use only.

### `raatFastRoamedSession:8100`

### `raatEAPTLV:8102`

Indicates and EAP-TLV attribute.

### `raatCredentialsChanged`

### `raatCertificateThumbprint:8250`

### `raatPeerId:9000`

### `raatServerId`

### `raatMethodId`

### `raatEMSK`

### `raatSessionId`

### `raatReserved`

The value field in
[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute) for this type is undefined.

## See also

[EAP Enumerations](https://learn.microsoft.com/windows/win32/eap/eap-enumerations)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[RAS_AUTH_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ras_auth_attribute)