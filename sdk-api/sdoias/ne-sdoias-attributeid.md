# ATTRIBUTEID enumeration

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The
**ATTRIBUTEID** enumeration type enumerates the RADIUS attributes supported by the SDO API.

## Constants

### `ATTRIBUTE_UNDEFINED:0`

Specifies a value equal to zero, and used as the **NULL** terminator in an array of attributes.

### `ATTRIBUTE_MIN_VALUE:1`

Specifies the minimum value for values of this enumeration type.

### `RADIUS_ATTRIBUTE_USER_NAME`

Specifies the name of the user to be authenticated. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_USER_PASSWORD`

Specifies the password of the user to be authenticated. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_CHAP_PASSWORD`

Specifies the password provided by the user in response to an MD5 Challenge Handshake Authentication Protocol (CHAP) challenge. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_NAS_IP_ADDRESS`

Specifies the Network Access Server (NAS) IP address. An Access-Request should specify either an NAS IP address or an NAS identifier. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_NAS_PORT`

Specifies the physical or virtual private network (VPN) through which the user is connecting to the NAS. Note that this value is not a port number in the sense of TCP or UDP. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_SERVICE_TYPE`

Specifies the type of service the user has requested or the type of service to be provided. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FRAMED_PROTOCOL`

Specifies the type of framed protocol to use for framed access, for example SLIP, PPP, or ARAP (AppleTalk Remote Access Protocol). For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FRAMED_IP_ADDRESS`

Specifies the IP address that is configured for the user requesting authentication. This attribute is typically returned by the authentication provider. However, the NAS may use it in an authentication request to specify a preferred IP address. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FRAMED_IP_NETMASK`

Specifies the IP network mask for a user that is a router to a network. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FRAMED_ROUTING:10`

Specifies the routing method for a user that is a router to a network. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FILTER_ID`

Specifies the filter list for the user requesting authentication. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FRAMED_MTU`

Specifies the Maximum Transmission Unit (MTU) for the user. This attribute is used in cases where the MTU is not negotiated through some other means, such as PPP. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FRAMED_COMPRESSION`

Specifies a compression protocol to use for the connection. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_LOGIN_IP_HOST`

Specifies the system with which to connect the user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_LOGIN_SERVICE`

Specifies the service to use to connect the user to the host specified by **raatLoginIPHost**. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_LOGIN_TCP_PORT`

Specifies the port to which to connect the user. This attribute is present only if the **raatLoginService** attribute is present. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_UNASSIGNED1`

This value is currently unassigned.

### `RADIUS_ATTRIBUTE_REPLY_MESSAGE`

Specifies a message to display to the user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_CALLBACK_NUMBER`

Specifies a callback number. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_CALLBACK_ID:20`

Specifies a location to call back. The value of this attribute is interpreted by the NAS. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_UNASSIGNED2`

This value is currently unassigned. The value field in for this type is also undefined.

### `RADIUS_ATTRIBUTE_FRAMED_ROUTE`

Specifies routing information to configure on the NAS for the user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FRAMED_IPX_NETWORK`

Specifies the IPX network number to configure for the user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_STATE`

Specifies state information provided to the client by the server. Refer to
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for detailed information about this value. The value field in for this type is a pointer.

### `RADIUS_ATTRIBUTE_CLASS`

Specifies a value that is provided to the NAS by the authentication provider. The NAS should use this value when communicating with the accounting provider. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_VENDOR_SPECIFIC`

Specifies a field for vendor-supplied extended attributes. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_SESSION_TIMEOUT`

Specifies the maximum number of seconds for which to provide service to the user. After this time, the session is terminated. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_IDLE_TIMEOUT`

Specifies the maximum number of consecutive seconds the session can be idle. If the idle time exceeds this value, the session is terminated. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_TERMINATION_ACTION`

Specifies an action the server performs when time the connection terminates. Refer to the above-referenced files for detailed information about this value. The value field in for this type is 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_CALLED_STATION_ID:30`

Specifies the number that the user dialed to connect to the NAS. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_CALLING_STATION_ID`

Specifies the number from which the user is calling. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_NAS_IDENTIFIER`

