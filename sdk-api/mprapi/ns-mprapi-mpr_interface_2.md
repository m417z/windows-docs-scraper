# MPR_INTERFACE_2 structure

## Description

The
**MPR_INTERFACE_2** structure contains data for a router demand-dial interface.

## Members

### `wszInterfaceName`

A pointer to a Unicode string that contains the name of the interface.

### `hInterface`

A handle to the interface.

### `fEnabled`

A value that specifies whether the interface is enabled. This value is **TRUE** if the interface is enabled, **FALSE** if the interface is administratively disabled.

### `dwIfType`

A value that identifies the
[interface type](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type).

### `dwConnectionState`

A value that describes the current state of the interface, for example, connected, disconnected, or unreachable. For more information and a list of possible states, see
[ROUTER_CONNECTION_STATE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_connection_state).

### `fUnReachabilityReasons`

A value that describes the reason why the interface is unreachable. For more information and a list of possible values, see [Unreachability Reasons](https://learn.microsoft.com/windows/desktop/RRAS/unreachability-reasons).

### `dwLastError`

A value that contains a nonzero value if the interface fails to connect.

### `dwfOptions`

A value that specifies bit flags that are used to set connection options. You can set one of the flags listed in the following table.

| Flag | Meaning |
| --- | --- |
| **MPRIO_SpecificIpAddr** | If this flag is set, RRAS attempts to use the IP address specified by **ipaddr** as the IP address for the dial-up connection. If this flag is not set, the value of the **ipaddr** member is ignored.<br><br>Setting the **MPRIO_SpecificIpAddr** flag corresponds to selecting the **Specify an IP Address** setting in the TCP/IP settings dialog box. Clearing the **MPRIO_SpecificIpAddr** flag corresponds to selecting the **Server Assigned IP Address** setting in the **TCP/IP Settings** dialog box.<br><br>Currently, an IP address set in the phone-book entry properties or retrieved from a server overrides the IP address set in the network control panel. |
| **MPRIO_SpecificNameServers** | If this flag is set, RRAS uses the **ipaddrDns**, **ipaddrDnsAlt**, **ipaddrWins**, and **ipaddrWinsAlt** members to specify the name server addresses for the dial-up connection. If this flag is not set, RRAS ignores these members.<br><br>Setting the MPRIO_SpecificNameServers flag corresponds to selecting the **Specify Name Server Addresses** setting in the TCP/IP Settings dialog box. Clearing the **MPRIO_SpecificNameServers** flag corresponds to selecting the **Server Assigned Name Server Addresses** setting in the **TCP/IP Settings** dialog box. |
| **MPRIO_IpHeaderCompression** | If this flag is set, RRAS negotiates to use IP header compression on PPP connections. IP header compression can significantly improve performance.<br><br>If this flag is not set, IP header compression is not negotiated.<br><br>This flag corresponds to the **Use IP Header Compression** check box in the **TCP/IP Settings** dialog box. The flag should be cleared only when connecting to a server that does not correctly negotiate IP header compression. |
| **MPRIO_RemoteDefaultGateway** | If this flag is set, the default route for IP packets is through the dial-up adapter when the connection is active. If this flag is cleared, the default route is not modified.<br><br>This flag corresponds to the **Use Default Gateway on Remote Network** check box in the **TCP/IP Settings** dialog box. |
| **MPRIO_DisableLcpExtensions** | If this flag is set, RRAS disables the PPP LCP extensions defined in [RFC 1570](https://learn.microsoft.com/windows/desktop/RRAS/routing-request-for-comments). Disabling the PPP LCP extensions may be necessary to connect to certain older PPP implementations, but it interferes with features such as server callback. Do not set this flag unless it is specifically required. |
| **MPRIO_SwCompression** | If this flag is set, software compression is negotiated on the link. Setting this flag causes the PPP driver to attempt to negotiate Compression Control Protocol (CCP) with the server. This flag should be set by default, but clearing it can reduce the negotiation period if the server does not support a compatible compression protocol. |
| **MPRIO_RequireEncryptedPw** | If this flag is set, only secure password schemes can be used to authenticate the client with the server. This prevents the PPP driver from using the PAP plain-text authentication protocol to authenticate the client. However, the MS-CHAP, MD5-CHAP, and SPAP authentication protocols are supported. For increased security, set this flag. For increased interoperability, clear this flag. <br><br>This flag corresponds to the **Require Encrypted Password** check box in the **Security** dialog box. For more information, see **MPRIO_RequireMsEncryptedPw**. |
| **MPRIO_RequireMsEncryptedPw** | If this flag is set, only the Microsoft secure password schemes can be used to authenticate the client with the server. This prevents the PPP driver from using the PAP plain-text authentication protocol, MD5-CHAP, or SPAP. For increased security, set this flag. For increased interoperability, clear this flag. This flag takes precedence over **MPRIO_RequireEncryptedPw**.<br><br>This flag corresponds to the **Require Microsoft Encrypted Password** check box in the **Security** dialog box. For more information, see **MPRIO_RequireDataEncryption**. |
| **MPRIO_RequireDataEncryption** | If this flag is set, data encryption must be negotiated successfully or the connection should be dropped. This flag is ignored unless **MPRIO_RequireMsEncryptedPw** is also set.<br><br>This flag corresponds to the **Require Data Encryption** check box in the **Security** dialog box. |
| **MPRIO_NetworkLogon** | This flag is reserved for future use. |
| **MPRIO_UseLogonCredentials** | If this flag is set, RRAS uses the user name, password, and domain of the currently logged-on user when dialing this entry. This flag is ignored unless **MPRIO_RequireMsEncryptedPw** is also set.<br><br>This setting is ignored by the [RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function where specifying empty strings for the **szUserName** and **szPassword** members of the [RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure provides the same result.<br><br>This flag corresponds to the **Use Current Username and Password** check box in the **Security** dialog box. |
| **MPRIO_PromoteAlternates** | This flag has an effect when alternate phone numbers are defined by the **szAlternates** member. If this flag is set, an alternate phone number that connects successfully becomes the primary phone number, and the current primary phone number is moved to the alternate list.<br><br>This flag corresponds to the check box in the **Alternate Numbers** dialog box. |
| **MPRIO_SecureLocalFiles** | If this flag is set, RRAS checks for existing remote file system and remote printer bindings before making a connection with this entry. Typically, you set this flag on phone-book entries for public networks to remind users to break connections to their private network before connecting to a public network. |
| **MPRIO_RequireEAP** | If this flag is set, Extensible Authentication Protocol (EAP) must be supported for authentication. |
| **MPRIO_RequirePAP** | If this flag is set, Password Authentication Protocol must be supported for authentication. |
| **MPRIO_RequireSPAP** | If this flag is set, Shiva's Password Authentication Protocol (SPAP) must be supported for authentication. |
| **MPRIO_SharedPhoneNumbers** | If this flag is set, phone numbers are shared. |
| **MPRIO_RequireCHAP** | If this flag is set, the Challenge Handshake Authentication Protocol must be supported for authentication. |
| **MPRIO_RequireMsCHAP** | If this flag is set, the Microsoft Challenge Handshake Authentication Protocol must be supported for authentication. |
| **MPRIO_RequireMsCHAP2** | If this flag is set, version 2 of the Microsoft Challenge Handshake Authentication Protocol must be supported for authentication. |
| **MPRIO_IpSecPreSharedKey** | If this flag is set for **dwfOptions** in the **MPR_INTERFACE_2** structure and is used in [MprAdminInterfaceSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetinfo), it configures the demand dial interface to use preshared key. |
| **MPRIO_RequireMachineCertificates** | Windows 8 or later: If this flag is set, machine certificates are used for IKEv2 authentication. |
| **MPRIO_UsePreSharedKeyForIkev2Initiator** | Windows 8 or later: If this flag is set, a pre-shared key is used by the initiator of the IKEv2 connection for authentication. |
| **MPRIO_UsePreSharedKeyForIkev2Responder** | Windows 8 or later: If this flag is set, a pre-shared key is used by the responder of the IKEv2 connection for authentication. |

### `szLocalPhoneNumber`

A value that specifies a null-terminated string that contains a telephone number.

### `szAlternates`

A pointer to a list of consecutive null-terminated Unicode strings. The last string is terminated by two consecutive null characters. The strings are alternate phone numbers that the router dials, in the order listed, if the primary number fails to connect. For more information, see **szLocalPhoneNumber**.

### `ipaddr`

A value that specifies the IP address to be used while this connection is active. This member is ignored unless **dwfOptions** specifies the
**MPRIO_SpecificIpAddr** flag.

### `ipaddrDns`

A value that specifies the IP address of the DNS server to be used while this connection is active. This member is ignored unless **dwfOptions** specifies the
**MPRIO_SpecificNameServers** flag.

### `ipaddrDnsAlt`

A value that specifies the IP address of a secondary or backup DNS server to be used while this connection is active. This member is ignored unless **dwfOptions** specifies the
**MPRIO_SpecificNameServers** flag.

### `ipaddrWins`

A value that specifies the IP address of the WINS server to be used while this connection is active. This member is ignored unless **dwfOptions** specifies the
**MPRIO_SpecificNameServers** flag.

### `ipaddrWinsAlt`

A value that specifies the IP address of a secondary WINS server to be used while this connection is active. This member is ignored unless **dwfOptions** specifies the
**MPRIO_SpecificNameServers** flag.

### `dwfNetProtocols`

A value that specifies the network protocols to negotiate. This member can be a combination of the following flags.

| Flag | Meaning |
| --- | --- |
| **MPRNP_Ipx** | Negotiate the IPX protocol. |
| **MPRNP_Ip** | Negotiate the TCP/IP protocol. |

**64-bit Windows:** The **MPRNP_Ipx** flag is not supported

### `szDeviceType`

A value that specifies a null-terminated string that indicates the RRAS device type that is referenced by **szDeviceName**. This member can be one of the following string constants.

| String | Meaning |
| --- | --- |
| **MPRDT_Modem** | A modem that is accessed through a COM port. |
| **MPRDT_Isdn** | An ISDN adapter with the corresponding NDISWAN driver installed. |
| **MPRDT_X25** | An X.25 adapter with the corresponding NDISWAN driver installed. |
| **MPRDT_Vpn** | A virtual private network (VPN) connection. |
| **MPRDT_Pad** | A packet assembler/disassembler. |
| **MPRDT_Generic** | Generic. |
| **MPRDT_Serial** | Direct serial connection through a serial port. |
| **MPRDT_FrameRelay** | Frame Relay. |
| **MPRDT_Atm** | Asynchronous Transfer Mode. |
| **MPRDT_Sonet** | Sonet. |
| **MPRDT_SW56** | Switched 56K Access. |
| **MPRDT_Irda** | An Infrared Data Association (IrDA)-compliant device. |
| **MPRDT_Parallel** | Direct parallel connection through a parallel port. |

### `szDeviceName`

Contains a null-terminated string that contains the name of a TAPI device to use with this phone-book entry, for example, "Fabrikam Inc 28800 External". To enumerate all available RAS-capable devices, use the
[RasEnumDevices](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumdevicesa) function.

### `szX25PadType`

A data type that contains a null-terminated string that identifies the X.25 PAD type. Set this member to an empty string ("") unless the entry should dial using an X.25 PAD.

**Windows 2000 and Windows NT:** The **szX25PadType** string maps to a section name in PAD.INF.

### `szX25Address`

Contains a null-terminated string that identifies the X.25 address to connect to. Set this member to an empty string ("") unless the entry should dial using an X.25 PAD or native X.25 device.

### `szX25Facilities`

Contains a null-terminated string that specifies the facilities to request from the X.25 host at connection time. This member is ignored if **szX25Address** is an empty string ("").

### `szX25UserData`

Contains a null-terminated string that specifies additional connection data supplied to the X.25 host at connection time. This member is ignored if **szX25Address** is an empty string ("").

### `dwChannels`

Reserved for future use.

### `dwSubEntries`

A value that specifies the number of multilink subentries associated with this entry. When calling
[RasSetEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetentrypropertiesa), set this member to zero. To add subentries to a phone-book entry, use the
[RasSetSubEntryProperties](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rassetsubentrypropertiesa) function.

### `dwDialMode`

Indicates whether RRAS should dial all of this entry's multilink subentries when the entry is first connected. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MPRDM_DialAll** | Dial all subentries initially. |
| **MPRDM_DialAsNeeded** | Adjust the number of subentries as bandwidth is required. RRAS uses the **dwDialExtraPercent**, **dwDialExtraSampleSeconds**, **dwDialHangUpExtraPercent**, and **dwHangUpExtraSampleSeconds** members to determine when to dial or disconnect a subentry. |

### `dwDialExtraPercent`

A value that specifies the percentage of the total bandwidth that is available from the currently connected subentries. RRAS dials an additional subentry when the total bandwidth that is used exceeds **dwDialExtraPercent** percent of the available bandwidth for at least **dwDialExtraSampleSeconds** seconds.

This member is ignored unless the **dwDialMode** member specifies the **MPRDM_DialAsNeeded** flag.

### `dwDialExtraSampleSeconds`

A value that specifies the time, in seconds, for which current bandwidth usage must exceed the threshold that is specified by **dwDialExtraPercent** before RRAS dials an additional subentry.

This member is ignored unless the **dwDialMode** member specifies the **MPRDM_DialAsNeeded** flag.

### `dwHangUpExtraPercent`

A value that specifies the percentage of the total bandwidth that is available from the currently connected subentries. RRAS terminates (hangs up) an existing subentry connection when the total bandwidth used is less than **dwHangUpExtraPercent** percent of the available bandwidth for at least **dwHangUpExtraSampleSeconds** seconds.

This member is ignored unless the **dwDialMode** member specifies the **MPRDM_DialAsNeeded** flag.

### `dwHangUpExtraSampleSeconds`

A value that specifies the time, in seconds, for which current bandwidth usage must be less than the threshold that is specified by **dwHangUpExtraPercent** before RRAS terminates an existing subentry connection.

This member is ignored unless the **dwDialMode** member specifies the **MPRDM_DialAsNeeded** flag.

### `dwIdleDisconnectSeconds`

A value that specifies the time, in seconds, after which an inactive connection is terminated. Unless the idle time-out is disabled, the entire connection is terminated if the connection is idle for the specified interval. This member can specify either a time-out value, or one of the following values.

| Value | Meaning |
| --- | --- |
| **MPRIDS_Disabled** | There is no idle time-out for this connection. |
| **MPRIDS_UseGlobalValue** | Use the user preference value as the default. |

### `dwType`

A value that specifies the type of phone-book entry. This member can be one of the following types.

| Type | Meaning |
| --- | --- |
| **MPRET_Phone** | Phone line, for example, modem, ISDN, or X.25. |
| **MPRET_Vpn** | Virtual Private Network. |
| **MPRET_Direct** | Direct serial or parallel connection. |

### `dwEncryptionType`

A value that specifies the type of encryption to use for Microsoft Point-to-Point Encryption (MPPE) with the connection. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MPR_ET_None** | Do not use encryption. |
| **MPR_ET_Require** | Use encryption. |
| **MPR_ET_RequireMax** | Use maximum-strength encryption. |
| **MPR_ET_Optional** | If possible, use encryption. |

The value of **dwEncryptionType** does not affect how passwords are encrypted. Whether passwords are encrypted and how passwords are encrypted is determined by the authentication protocol, for example, PAP, MS-CHAP, or EAP.

### `dwCustomAuthKey`

A value that specifies the authentication key to be provided to an Extensible Authentication Protocol (EAP) vendor.

### `dwCustomAuthDataSize`

A value that specifies the size of the data pointed to by the **lpbCustomAuthData** member.

### `lpbCustomAuthData`

A pointer to authentication data to use with EAP.

### `guidId`

The globally unique identifier (GUID) that represents this phone-book entry. This member is read-only.

### `dwVpnStrategy`

The VPN strategy to use when dialing a VPN connection. This member can have one of the following values.

| Value | Meaning |
| --- | --- |
| **MPR_VS_Default** | RRAS dials PPTP first. If PPTP fails, L2TP is attempted. The protocol that succeeds is tried first in subsequent dialing for this entry. |
| **MPR_VS_PptpOnly** | RAS dials only PPTP. |
| **MPR_VS_PptpFirst** | RAS always dials PPTP first, L2TP second. |
| **MPR_VS_L2tpOnly** | RAS dials only L2TP. |
| **MPR_VS_L2tpFirst** | RAS dials L2TP first, PPTP second. |

## Remarks

The
**MPR_INTERFACE_2** structure has a number of members that are similar to members of the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure.

The following members from the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure have no counterpart in
**MPR_INTERFACE_2**:

* **dwCountryID**
* **dwCountryCode**
* **szAreaCode**
* **dwFramingProtocol**

**64-bit Windows:** Does not support the IPX protocol.

## See also

[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0)

[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1)

[MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo)

[MprAdminInterfaceSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacesetinfo)