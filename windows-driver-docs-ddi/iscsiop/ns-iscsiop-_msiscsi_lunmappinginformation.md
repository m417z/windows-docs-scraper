# _MSiSCSI_LUNMappingInformation structure

## Description

This MSiSCSI_LUNMappingInformation structure provides the SCSI address information that the operating system assigns to a particular logical unit.

## Members

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this identifier (ID). The initiator reports this value in the **UniqueAdapterId** member of the [MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation) structure.

### `UniqueSessionId`

A session ID that uniquely identifies the session for which the LUN mapping is valid. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in the *UniqueSessionId* parameter. Do not confuse this value with the values in the ISID and TSID members.

### `OSBus`

The number that the operating system assigns to the bus that the adapter is attached to.

### `OSTarget`

The device number that the operating system assigns to the target.

### `OSLUN`

The logical unit number (LUN) that the operating system assigns to the logical unit.

## Remarks

You must implement this class.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)

[MSiSCSI_HBAInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsimgt/ns-iscsimgt-_msiscsi_hbainformation)

[MSiSCSI_LUNMappingInformation WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-lunmappinginformation-wmi-class)

[MSiSCSI_TargetMappings](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_msiscsi_targetmappings)