Specifies the NAS identifier. An Access-Request should specify either an NAS identifier or an NAS IP address. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_PROXY_STATE`

Specifies a value that a proxy server includes when forwarding an authentication request. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_LOGIN_LAT_SERVICE`

Specifies an attribute that is not currently used for authentication on Windows. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_LOGIN_LAT_NODE`

Specifies an attribute that is not currently used for authentication on Windows. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_LOGIN_LAT_GROUP`

Specifies an attribute that is not currently used for authentication on Windows. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FRAMED_APPLETALK_LINK`

Specifies the AppleTalk network number for the user when the user is another router. The value field in for this type is 32-bit integral value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FRAMED_APPLETALK_NET`

Specifies the AppleTalk network number that the NAS should use to allocate an AppleTalk node for the user. This attribute is used only when the user is not another router. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_FRAMED_APPLETALK_ZONE`

Specifies the AppleTalk default zone for the user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_ACCT_STATUS_TYPE:40`

Specifies whether the accounting provider should start or stop accounting for the user. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_DELAY_TIME`

Specifies the length of time that the client has been attempting to send the current request. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_INPUT_OCTETS`

Specifies the number of octets that have been received during the current accounting session. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_OUTPUT_OCTETS`

Specifies the number of octets that were sent during the current accounting session. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_SESSION_ID`

Specifies a value to enable the identification of matching start and stop records within a log file. The start and stop records are sent in the **raatAcctStatusType** attribute. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_AUTHENTIC`

Specifies, to the accounting provider, how the user was authenticated; for example by Windows Directory Services, RADIUS, or some other authentication provider. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_SESSION_TIME`

Specifies the number of seconds that have elapsed in the current accounting session. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_INPUT_PACKETS`

Specifies the number of packets that are received during the current accounting session. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_OUTPUT_PACKETS`

Specifies the number of packets that are sent during the current accounting session. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_TERMINATE_CAUSE`

Specifies how the current accounting session was terminated. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_MULTI_SSN_ID:50`

Specifies a value to enable the identification of related accounting sessions within a log file. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_ACCT_LINK_COUNT:51`

Specifies the number of links if the current accounting session is using a multilink connection. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_CHAP_CHALLENGE:60`

Specifies the CHAP challenge sent by the NAS to a CHAP user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_NAS_PORT_TYPE`

Specifies the type of the port through which the user is connecting, for example, asynchronous, ISDN, virtual. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_PORT_LIMIT`

Specifies the number of ports the NAS should make available to the user for multilink sessions. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_LOGIN_LAT_PORT`

Specifies an attribute that is not currently used for authentication on Windows. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `RADIUS_ATTRIBUTE_TUNNEL_TYPE`

Specifies the tunneling protocol used. The following list lists valid tunnel types.

| Tunnel type value | Description |
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

### `RADIUS_ATTRIBUTE_TUNNEL_MEDIUM_TYPE`

Specifies which transport medium to use when creating a tunnel for those protocols (such as L2TP) that can operate over multiple transports. The following list lists valid medium types.

| Medium type value | Description |
| --- | --- |
| 1 | IPv4 (IP version 4) |
| 2 | IPv6 (IP version 6) |
| 3 | OSI Network Service Access Points (NSAP) Signaling Protocol (see ISO 8348 and ITU-T X.213). |
| 4 | High-Level Data Link Control (HDLC) Protocol (8-bit multidrop) |
| 5 | Bolt Beranek and Newman, Inc. (BBN) Report 1822 |
| 6 | IEEE 802 (includes all 802 media plus Ethernet "canonical format") |
| 7 | E.163 Plain Old Telephone Service (POTS) |
| 8 | E.164 Switched Multimegabit Data Service (SMDS), Frame Relay, Asynchronous Transfer Mode (ATM) |
| 9 | F.69 (Telex) |
| 10 | X.121 (X.25, Frame Relay) |
| 11 | Internetwork Packet Exchange (IPX) |
| 12 | AppleTalk |
| 13 | Decnet IV |
| 14 | Banyan Vines |
| 15 | E.164 with NSAP format subaddress |

### `RADIUS_ATTRIBUTE_TUNNEL_CLIENT_ENDPT`

Specifies the address of the initiator end of the tunnel.

### `RADIUS_ATTRIBUTE_TUNNEL_SERVER_ENDPT`

Specifies the address of the server end of the tunnel.

### `RADIUS_ATTRIBUTE_ACCT_TUNNEL_CONN`

Specifies an identifier assigned to the tunnel
session. For more information, see
[RFC 2867](https://www.ietf.org/rfc/rfc2867.txt).

### `RADIUS_ATTRIBUTE_TUNNEL_PASSWORD`

The password for authenticating to the remote server.

### `RADIUS_ATTRIBUTE_ARAP_PASSWORD:70`

Specifies a password to use for AppleTalk Remote Access Protocol (ARAP) authentication. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_ARAP_FEATURES`

