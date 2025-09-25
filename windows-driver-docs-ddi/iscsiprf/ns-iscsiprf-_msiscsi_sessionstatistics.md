# _MSiSCSI_SessionStatistics structure

## Description

The MSiSCSI_SessionStatistics structure is used by iSCSI initiators to report session statistics.

## Members

### `iSCSIName`

A wide character string that contains the name of an iSCSI target.

### `USID`

The iSCSI session identifier (ID) for this connection instance. This ID is an internal value that the iSCSI protocol uses to identify the session. Do not use this ID. Application software should use the session identifier that the [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods return in the *UniqueSessionId* parameter.

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this ID. The initiator reports this value in the *UniqueAdapterId* member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) structure.

### `BytesSent`

The number of bytes that are sent over this session.

### `BytesReceived`

The number of bytes that are received over this session.

### `PDUCommandsSent`

The number of PDUs that are sent over this session.

### `PDUResponsesReceived`

The number of PDUs that are received over this session.

### `DigestErrors`

The number of digest errors that have occurred in this session.

### `ConnectionTimeoutErrors`

The number of connection time-out errors that have occurred in this session.

### `FormatErrors`

The number of format errors that have occurred in this session.

## Remarks

It is optional that you implement this class.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation)

[MSiSCSI_SessionStatistics WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-sessionstatistics-wmi-class)