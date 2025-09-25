# RAS_CONNECTION_4 structure

## Description

Contains specific information for the connection that includes: the user name, domain, Globally Unique Identifier (GUID) associated with the connection, Network Access Protection (NAP) quarantine state, packet statistics, as well as its Point-to-Point (PPP) and Internet Key Exchange version 2 (IKEv2) related information.

## Members

### `dwConnectDuration`

A value that represent the duration of the connection in seconds.

### `dwInterfaceType`

A [ROUTER_INTERFACE_TYPE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type) enumeration that identifies the type of connection interface.

### `dwConnectionFlags`

A bitmap of flags that specify connection attributes. The **dwConnectionFlags** member must contain at least one of the following values.

| Value | Meaning |
| --- | --- |
| **RAS_FLAGS_PPP_CONNECTION**<br><br>0x00000001 | The connection is using Point-to-Point Protocol (PPP). |
| **RAS_FLAGS_MESSENGER_PRESENT**<br><br>0x00000002 | The messenger service is active on the client and messages can be sent to the client using the [MprAdminSendUserMessage](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminsendusermessage) function. |
| **RAS_FLAGS_QUARANTINE_PRESENT**<br><br>0x00000008 | The connection is currently in quarantine. For information on how to remove the connection from quarantine, please see [MprAdminConnectionRemoveQuarantine](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminconnectionremovequarantine). |
| **RAS_FLAGS_ARAP_CONNECTION**<br><br>0x00000010 | The connection is using AppleTalk Remote Access Protocol (ARAP). |
| **RAS_FLAGS_IKEV2_CONNECTION**<br><br>0x00000010 | The connection is using IKEv2. |
| **RAS_FLAGS_DORMANT**<br><br>0x00000020 | The connection is using IKEv2 and the server is not reachable. |

### `wszInterfaceName`

A null-terminated Unicode string that contains the name of the interface for this connection.

### `wszUserName`

A null-terminated Unicode string that contains the name of the user logged on to the connection.

### `wszLogonDomain`

A null-terminated Unicode string that contains the domain on which the connected user is authenticated.

### `wszRemoteComputer`

A null-terminated Unicode string that contains the name of the remote computer.

### `guid`

A GUID that identifies the connection. For incoming connections, this GUID is valid only as long as the connection is active.

### `rasQuarState`

A [RAS_QUARANTINE_STATE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-ras_quarantine_state) structure that specifies the NAP quarantine state of the connection.

### `probationTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the time required for the connection to come out of quarantine after which the connection will be dropped. This value is valid only if the **rasQuarState** member has a value of **RAS_QUAR_STATE_PROBATION**.

### `connectionStartTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the connection start time in UTC.

### `ullBytesXmited`

A value that specifies the number of bytes transmitted on the connection.

### `ullBytesRcved`

A value that specifies the number of bytes received on the connection.

### `dwFramesXmited`

A value that specifies the number of frames transmitted on the connection.

### `dwFramesRcved`

A value that specifies the number of frames received on the connection.

### `dwCrcErr`

A value that specifies the number of Cyclic Redundancy Check (CRC) errors on the connection.

### `dwTimeoutErr`

A value that specifies the number of time-out errors on the connection.

### `dwAlignmentErr`

A value that specifies the number of alignment errors on the connection.

### `dwHardwareOverrunErr`

A value that specifies the number of hardware overrun errors on the connection.

### `dwFramingErr`

A value that specifies the number of framing errors on the connection.

### `dwBufferOverrunErr`

A value that specifies the number of buffer overrun errors on the connection.

### `dwCompressionRatioIn`

A value that specifies the percentage by which data received on this connection is compressed. The **dwCompressionRatioIn** member is the size of the compressed data divided by the size of the same data in an uncompressed state.

### `dwCompressionRatioOut`

A value that specifies the percentage by which data transmitted on this connection is compressed. The ratio is the size of the compressed data divided by the size of the same data in an uncompressed state.

### `dwNumSwitchOvers`

A value that specifies the number of IKEv2 Mobility and Multihoming Protocol (MOBIKE) switches that have occurred on the connection. The **dwNumSwitchOvers** member is only valid if the **dwConnectionFlags** member is **RAS_FLAGS_IKEV2_CONNECTION**.

### `wszRemoteEndpointAddress`

A null-terminated Unicode string that contains the IP address of the remote computer in the connection. This string is of the form "a.b.c.d".

### `wszLocalEndpointAddress`

A null-terminated Unicode string that contains the IP address of the local computer in the connection. This string is of the form "a.b.c.d".

### `ProjectionInfo`

A [PROJECTION_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-projection_info2) structure that contains either a [PPP_PROJECTION_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_projection_info2) structure or a [IKEV2_PROJECTION_INFO2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ikev2_projection_info2) structure.

### `hConnection`

A handle to the RAS connection.

### `hInterface`

A handle to the RAS connection interface.

### `dwDeviceType`

A value that specifies the tunnel type of the VPN connection. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| **RDT_Tunnel_Pptp** | Point-to-Point tunnel (PPTP) |
| **RDT_Tunnel_L2tp** | L2TP tunnel |
| **RDT_Tunnel_Sstp** | SSTP tunnel |
| **RDT_Tunnel_IKev2** | IKEv2 tunnel |