Specifies information that an NAS should send back to the user in an ARAP "feature flags" packet. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_ARAP_ZONE_ACCESS`

Specifies how to use the ARAP zone list for the user. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_ARAP_SECURITY`

Specifies an ARAP security module to use during a secondary authentication phase between the NAS and the user. The value field for this type is a 32-bit integral. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_ARAP_SECURITY_DATA`

Specifies the data to use with an ARAP security module. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_PASSWORD_RETRY`

Specifies the number of password retry attempts to permit the user access. The value field for this type is a 32-bit integral value.

### `RADIUS_ATTRIBUTE_PROMPT:76`

Specifies whether the NAS should echo the user response to a challenge. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_CONNECT_INFO`

Specifies information about the type of connection the user is using. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_CONFIGURATION_TOKEN`

Specifies user-profile information in communications between RADIUS Proxy Servers and RADIUS Proxy Clients. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_EAP_MESSAGE`

Specifies that EAP information be sent directly between the user and the authentication provider. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_SIGNATURE:80`

Specifies a signature to include with CHAP, EAP, or ARAP packets. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_TUNNEL_PVT_GROUP_ID`

Group ID for a particular tunneled session.

### `RADIUS_ATTRIBUTE_TUNNEL_ASSIGNMENT_ID`

Specifies a tunnel to which a session is assigned.

### `RADIUS_ATTRIBUTE_TUNNEL_PREFERENCE`

Relative preference assigned to each tunnel when more than one set of tunneling attributes is returned to the tunnel initiator.

### `RADIUS_ATTRIBUTE_ARAP_CHALLENGE_RESPONSE`

Specifies the response to a Apple Remote Access Protocol (ARAP) challenge. In ARAP, either the server or the client responds to challenges. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

### `RADIUS_ATTRIBUTE_ACCT_INTERIM_INTERVAL:85`

Indicates the number of seconds between each interim update for this specific session. This value can only appear in the Access-Accept message. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

### `RADIUS_ATTRIBUTE_NAS_IPv6_ADDRESS:95`

Specifies the IPv6 Address of the NAS that requests authentication of the user. It should be unique to the NAS within the scope of the RADIUS server. It is only used in an Access-Request packet. For more information, see the NAS-IPv6-Address section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt).

### `RADIUS_ATTRIBUTE_FRAMED_INTERFACE_ID`

Specifies the IPv6 interface identifier to be
configured for the user. It may be used in an Access-Accept packet.
For more information, see the Framed-Interface-Id section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt).

### `RADIUS_ATTRIBUTE_FRAMED_IPv6_PREFIX`

Specifies an IPv6 prefix (and corresponding route)
to be configured for the user. It may be used in an Access-Accept
packet and can appear multiple times. For more information, see the Framed-IPv6-Prefix section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt).

### `RADIUS_ATTRIBUTE_LOGIN_IPv6_HOST`

Specifies the system with which to connect the
user, when the ratLoginService attribute is included. It may be
used in an Access-Accept packet.
For more information, see the Login-IPv6-Host section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt).

### `RADIUS_ATTRIBUTE_FRAMED_IPv6_ROUTE`

Specifies routing information to be configured for
the user on the NAS. It is used in an Access-Accept packet and
can appear multiple times.
For more information, see the Framed-IPv6-Route section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt).

### `RADIUS_ATTRIBUTE_FRAMED_IPv6_POOL:100`

Specifies the name of an assigned pool that should
be used to assign an IPv6 prefix for the user. If a NAS does not
support multiple prefix pools, the NAS must ignore this attribute.

For more information, see the Framed-IPv6-Pool section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt).

### `IAS_ATTRIBUTE_SAVED_RADIUS_FRAMED_IP_ADDRESS:0x1000`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_SAVED_RADIUS_CALLBACK_NUMBER`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_NP_CALLING_STATION_ID`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_SAVED_NP_CALLING_STATION_ID`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_SAVED_RADIUS_FRAMED_ROUTE`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_IGNORE_USER_DIALIN_PROPERTIES`

