# _MSiSCSI_RequestTimeStatistics structure

## Description

The MSiSCSI_RequestTimeStatistics structure is used by iSCSI initiators to report request time statistics.

## Members

### `iSCSIName`

The iSCSI target name.

### `CID`

The iSCSI connection identifier (ID) for this connection instance. This ID is an internal value that the iSCSI protocol uses to identify the connection. Do not use this ID. Application software should use the connection identifier that the [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods return in the UniqueConnectionId parameter.

### `USID`

The iSCSI session ID for this connection instance. This ID is an internal value that the iSCSI protocol uses to identify the session. Do not use this ID. Application software should use the session identifier that the [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods return in the UniqueSessionId parameter.

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this identifier (ID). The initiator reports this value in the UniqueAdapterId member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) structure.

### `MaximumProcessingTime`

The maximum time taken to process a request over this connection.

### `AverageProcessingTime`

The average time taken to process a request over this connection.

## Remarks

It is optional that you implement this class.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation)