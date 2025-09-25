## Description

The **EAP_ATTRIBUTE_TYPE** enumeration defines the set of possible EAP attribute types available on an authenticating entity.

Further details for values in this enumerated type are obtained by referring to one of the following references:
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt),
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt),
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt), [RFC 2868](https://www.ietf.org/rfc/rfc2868.txt), [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt), [RFC 3579](https://www.ietf.org/rfc/rfc3579.txt), or [RFC 3580](https://www.ietf.org/rfc/rfc3580.txt).

## Constants

### `eatMinimum:0`

Specifies a value equal to zero, and used as the **NULL** terminator in any array of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) structures.

This attribute type is consumed by PPP client supplicants.

### `eatUserName`

Specifies the name of the user to be authenticated. This attribute type is also used when the user's password is changed. For Routing and Remote Access Service (RRAS) authentication sessions, the identity string (name) of the authenticating user is sent to IAS as part of the request attributes. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a multi-byte string with no NULL termination character. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is exported by MS-CHAPv2 methods and by PEAP methods. It is consumed by PPP server supplicants.

### `eatUserPassword`

Specifies the password of the user to be authenticated. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatMD5CHAPPassword`

Specifies the password provided by the user in response to an MD5 Challenge Handshake Authentication Protocol (CHAP) challenge. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatNASIPAddress`

Specifies the IP address of the Network Access Server (NAS) that is requesting user authentication. An Access-Request should specify either an NAS IP address or an NAS identifier. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatNASPort`

Specifies the physical or virtual private network (VPN) through which the user is connecting to the NAS. Note that this value is not a port number in the sense of TCP or UDP. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatServiceType`

Specifies the type of service the user has requested or the type of service to be provided. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatFramedProtocol`

Specifies the type of framed protocol to use for framed access, for example SLIP, PPP, or ARAP (AppleTalk Remote Access Protocol). The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatFramedIPAddress`

Specifies the IP address that is configured for the user requesting authentication. This attribute is typically returned by the authentication provider. However, the NAS may use it in an authentication request to specify a preferred IP address. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatFramedIPNetmask`

Specifies the IP network mask for a user that is a router to a network. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatFramedRouting:10`

Specifies the routing method for a user that is a router to a network. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatFilterId`

Specifies the name of the filter list for the user requesting authentication. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatFramedMTU`

Specifies the Maximum Transmission Unit (MTU) for the user. This attribute is used in cases where the MTU is not negotiated through some other means, such as PPP. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatFramedCompression`

Specifies a compression protocol to use for the connection. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatLoginIPHost`

Specifies the system with which to connect the user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatLoginService`

Specifies the service to use to connect the user to the host specified by **eatLoginIPHost**. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatLoginTCPPort`

Specifies the port to which to connect the user. This attribute is present only if the **eatLoginService** attribute is present. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatUnassigned17`

This value is currently unassigned.

This attribute type is not used by EAPHost methods or supplicants.

### `eatReplyMessage`

Specifies a message to display to the user. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type consumed by the PPP server supplicant. This attribute type should not be used by any other method or supplicant. **eatEAPMessage** should be used to sent displayable messages whenever possible. For more information, see [RFC 3580](https://www.ietf.org/rfc/rfc3580.txt).

### `eatCallbackNumber`

Specifies a callback number. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatCallbackId:20`

Specifies a location to call back. The value of this attribute is interpreted by the NAS. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatUnassigned21`

This value is currently unassigned.

This attribute type is not used by EAPHost methods or supplicants.

### `eatFramedRoute`

Specifies routing information to configure on the NAS for the user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatFramedIPXNetwork`

Specifies the IPX network number to configure for the user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatState`

Specifies state information provided to the client by the server. For RRAS authentication sessions, if authentication completed successfully and IAS returned attributes, then this state information is saved and used as input when constructing the request attributes for IAS during the next packet cycle. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. Refer to
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for detailed information about this value.

This attribute type is consumed by PPP server supplicants.

### `eatClass`

Specifies a value that is provided to the NAS by the authentication provider. The NAS should use this value when communicating with the accounting provider. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatVendorSpecific`

Specifies a field for vendor-supplied extended attributes.