Specifies that the user's dial-in properties are ignored.

### `IAS_ATTRIBUTE_NP_TIME_OF_DAY`

Time periods and days of week during which user is allowed to connect.

### `IAS_ATTRIBUTE_NP_CALLED_STATION_ID`

Phone number dialed by user.

### `IAS_ATTRIBUTE_NP_ALLOWED_PORT_TYPES:0x1008`

Port types permitted for a connection.

### `IAS_ATTRIBUTE_NP_AUTHENTICATION_TYPE`

Authentication types permitted for a connection.

### `IAS_ATTRIBUTE_NP_ALLOWED_EAP_TYPE`

EAP encryption modes permitted for a connection.

### `IAS_ATTRIBUTE_SHARED_SECRET`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_CLIENT_IP_ADDRESS`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_CLIENT_PACKET_HEADER`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_TOKEN_GROUPS`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_ALLOW_DIALIN`

Specifies whether dial-in access is available for a given user.

### `IAS_ATTRIBUTE_REQUEST_ID:0x1010`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_MANIPULATION_TARGET`

The target data to which an attribute manipulation rule is applied. Attribute manipulation was previously known as 'realms processing'. See the online help for Internet Authentication Service for more information on attribute manipulation.

### `IAS_ATTRIBUTE_MANIPULATION_RULE`

The manipulation rule to apply to the data specified by the Manipulation-Target attribute. See the online help for Internet Authentication Service for more information on attribute manipulation.

### `IAS_ATTRIBUTE_ORIGINAL_USER_NAME`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_CLIENT_VENDOR_TYPE`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_CLIENT_UDP_PORT`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP_CHALLENGE`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP_RESPONSE`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP_DOMAIN:0x1018`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP_ERROR`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP_CPW1`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP_CPW2`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP_LM_ENC_PW`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP_NT_ENC_PW`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP_MPPE_KEYS`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_AUTHENTICATION_TYPE`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_CLIENT_NAME:0x1020`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_NT4_ACCOUNT_NAME`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_FULLY_QUALIFIED_USER_NAME`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_NTGROUPS`

Specifies groups used for the policy conditions.

### `IAS_ATTRIBUTE_EAP_FRIENDLY_NAME`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_AUTH_PROVIDER_TYPE`

The type of authentication provider to use.

### `MS_ATTRIBUTE_ACCT_AUTH_TYPE`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_ACCT_EAP_TYPE`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_PACKET_TYPE:0x1028`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_AUTH_PROVIDER_NAME`

The name of the RADIUS server or server group that provides authentication.

### `IAS_ATTRIBUTE_ACCT_PROVIDER_TYPE`

The type of accounting provider to use.

### `IAS_ATTRIBUTE_ACCT_PROVIDER_NAME`

The name of the RADIUS server that provides accounting.

### `MS_ATTRIBUTE_MPPE_SEND_KEY`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_MPPE_RECV_KEY`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_REASON_CODE`

