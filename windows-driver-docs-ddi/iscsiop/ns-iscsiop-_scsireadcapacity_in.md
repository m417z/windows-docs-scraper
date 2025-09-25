# _ScsiReadCapacity_IN structure (iscsiop.h)

## Description

The ScsiReadCapacity_IN structure holds the input data for the [ScsiReadCapacity](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireadcapacity6) method, which is used to send a SCSI read capacity command.

## Members

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in the *UniqueSessionId* parameter. Do not confuse this value with the values in the ISID and TSID members.

### `Lun`

A 64-bit number that, together with the name of the target, uniquely identifies the logical unit.

## Remarks

You must implement this method.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[ScsiReadCapacity](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireadcapacity6)

[ScsiReadCapacity_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsireadcapacity_out)