This field is used to store Microsoft Point-to-Point Encryption (MPPE) keys consumed by the [802.1X](https://learn.microsoft.com/previous-versions/windows/embedded/ms890287(v=msdn.10)) supplicant. For more information, see [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

The following table shows the structure of the data pointed to by the **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type.

| First Byte | Last Byte | Description |
| --- | --- | --- |
| 0 | 3 | Length: 4 bytes The vendor identifier. This field always has a value of 311. |
| 4 | 4 | Length: 1 byte The type of MPPE key. If the attribute refers to a MPPE send key, then this field has a value of 16. If the attribute refers to a MPPE receive key, then this field has a value of 17. |
| 5 | 5 | Length: 1 byte The MPPE vendor-specific attribute length. This field always has a value of 52. |
| 6 | 7 | Length: 2 bytesSalt. This field always has a value of 0. |
| 8 | 8 | Length: 1 byte The MPPE key length. This field always has a value of 32. |
| 9 | 40 | Length: 32 bytes The MPPE key. The field contents are as follows:<br><br>* For MPPE send keys used on a client, this field contains the first 32 bytes (bytes 0-31) of the master session key (MSK).<br>* For MPPE send keys used on a server, this field contains the second 32 bytes (bytes 32-63) of the MSK.<br>* For MPPE receive keys used on a client, this field contains the second 32 bytes (bytes 32-63) of the MSK.<br>* For MPPE receive keys used on a server, this field contains the first 32 bytes (bytes 0-31) of the MSK. |
| 41 | 55 | Length: 15 bytesPadding. |

This attribute type is consumed by 802.1X supplicants.

### `eatSessionTimeout`

Specifies the maximum number of seconds for which to provide service to the user. After this time, the session is terminated. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is typically used by EAP methods to set the timeout duration for authentication within an Access-Challenge packet. The duration of the timeout is determined by IAS, not the EAP method.

For RRAS authentication sessions, if authentication succeeded and there is a pending packet to be sent, the packet is sent with an interactive timeout if the corresponding **eatSessionTimeout** value is greater than 10.

This attribute type is consumed by PPP server supplicants.

### `eatIdleTimeout`

Specifies the maximum number of consecutive seconds the session can be idle. If the idle time exceeds this value, the session is terminated. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatTerminationAction`

Specifies an action the server performs when time the connection terminates. Refer to the above-referenced files for detailed information about this value. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatCalledStationId:30`

Specifies the phone number called using Dialed Number Identification (DNIS) or similar technology. The phone number called by the user may be different than the phone number from which the call originated. This attribute type may also be used to store other types of information, such as MAC addresses. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see [RFC 3580](https://www.ietf.org/rfc/rfc3580.txt).

### `eatCallingStationId`

Specifies the originating phone number for a call, using Automatic Number Identification (ANI) or similar technology. This attribute type may also be used to store other types of information, such as MAC addresses. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see [RFC 3580](https://www.ietf.org/rfc/rfc3580.txt).

### `eatNASIdentifier`

Specifies the NAS identifier. An Access-Request should specify either an NAS identifier or an NAS IP address. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatProxyState`

Specifies a value that a proxy server includes when forwarding an authentication request. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatLoginLATService`

Not used. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatLoginLATNode`

Not used. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatLoginLATGroup`

Not used. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatFramedAppleTalkLink`

Specifies the AppleTalk network number for the user when the user is another router. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatFramedAppleTalkNetwork`

Specifies the AppleTalk network number that the NAS should use to allocate an AppleTalk node for the user. This attribute is used only when the user is not another router. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatFramedAppleTalkZone`

Specifies the AppleTalk default zone for the user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctStatusType:40`

Specifies whether the accounting provider should start or stop accounting for the user. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctDelayTime`

Specifies the length of time that the client has been attempting to send the current request. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctInputOctets`

Specifies the number of octets that have been received during the current accounting session. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctOutputOctets`

Specifies the number of octets that were sent during the current accounting session. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctSessionId`

Specifies a value to enable the identification of matching start and stop records within a log file. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctAuthentic`

Specifies, to the accounting provider, how the user was authenticated; for example by Directory Services, RADIUS, or some other authentication provider. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctSessionTime`

Specifies the number of seconds that have elapsed in the current accounting session. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctInputPackets`

Specifies the number of packets that have been received during the current accounting session. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctOutputPackets`

Specifies the number of packets that have been sent during the current accounting session. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctTerminateCause`

Specifies how the current accounting session was terminated. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctMultiSessionId:50`

Specifies a value to enable the identification of related accounting sessions within a log file. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctLinkCount`

Specifies the number of links if the current accounting session is using a multilink connection. For more information, see
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctEventTimeStamp:55`

Specifies an attribute that is included in an accounting request packet. It specifies the time that the event took place. For more information, see [RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatMD5CHAPChallenge:60`

Specifies the CHAP challenge sent by the NAS to a CHAP user. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatNASPortType`

Specifies the type of the port through which NAS is authenticating the user, for example, asynchronous, ISDN, virtual. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatPortLimit`

Specifies the number of ports the NAS should make available to the user for multilink sessions. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatLoginLATPort`

Not used. For more information, see
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt).

### `eatTunnelType`

Specifies the tunneling protocol used.

This attribute type is not used by EAPHost methods or supplicants.

### `eatTunnelMediumType`

Specifies which transport medium to use when creating a tunnel for those protocols (such as L2TP) that can operate over multiple transports.

This attribute type is not used by EAPHost methods or supplicants.

### `eatTunnelClientEndpoint`

Points to the address of the initiator end of the tunnel.

This attribute type is not used by EAPHost methods or supplicants.

### `eatTunnelServerEndpoint`

Points to the address of the server end of the tunnel.

This attribute type is not used by EAPHost methods or supplicants.

### `eatARAPPassword:70`

Specifies a password to use for AppleTalk Remote Access Protocol (ARAP) authentication. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatARAPFeatures`

Specifies information that an NAS should send back to the user in an ARAP "feature flags" packet. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatARAPZoneAccess`

Specifies how to use the ARAP zone list for the user. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatARAPSecurity`

Specifies an ARAP security module to use during a secondary authentication phase between the NAS and the user. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatARAPSecurityData`

Specifies the data to use with an ARAP security module. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatPasswordRetry`

Specifies the number of password retry attempts to permit the user access. This attribute type is deprecated for EAP and RADIUS/EAP. For more information, see [RFC 3579](https://www.ietf.org/rfc/rfc3579.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatPrompt`

Specifies whether the NAS should echo the user response to a challenge. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatConnectInfo`

Specifies information about the type of connection the user is using. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatConfigurationToken`

Specifies user-profile information in communications between RADIUS Proxy Servers and RADIUS Proxy Clients. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatEAPMessage`

Specifies that EAP information be sent directly between the user and the authentication provider. For RRAS authentication sessions, this attribute type is used to retrieve the EAP message from the authenticator and send the message to the client. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is consumed by PPP server supplicants.

### `eatSignature:80`

Specifies a signature to include with CHAP, EAP, or ARAP packets. For more information,
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatARAPChallengeResponse:84`

Specifies the response to a Apple Remote Access Protocol (ARAP) challenge. In ARAP, either the server or the client may respond to challenges. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatAcctInterimInterval:85`

Specifies the time, in seconds, between accounting updates. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatNASIPv6Address:95`

The IPv6 address of the NAS requesting user authentication. This address should be unique to the NAS within the scope of the RADIUS server. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt).

### `eatFramedInterfaceId`

The IPv6 interface identifier to be configured for the user. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt).

### `eatFramedIPv6Prefix`

The IPv6 prefix (and corresponding route) to be configured for the user. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string. For more information, see [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt).

### `eatLoginIPv6Host`

Not used.

### `eatFramedIPv6Route`

Not used.

### `eatFramedIPv6Pool`

Not used.

### `eatARAPGuestLogon:8096`

Specifies a Apple Remote Access Protocol (ARAP) guest logon. For more information, see
[RFC 2869](https://www.ietf.org/rfc/rfc2869.txt).

This attribute type is not used by EAPHost methods or supplicants.

### `eatCertificateOID`

The object identifier (OID) present on the certificate. This attribute type is used in certificate-based authentication sessions. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string.

This attribute type is exported by EAP-TLS and NPS methods.

### `eatEAPConfiguration`

Not used.

### `eatPEAPEmbeddedEAPTypeId`

The identifier of the inner EAP method used in PEAP authentication. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a DWORD. Only the least significant byte of the DWORD is meaningful.

This attribute type is exported by PEAP methods and is not consumed by any supplicant.

### `eatPEAPFastRoamedSession:8100`

Specifies whether PEAP fast reconnect is used by the authenticator. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a DWORD. If **pValue** points to 0, then fast reconnect is not used by the authenticator. If **pValue** points to a nonzero value, then fast reconnect is used by the authenticator.

This attribute type is exported by PEAP methods and consumed by PPP client supplicants.

### `eatFastRoamedSession:8100`

TBD

### `eatEAPTLV:8102`

An EAP-TLV attribute. This attribute type is used to handle statement of health (SoH) requests and SoH responses from the server.

The following table shows the structure of the data pointed to by the **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type.

| First Byte | Last Byte | Description |
| --- | --- | --- |
| 0 | 1 | Length: 2 bytes The buffer type. This field always has a value of 7. |
| 2 | 3 | Length: 2 bytes The length of the remaining contents of the buffer. For SoH requests from the server, this field has a value of 6. For SoH responses from the server, calculate the length by adding 8 to the number of bytes in the SoH payload. |
| 4 | 7 | Length: 4 bytes The vendor identifier. This field always has a value of 311. |
| 8 | 9 | Length: 2 bytes The SoH type. For SoH requests from the server, this field has a value of 2. For SoH responses from the server, this field has a value of 3. |
| 10 | 11 | Length: 2 bytes The number of bytes of data in the SoH payload. |
| 12 |  | Length: Variable The SoH payload returned by the NAP system. The supplicant should not attempt to interpret this data. |

This attribute type is consumed by PPP client supplicants and by EAPHost supplicants.

### `eatCredentialsChanged`

Specifies whether credentials have changed during EAP authentication. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a DWORD. If **pValue** points to 0, then the credentials have not changed. If **pValue** points to a nonzero value, then credentials have changed.

This attribute type may be exported by MS-CHAPv2 methods, and is consumed by PPP client supplicants.

### `eatInnerEapMethodType`

The inner EAP method used inside native tunnel methods. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to an [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure.

This attribute type is exported by EAP methods.

### `eatClearTextPassword:8107`

The password, in clear text, of the user to be authenticated. This attribute type is sent by EAP methods that use EAPHost to raise the identity user interface. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to an [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure.

This attribute type is exported by EAPHost.

### `eatQuarantineSoH:8150`

Contains SoH request and response information used during EAP authentication. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string.

This attribute type is exported by EAPHost and PEAP methods, and consumed by PPP server supplicants.

### `eatCertificateThumbprint:8250`

TBD

### `eatPeerId:9000`

The peer identity provided in the identity response message (EAP-Response/Identity). This identity may be different than the peer identity authenticated by the EAP method. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to an ASCII string. The string will be **NULL** if the EAP peer identity does not exist. For more information, see the [Key Management Framework draft specification](https://www.ietf.org/).

This attribute type is exported by EAP methods and consumed by supplicants.

### `eatServerId`

The identity of the server used when the EAP method authenticates to the server. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to an ASCII string. The string will be **NULL** if an EAP method does not define a method-specific peer identity. For more information, see the [Key Management Framework draft specification](https://www.ietf.org/).

This attribute type is exported by EAP methods and consumed by supplicants.

### `eatMethodId`

A temporally unique method identifier that identifies an EAP session of a given type between a peer and a server. Any EAP method that derives keys must specify this attribute type. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a DWORD. For more information, see the [Key Management Framework draft specification](https://www.ietf.org/).

This attribute type is exported by EAPHost methods and other EAP methods, and consumed by supplicants.

### `eatEMSK`

The extended session master key (EMSK). This key material is derived between the peer and the server, and should not be shared with a third party. The **pValue** member of
[EAP_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attribute) for this type points to a byte string, which should contain at least 64 octets of key material. For more information, see the [Key Management Framework draft specification](https://www.ietf.org/).

This attribute type is exported by EAP methods and consumed by supplicants.

### `eatSessionId`

Windows Vista with SP1 or later: An attribute type that carries the session identity.

### `eatReserved`

Not used.

## See also

[About EAP Attributes](https://learn.microsoft.com/windows/win32/eaphost/about-eap-attributes)

[PEAP](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc757996(v=ws.10))