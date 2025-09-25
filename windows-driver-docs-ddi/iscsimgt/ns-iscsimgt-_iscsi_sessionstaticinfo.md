# _ISCSI_SessionStaticInfo structure

## Description

The ISCSI_SessionStaticInfo structure provides information about the characteristics of an iSCSI session.

## Members

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in their UniqueSessionId parameter. Do not confuse this value with the values in the **ISID** and **TSID** members.

### `InitiatoriSCSIName`

A wide character string that specifies the initiator node name.

### `TargetiSCSIName`

A wide character string that specifies the node name of the target.

### `TSID`

An internal value that specifies the portion of the iSCSI session ID that the target provides. The iSCSI protocol uses TSID together with ISID to identify the session. Do not confuse TSID with the session ID that **UniqueSessionId** specifies.

### `ISID`

An internal value that specifies the portion of the iSCSI session ID that the initiator provides.

### `InitialR2t`

A Boolean value that indicates if the initiator must wait for a ready-to-send (R2T) request before sending data to the target. If this member is **TRUE**, the initiator must wait for a ready-to-send (R2T) request before sending data to the target. If this member is **FALSE**, the initiator can send unsolicited data within limits that the value of **FirstBurstLength** specifies.

### `ImmediateData`

A Boolean value that indicates if the initiator and target have agreed to allow the transmission of immediate data in the session. (*Immediate data* is data that the initiator piggybacks onto an iSCSI command PDU.) If this member is **TRUE**, the initiator and target have agreed to allow the transmission of immediate data in this session.

### `Type`

An [ISCSI_SESSION_TYPE_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-session-type-qualifiers) enumeration value that specifies the type of logon session.

| Type | Meaning |
| --- | --- |
| discoverySession | Session is being used only for discovery. |
| informationtalSession | Session is being used for a limited set of SCSI commands. |
| dataSession | Session is being used as a full feature session. |
| bootSession | Session is being used to boot from target. |

### `DataSequenceInOrder`

A Boolean value that indicates whether sequences of data PDUs must be transmitted by using continuously increasing offsets, except during error recovery. If this member is **TRUE**, sequences of data PDUs must be transmitted by using continuously increasing offsets, except during error recovery. If this member is **FALSE**, sequences of data PDUs can be transmitted in any order.

The value in **DataSequenceInOrder** indicates the ordering of the sequences themselves, not the ordering of the data PDUs within each sequence. The **DataPduInOrder** member indicates the ordering of the data PDUs within each sequence.

### `DataPduInOrder`

A Boolean value that indicates whether the data PDUs within a sequence of data PDUs must be located at continuously increasing addresses. If this member is **TRUE**, the data PDUs within a sequence of data PDUs must be located at continuously increasing addresses, with no gaps or overlay between PDUs. If this member is **FALSE**, the data PDUs within each sequence can be in any order.

### `ErrorRecoveryLevel`

The level of error recovery that the initiator and the target negotiated. Higher numbers represent more elaborate recovery schemes. Currently, this member must be 0 or ULONG_VALUE_UNKNOWN.

### `MaxOutstandingR2t`

The maximum number of outstanding ready-to-transmit (R2T) requests that are allowed for each task within this session.

### `FirstBurstLength`

The maximum amount of unsolicited data, in bytes, that you can send within this session.

### `MaxBurstLength`

The maximum number of bytes that you can send within a single sequence of Data-In or Data-Out PDUs.

### `MaxConnections`

The maximum number of connections that are allowed within this session.

### `ConnectionCount`

The number of connections that currently belong to this session.

### `ConnectionsList`

A variable length array of [ISCSI_ConnectionStaticInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_connectionstaticinfo) structures that specifies the static configuration data for each connection that is associated with this session. **ConnectionCount** indicates the number of elements in the array.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[ISCSI_ConnectionStaticInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_iscsi_connectionstaticinfo)

[LOGINSESSIONTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ne-iscsiop-loginsessiontype)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)