Specifies an MS-CHAP reason-for-failure code. This attribute is returned in the Failure packet Message field. For more information, see Request for Comments (RFC)
[2433](https://www.ietf.org/rfc/rfc2433.txt).

### `MS_ATTRIBUTE_FILTER`

See Request for Comments (RFC)
[2548](https://www.ietf.org/rfc/rfc2548.txt), Microsoft Vendor-specific RADIUS Attributes.

### `MS_ATTRIBUTE_CHAP2_RESPONSE:0x1030`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP2_SUCCESS`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_CHAP2_CPW`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_RAS_VENDOR`

See Request for Comments (RFC)
[2548](https://www.ietf.org/rfc/rfc2548.txt), Microsoft Vendor-specific RADIUS Attributes.

### `MS_ATTRIBUTE_RAS_VERSION`

See Request for Comments (RFC)
[2548](https://www.ietf.org/rfc/rfc2548.txt), Microsoft Vendor-specific RADIUS Attributes.

### `IAS_ATTRIBUTE_NP_NAME`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_PRIMARY_DNS_SERVER`

See Request for Comments (RFC)
[2548](https://www.ietf.org/rfc/rfc2548.txt), Microsoft Vendor-specific RADIUS Attributes.

### `MS_ATTRIBUTE_SECONDARY_DNS_SERVER`

See Request for Comments (RFC)
[2548](https://www.ietf.org/rfc/rfc2548.txt), Microsoft Vendor-specific RADIUS Attributes.

### `MS_ATTRIBUTE_PRIMARY_NBNS_SERVER:0x1038`

See Request for Comments (RFC)
[2548](https://www.ietf.org/rfc/rfc2548.txt), Microsoft Vendor-specific RADIUS Attributes.

### `MS_ATTRIBUTE_SECONDARY_NBNS_SERVER`

See Request for Comments (RFC)
[2548](https://www.ietf.org/rfc/rfc2548.txt), Microsoft Vendor-specific RADIUS Attributes.

### `IAS_ATTRIBUTE_PROXY_POLICY_NAME`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_PROVIDER_TYPE`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_PROVIDER_NAME`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_REMOTE_SERVER_ADDRESS`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_GENERATE_CLASS_ATTRIBUTE`

Specifies whether NPS automatically generates the class attribute. NPS automatically generates the class attribute by default.

### `MS_ATTRIBUTE_RAS_CLIENT_NAME`

Specifies the name of the client generating a request.

### `MS_ATTRIBUTE_RAS_CLIENT_VERSION:0x1040`

Specifies the version of the client generating a request.

### `IAS_ATTRIBUTE_ALLOWED_CERTIFICATE_EKU`

Specifies the certificate purpose or usage object identifiers (OIDs), in dotted decimal notation, that are allowed when performing certificate-based authentication with EAP-TLS.

### `IAS_ATTRIBUTE_EXTENSION_STATE`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_GENERATE_SESSION_TIMEOUT`

Specifies whether NPS automatically generates the session timeout based on user account expiration and time-of-day restrictions. NPS does not automatically generate the session timeout by default.

### `IAS_ATTRIBUTE_SESSION_TIMEOUT`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_QUARANTINE_IPFILTER`

Specifies the IP traffic filter used by the Routing and Remote Access service when the connection is in a restricted state.

### `MS_ATTRIBUTE_QUARANTINE_SESSION_TIMEOUT`

Specifies the time (in seconds) that the connection can remain in a restricted state before being disconnected.

### `MS_ATTRIBUTE_USER_SECURITY_IDENTITY`

Specifies the SID of the user requesting access.

### `IAS_ATTRIBUTE_REMOTE_RADIUS_TO_WINDOWS_USER_MAPPING:0x1048`

Specifies that Windows authorization is enabled for users authenticated by the remote RADIUS server for example, allows use with Passport user mapping.

### `IAS_ATTRIBUTE_PASSPORT_USER_MAPPING_UPN_SUFFIX`

Specifies the UPN suffix of the Passport to Windows user mapping.

### `IAS_ATTRIBUTE_TUNNEL_TAG`

Used to set the tag byte for any tunnel attributes in the profile. If this is not set, the default is zero.

### `IAS_ATTRIBUTE_NP_PEAPUPFRONT_ENABLED`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_CERTIFICATE_EKU:8097`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_EAP_CONFIG`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_PEAP_EMBEDDED_EAP_TYPEID`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_PEAP_FAST_ROAMED_SESSION:8100`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_EAP_TYPEID`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_EAP_TLV`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_REJECT_REASON_CODE`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_PROXY_EAP_CONFIG`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_EAP_SESSION`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_IS_REPLAY`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_CLEAR_TEXT_PASSWORD`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_IDENTITY_TYPE`

Specifies the type of identity check to perform.

### `MS_ATTRIBUTE_SERVICE_CLASS`

Specifies which group of DHCP scopes correspond to the client requesting access.

### `MS_ATTRIBUTE_QUARANTINE_USER_CLASS:8110`

Vendor-specific attribute used to carry the name of a special DHCP user class, as specified in [RFC 3004](https://www.ietf.org/rfc/rfc3162.txt), called Network Access Protection (NAP) user class.

### `MS_ATTRIBUTE_QUARANTINE_STATE`

Specifies the target quarantine state of the client.

### `IAS_ATTRIBUTE_OVERRIDE_RAP_AUTH`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_PEAP_CHANNEL_UP`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_NAME_MAPPED`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_POLICY_ENFORCED`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_MACHINE_NTGROUPS`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_USER_NTGROUPS`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_MACHINE_TOKEN_GROUPS`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_USER_TOKEN_GROUPS`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_QUARANTINE_GRACE_TIME:8120`

Specifies the amount of time a host has to become conformant with network policy.

### `IAS_ATTRIBUTE_QUARANTINE_URL`

This attribute is reserved for system
use.

### `IAS_ATTRIBUTE_QUARANTINE_FIXUP_SERVERS`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_NOT_QUARANTINE_CAPABLE`

Vendor-specific attribute that specifies if the client is capable of reporting its state to the network access server (NAS). It must be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The client sent a Statement of Health (SoH). |
| 1 | The client did not send an SoH. |

### `IAS_ATTRIBUTE_QUARANTINE_SYSTEM_HEALTH_RESULT`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_QUARANTINE_SYSTEM_HEALTH_VALIDATORS`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_MACHINE_NAME`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_NT4_MACHINE_NAME`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_QUARANTINE_SESSION_HANDLE`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_FULLY_QUALIFIED_MACHINE_NAME`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_QUARANTINE_FIXUP_SERVERS_CONFIGURATION:8130`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_CLIENT_QUARANTINE_COMPATIBLE`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_NETWORK_ACCESS_SERVER_TYPE`

Specifies the access type of a network access server (NAS). A NAS may send this attribute to a RADIUS server to indicate the type of this NAS in an Access-Request message.

### `IAS_ATTRIBUTE_QUARANTINE_SESSION_ID`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_AFW_QUARANTINE_ZONE`

Vendor-specific attribute used as a hint for dynamic selection of a preconfigured Internet Protocol security (IPsec) policy by the client requesting access.

### `MS_ATTRIBUTE_AFW_PROTECTION_LEVEL`

Vendor-specific attribute used as a hint for dynamic selection of a preconfigured IPsec policy by the client requesting access.

### `IAS_ATTRIBUTE_QUARANTINE_UPDATE_NON_COMPLIANT`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_REQUEST_START_TIME`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_MACHINE_NAME`

Vendor-specific attribute used to communicate the machine name of the client requesting network access.

### `IAS_ATTRIBUTE_CLIENT_IPv6_ADDRESS`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_SAVED_RADIUS_FRAMED_INTERFACE_ID:8140`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_SAVED_RADIUS_FRAMED_IPv6_PREFIX`

### `IAS_ATTRIBUTE_SAVED_RADIUS_FRAMED_IPv6_ROUTE`

### `MS_ATTRIBUTE_QUARANTINE_GRACE_TIME_CONFIGURATION`

### `MS_ATTRIBUTE_IPv6_FILTER:8144`

Vendor-specific attribute used to limit the inbound and/or outbound access of the endpoint client.

### `MS_ATTRIBUTE_IPV4_REMEDIATION_SERVERS`

Specifies a list of servers that should be reachable by a quarantined client so that it may remediate itself.

### `MS_ATTRIBUTE_IPV6_REMEDIATION_SERVERS`

Specifies a list of servers that should be reachable by a quarantined client so that it may remediate itself.

### `IAS_ATTRIBUTE_PROXY_RETRY_COUNT`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_MACHINE_INVENTORY`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_ABSOLUTE_TIME`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_QUARANTINE_SOH:8150`

Vendor-specific attribute used only to carry Statement of Health (SoH) information when EAP is not used. A RADIUS server may send it to a network access server (NAS) in an Access-Accept message.

### `IAS_ATTRIBUTE_EAP_TYPES_CONFIGURED_IN_PROXYPOLICY`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_HCAP_LOCATION_GROUP_NAME`

Vendor-specific attribute specifying the location group name for the HCAP entity.

### `MS_ATTRIBUTE_EXTENDED_QUARANTINE_STATE`

Specifies the additional Quarantine state information for a user requesting access to this NAS.

### `IAS_ATTRIBUTE_SOH_CARRIER_EAPTLV`

This attribute is reserved for system use.

### `MS_ATTRIBUTE_HCAP_USER_GROUPS:8155`

An NAS may use this attribute to pass the group name of the user requesting network access to a RADIUS server, which may then use this information to make authentication or authorization decisions.

### `IAS_ATTRIBUTE_SAVED_MACHINE_HEALTHCHECK_ONLY`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_POLICY_EVALUATED_SHV`

Multiple instances of this attribute
can be present at one time.

### `MS_ATTRIBUTE_RAS_CORRELATION_ID`

TBD

### `MS_ATTRIBUTE_HCAP_USER_NAME`

An NAS may use this attribute to pass the name of the user requesting network access to a RADIUS server, which may then use this information to make authentication or authorization decisions.

### `IAS_ATTRIBUTE_NT4_HCAP_ACCOUNT_NAME:8160`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_USER_TOKEN_SID`

SID for IAS_ATTRIBUTE_NT4_ACCOUNT_NAME or IAS_ATTRIBUTE_NT4_HCAP_ACCOUNT_NAME
regardless of whether the later is a user account or a machine account.

### `IAS_ATTRIBUTE_MACHINE_TOKEN_SID`

SID for IAS_ATTRIBUTE_NT4_MACHINE_NAME.

### `IAS_ATTRIBUTE_MACHINE_VALIDATED`

TBD

### `MS_ATTRIBUTE_USER_IPv4_ADDRESS`

Specifies the IPv4 address of the user.

### `MS_ATTRIBUTE_USER_IPv6_ADDRESS:8165`

Specifies the IPv4 address of the user.

### `MS_ATTRIBUTE_TSG_DEVICE_REDIRECTION`

Vendor-specific attribute for TS Gateway Device Redirection flags.

### `IAS_ATTRIBUTE_ACCEPT_REASON_CODE`

TBD

### `IAS_ATTRIBUTE_LOGGING_RESULT`

TBD

### `IAS_ATTRIBUTE_SERVER_IP_ADDRESS`

TBD

### `IAS_ATTRIBUTE_SERVER_IPv6_ADDRESS`

TBD

### `IAS_ATTRIBUTE_RADIUS_USERNAME_ENCODING_ASCII`

TBD

### `MS_ATTRIBUTE_RAS_ROUTING_DOMAIN_ID:8172`

### `IAS_ATTRIBUTE_CERTIFICATE_THUMBPRINT:8250`

### `RAS_ATTRIBUTE_ENCRYPTION_TYPE`

Specifies the encryption type of the user's connection.

### `RAS_ATTRIBUTE_ENCRYPTION_POLICY`

Specifies the whether encryption is Allowed, Required, or None (disallowed). For more information, see
[RFC 2548](https://www.ietf.org/rfc/rfc2548.txt).

### `RAS_ATTRIBUTE_BAP_REQUIRED`

Specifies whether bandwidth allocation protocol (BAP) is required.

### `RAS_ATTRIBUTE_BAP_LINE_DOWN_TIME`

Time in seconds for the capacity utilization calculation.

### `RAS_ATTRIBUTE_BAP_LINE_DOWN_LIMIT`

Percent of capacity utilized at which to bring a line down for this user.

#### - IAS_ATTRIBUTE_NP_CONSTRAINT

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_SAVED_RADIUS_FRAMED_IPV6_PREFIX`

This attribute is reserved for system use.

### `IAS_ATTRIBUTE_SAVED_RADIUS_FRAMED_IPV6_ROUTE`

This attribute is reserved for system use.

## See also

[Attributes](https://learn.microsoft.com/windows/desktop/Nps/sdo-attributes)

[ISdoDictionaryOld](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdodictionaryold)