# RADIUS_ATTRIBUTE_TYPE enumeration

## Description

> [!NOTE]
> Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The **RADIUS_ATTRIBUTE_TYPE** type enumerates the possible types for a RADIUS attribute.

## Constants

### `ratMinimum`

This value is equal to zero, and used as the null-terminator in any array of [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) structures.

### `ratUserName`

Specifies the name of the user to be authenticated. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information. Also see [User Identification Attributes](https://learn.microsoft.com/windows/win32/Nps/ias-user-identification-attributes).

### `ratUserPassword`

Specifies the password of the user to be authenticated. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratCHAPPassword`

Specifies the password provided by the user in response to a Challenge Handshake Authentication Protocol (CHAP) challenge. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratNASIPAddress`

Specifies the NAS IP address. An Access-Request should specify either an NAS IP address or an NAS identifier. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratNASPort`

Identifies the physical or virtual private network (VPN) through which the user is connecting to the NAS. Note that this value is not a port number in the sense of TCP or UDP. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratServiceType`

Specifies the type of service the user has requested or the type of service to be provided. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedProtocol`

Specifies the type of framed protocol to use for framed access, for example SLIP, PPP, or ARAP (AppleTalk Remote Access Protocol). The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedIPAddress`

Specifies the IP address that will be configured for the user requesting authentication. This attribute is typically returned by the authentication provider. However, the NAS may use it in an authentication request to specify a preferred IP address. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedIPNetmask`

Specifies the IP network mask for a user that is a router to a network. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedRouting`

Specifies the routing method for a user that is a router to a network. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFilterId`

Identifies the filter list for the user requesting authentication. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedMTU`

Specifies the Maximum Transmission Unit (MTU) for the user. This attribute is used in cases where the MTU is not negotiated through some other means, such as PPP. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedCompression`

Specifies a compression protocol to use for the connection. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information

### `ratLoginIPHost`

Specifies the system with which to connect the user. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratLoginService`

Specifies the service to use to connect the user to the host specified by **ratLoginIPHost**. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratLoginPort`

Specifies the port to which to connect the user. This attribute is present only if the **ratLoginService** attribute is present. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratReplyMessage`

Specifies a message to display to the user. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratCallbackNumber`

Specifies a callback number. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratCallbackId`

Identifies a location to callback. The value of this attribute is interpreted by the NAS. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedRoute`

Provides routing information to configure on the NAS for the user. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedIPXNetwork`

Specifies the IPX network number to configure for the user. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratState`

This attribute is included in Access-Challenge and Access-Accept communications between the server and the client. Please refer to [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for detailed information about this value. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer.

### `ratClass`

Specifies a value that is provided to the NAS by the authentication provider. The NAS should use this value when communicating with the accounting provider. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratVendorSpecific`

Allows vendors to provide their own extended attributes. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratSessionTimeout`

Specifies the maximum number of seconds for which to provide service to the user. After this time, the session is terminated. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratIdleTimeout`

Specifies the maximum number of consecutive seconds the session can be idle. If the idle time exceeds this value, the session is terminated. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratTerminationAction`

Indicates what action the NAS should take when the specified service is completed. It is only used in Access-Accept packets. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratCalledStationId`

Specifies the number that the user dialed to connect to the NAS. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratCallingStationId`

Specifies the number from which the user is calling. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratNASIdentifier`

Specifies the NAS identifier. An Access-Request should specify either an NAS identifier or an NAS IP address. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratProxyState`

Specifies a value that a proxy server includes when forwarding an authentication request. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratLoginLATService`

This attribute is not currently used for authentication on Windows. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratLoginLATNode`

This attribute is not currently used for authentication on Windows. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratLoginLATGroup`

This attribute is not currently used for authentication on Windows. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedAppleTalkLink`

Specifies the AppleTalk network number for a user that is another router. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedAppleTalkNetwork`

Specifies the AppleTalk network number that the NAS should use to allocate an AppleTalk node for the user. This attribute is used only when the user is not another router. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratFramedAppleTalkZone`

Specifies the AppleTalk default zone for the user. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratAcctStatusType`

Specifies whether the accounting provider should start or stop accounting for the user. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `ratAcctDelayTime`

Specifies the length of time that the client has been attempting to send the current request. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `ratAcctInputOctets`

Specifies the number of octets that have been received during the current accounting session. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `ratAcctOutputOctets`

Specifies the number of octets sent during the current accounting session. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `ratAcctSessionId`

Specifies a value to enable the identification of matching start and stop records within a log file. The start and stop records are sent in the **ratAcctStatusType** attribute. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `ratAcctAuthentic`

Specifies, to the accounting provider, how the user was authenticated. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `ratAcctSessionTime`

Specifies the number of seconds that have elapsed in the current accounting session. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `ratAcctInputPackets`

Specifies the number of packets that have been received during the current accounting session. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `ratAcctOutputPackets`

Specifies the number of packets that have been sent during the current accounting session. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `ratAcctTerminationCause`

Specifies how the current accounting session was terminated. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `ratCHAPChallenge`

Specifies the CHAP challenge sent by the NAS to a CHAP user. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a pointer. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratNASPortType`

Specifies the type of the port through which the user is connecting, for example, asynchronous, ISDN, virtual. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `ratPortLimit`

Specifies the number of ports the NAS should make available to the user for multilink sessions. The value field in [RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute) for this type is a 32-bit integral value. See [RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information

### `ratTunnelType`

Specifies either the tunneling protocol or protocols to be used (in the case of a tunnel initiator) or specifies the tunneling protocol in use (in the case of a tunnel terminator). See [RFC 2868](https://www.ietf.org/rfc/rfc2868.txt) for more information.

### `ratMediumType`

Specifies the transport medium to use when creating a tunnel for protocols, such as L2TP, that can operate over multiple transports. See [RFC 2868](https://www.ietf.org/rfc/rfc2868.txt) for more information.

### `ratTunnelPassword`

May contain a password to be used to authenticate to a remote server. It may only be included in an Access-Accept packet.

### `ratTunnelPrivateGroupID`

Specifies the group ID for a particular tunneled session.

### `ratNASIPv6Address`

Specifies the IPv6 Address of the NAS that requests authentication of the user. It should be unique to the NAS within the scope of the RADIUS server. It is only used in an Access-Request packet. See the NAS-IPv6-Address section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `ratFramedInterfaceId`

Specifies the IPv6 interface identifier to be configured for the user. It may be used in an Access-Accept packet. See the Framed-Interface-Id section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `ratFramedIPv6Prefix`

Specifies an IPv6 prefix (and corresponding route) to be configured for the user. It may be used in an Access-Accept packet and can appear multiple times. See the Framed-IPv6-Prefix section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `ratLoginIPv6Host`

Specifies the system with which to connect the user, when the ratLoginService attribute is included. It may be used in an Access-Accept packet. See the Login-IPv6-Host section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `ratFramedIPv6Route`

Specifies routing information to be configured for the user on the NAS. It is used in an Access-Accept packet and can appear multiple times. See the Framed-IPv6-Route section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `ratFramedIPv6Pool`

Specifies the name of an assigned pool that should be used to assign an IPv6 prefix for the user. If a NAS does not support multiple prefix pools, the NAS must ignore this attribute. See the Framed-IPv6-Pool section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `ratCode`

Specifies the request type code. This is an extended, read-only attribute, used only in the [RadiusExtensionProcess](https://learn.microsoft.com/windows/win32/api/authif/nc-authif-pradius_extension_process) and [RadiusExtensionProcessEx](https://learn.microsoft.com/windows/win32/api/authif/nc-authif-pradius_extension_process_ex) functions. Its contents can be interpreted by comparing it with [RADIUS_CODE](https://learn.microsoft.com/windows/win32/api/authif/ne-authif-radius_code) enumeration values.

### `ratIdentifier`

Specifies the request identifier. This is an extended, read-only attribute.

### `ratAuthenticator`

Specifies the request authenticator. This is an extended, read-only attribute.

### `ratSrcIPAddress`

Specifies the source IP address. This is an extended, read-only attribute.

### `ratSrcPort`

Specifies the source IP port. This is an extended, read-only attribute.

### `ratProvider`

Specifies the authentication provider. The value for this attribute is taken from the [RADIUS_AUTHENTICATION_PROVIDER](https://learn.microsoft.com/windows/win32/api/authif/ne-authif-radius_authentication_provider) enumerated type. This is an extended, read-only attribute.

### `ratStrippedUserName`

Specifies the user name with the realm removed. See [User Identification Attributes](https://learn.microsoft.com/windows/win32/Nps/ias-user-identification-attributes) for more information. This is an extended attribute.

### `ratFQUserName`

Specifies the fully qualified user name. See [User Identification Attributes](https://learn.microsoft.com/windows/win32/Nps/ias-user-identification-attributes) for more information. This is an extended attribute.

### `ratPolicyName`

Specifies a remote access policy name. This is an extended attribute.

### `ratUniqueId`

Specifies a unique ID for the request. This is a read-only attribute.

### `ratExtensionState`

This attribute is used to pass state information between extensions.

### `ratEAPTLV`

Specifies an EAP-TLV packet. For more information about the EAP-TLV packet format, see [IETF EAP RFC 3748](https://www.ietf.org/rfc/rfc3748.txt).

### `ratRejectReasonCode`

Specifies the reason code for a RADIUS Reject. For more information, see [RADIUS_REJECT_REASON_CODE](https://learn.microsoft.com/windows/win32/api/authif/ne-authif-radius_reject_reason_code).

### `ratCRPPolicyName`

Specifies the Connection Request Policy Name that matched this RADIUS packet.

### `ratProviderName`

Specifies the remote RADIUS server group name for request forwarding.

If the Authentication indicated by **ratProvider** is a proxy, the extension DLL can change the **ratProviderName** to indicate which remote server group the request should be forwarded to.

### `ratClearTextPassword`

Specifies the user password in clear text.

To support authorization databases using PEAP-MSChapv2, the extension DLL retrieves the user password from the database and sends it to NPS.

### `ratSrcIPv6Address`

Source IPv6 address. It is not a standard RADIUS attribute. It corresponds to the internal attribute [IAS_ATTRIBUTE_CLIENT_IPv6_ADDRESS](https://learn.microsoft.com/windows/win32/api/sdoias/ne-sdoias-attributeid). This is a read-only attribute.

### `ratCertificateThumbprint`

Specifies the certificate thumbprint. It is not a standard RADIUS attribute. It corresponds to the internal attribute [IAS_ATTRIBUTE_CERTIFICATE_THUMBPRINT](https://learn.microsoft.com/windows/win32/api/sdoias/ne-sdoias-attributeid). This is an extended attribute.

## Remarks

The following attributes are read-only. Extension DLLs that implement [RadiusExtensionProcess2](https://learn.microsoft.com/windows/win32/api/authif/nc-authif-pradius_extension_process_2) cannot add/remove/modify these attributes within a request or response contained in a [RADIUS_EXTENSION_CONTROL_BLOCK](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_extension_control_block).

- **ratCode**
- **ratIdentifier**
- **ratAuthenticator**
- **ratSrcIPAddress**
- **ratSrcPort**
- **ratProvider**
- **ratUniqueId**
- **ratSrcIPv6Address**

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/win32/Nps/ias-about-internet-authentication-service)

[NPS Extensions Enumerations](https://learn.microsoft.com/windows/win32/Nps/ias-internet-authentication-service-enumerations)

[NPS Extensions Reference](https://learn.microsoft.com/windows/win32/Nps/ias-internet-authentication-service-reference)

[RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/win32/api/authif/ns-authif-radius_attribute)

[RADIUS_AUTHENTICATION_PROVIDER](https://learn.microsoft.com/windows/win32/api/authif/ne-authif-radius_authentication_provider)