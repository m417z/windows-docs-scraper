# _MSiSCSI_ConnectionStatistics structure

## Description

The **MSiSCSI_ConnectionStatistics** structure is used by iSCSI initiators to report statistics for a connection within a session.

## Members

### `iSCSIName`

A wide character string that contains the name of the iSCSI target.

### `CID`

The iSCSI connection identifier (ID) for this connection instance. This ID is an internal value that the iSCSI protocol uses to identify the connection. Do not use this ID. Application software should use the connection identifier that the [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods return in the *UniqueConnectionId* parameter.

### `USID`

The iSCSI session ID for this connection instance. This ID is an internal value that the iSCSI protocol uses to identify the session. Application software should use the session identifier that the [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods return in the *UniqueSessionId* parameter.

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this ID. The initiator reports this value in the **UniqueAdapterId** member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) structure.

### `BytesSent`

The number of bytes that are sent over this connection.

### `BytesReceived`

The number of bytes that are received over this connection.

### `PDUCommandsSent`

The number of PDUs that are sent over this connection.

### `PDUResponsesReceived`

The number of PDUs that are received over this connection.

## Remarks

Initiators must register the [MSiSCSI_ConnectionStatistics WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-connectionstatistics-wmi-class) with the following dynamic instance name for the connection:

```
targetname_#:#
```

The first number sign (#) is the value in the **USID** member of **MSiSCSI_ConnectionStatistics**, and the second number sign (#) is the value in the **CID** member. It is optional that you implement this class.

The totals tracked by this structure are valid for the lifetime of the connection in the session. Totals for all connections in a session are obtained in [MSiSCSI_SessionStatistics](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiprf/ns-iscsiprf-_msiscsi_sessionstatistics) structure.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[MSiSCSI_ConnectionStatistics WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-connectionstatistics-wmi-class)

[MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation)