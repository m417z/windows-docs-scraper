# _ISCSI_TargetMapping structure

## Description

The ISCSI_TargetMapping structure maps a collection of logical unit numbers (LUNs) that are locally defined to a group of 64-bit iSCSI logical unit numbers.

## Members

### `OSBus`

The SCSI bus number (which is valid in the local operating system) that the remote target is mapped to. A value of 0xffffffff indicates that the miniport driver can associate any SCSI bus number with the target.

### `OSTarget`

The SCSI target number (which is valid in the local operating system) that the remote target is mapped to. A value of 0xffffffff indicates that the miniport driver can pick any number to identify the remote target device.

### `UniqueSessionId`

A 64-bit integer that uniquely identifies the session. The [LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget) and [AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession) methods both return this value in their UniqueSessionId parameter. Do not confuse this value with the values in the ISID and TSID members.

### `LUNCount`

The number of LUNs that are associated with the remote target device.

### `TargetName`

A wide character string that indicates the target name.

### `FromPersistentLogin`

A Boolean value that indicates whether the logon session is persistent. If this member is **TRUE**, the logon session is persistent and the system creates it automatically when the computer boots up. If this member is **FALSE**, the logon session is not persistent.

### `Reserved`

Reserved for Microsoft use only.

### `LUNList`

A [ISCSI_LUNList](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_lunlist) structure that holds a list of LUNs that are associated with the target device.

## Remarks

A 64-bit iSCSI LUN by itself does not uniquely identify the logical unit that it represents. However, the combination of an iSCSI LUN and the name of the target that the logical unit belongs to does provide a unique identification for that logical unit that is valid anywhere in the network.

Management applications can use the ISCSI_TargetMapping structure to specify a local LUN number that can be assigned to the target LUN that the operating system finds during device enumerations.

## See also

[AddConnectionToSession](https://learn.microsoft.com/windows-hardware/drivers/storage/addconnectiontosession)

[ISCSI_LUNList](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_lunlist)

[ISCSI_TargetMapping WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-targetmapping-wmi-class)

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)