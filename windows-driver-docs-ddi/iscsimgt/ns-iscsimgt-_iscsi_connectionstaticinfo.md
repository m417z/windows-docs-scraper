# _ISCSI_ConnectionStaticInfo structure

## Description

The ISCSI_ConnectionStaticInfo structure contains information about the characteristics of an established connection.

## Members

### `UniqueConnectionId`

The connection identifier (ID) that the operating system and application software use to uniquely identify the connection. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in the *UniqueConnectionId* parameter. Do not confuse this value with the connection ID (CID).

### `CID`

The iSCSI connection ID (CID) for this connection instance. The iSCSI protocol uses this value to identify the connection.

### `State`

The type of connection state. This member can have the following symbolic constant values, which are defined in *Iscsimgt.h*.

| State | Meaning |
| --- | --- |
| login | The TCP connection has been established, but the target still has not sent a valid logon response with the final bit set. |
| full | The target has sent a valid logon response with the final bit set, and the connection is in the full feature phase. The initiator can send SCSI commands and data to targets. |
| logout | The initiator has sent a valid logoff command, but the connection has not yet been closed. |

### `Protocol`

The transport protocol that is used to establish this connection instance. For a list of values that you can assign to this member, see [ISCSI_CONNECTION_PROTOCOL_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-connection-protocol-type-qualifiers).

### `HeaderIntegrity`

The name of the iSCSI header digest scheme that is associated with this connection session. This member can have the following symbolic constant values, which are defined in *Iscsimgt.h*.

| HeaderIntegrity | Meaning |
| --- | --- |
| None | The session is not using a header digest. |
| crc32c | The session is using a 32-bit CRC digest. |

### `DataIntegrity`

The name of the iSCSI data digest scheme that is associated with this connection session. This member can have the following symbolic constant values, which are defined in *Iscsimgt.h*.

| HeaderIntegrity | Meaning |
| --- | --- |
| None | The session is not using a data digest. |
| crc32c | The session is using a 32-bit CRC digest. |

### `Reserved`

Reserved for Microsoft use only. You must set this member to 0.

### `MaxRecvDataSegmentLength`

The maximum data payload size, in bytes, that is supported for command or data PDUs within this connection session.

### `AuthType`

The type of authentication that is used to establish a connection. The [ISCSI_ConnectionStaticInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-connectionstaticinfo-wmi-class), which is defined in *Mgmt.mof*, does specify values for this member; but if your software includes *Iscsidsc.h*, it can use the [ISCSI_AUTH_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ne-iscsidef-iscsi_auth_types) enumeration to assign values to this member.

### `LocalAddr`

A [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure that holds the IP address of the local network card that the initiator uses to connect to the network.

### `LocalPort`

The local port number that this connection instance uses.

### `RemoteAddr`

A [ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address) structure that holds the IP address of the remote network card that this connection instance uses.

### `RemotePort`

The remote port number that the initiator used to make the connection.

### `EstimatedThroughput`

The estimated throughput, in bytes per second, of the connection.

### `MaxDatagramSize`

The maximum size, in bytes, of the datagram that the transport supports.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[ISCSI_AUTH_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ne-iscsidef-iscsi_auth_types)

[ISCSI_CONNECTION_PROTOCOL_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-connection-protocol-type-qualifiers)

[ISCSI_ConnectionStaticInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-connectionstaticinfo-wmi-class)

[ISCSI_IP_Address](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_ip_address)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)