## Description

The **RS_ONE_COMMAND_PARAMETER_DATA** structure contains information about the command data block (CDB) and a usage map for bits in the CDB.

## Members

### `ReadWriteCommandDurationLimitsPage`

Indicates the mode page, if any, that specifies the duration limit for the command.

### `Reserved`

Reserved for internal use.

### `Support`

The *Support* field values are described in the following table:

| Value | Description |
|--|--|
| 0 | Data about the requested SCSI command is not currently available. No data after byte one is valid. A subsequent request for command support data may be successful. |
| 1 | The device server does not support the requested command. Data after byte one is undefined. |
| 2 | Reserved |
| 3 | The device server supports the requested command in conformance with a SCSI standard. |
| 4 | Reserved |
| 5 | The device server supports the requested command in a vendor specific manner. |
| 6-7 | Reserved |

### `CommandDurationLimitPage`

Specified the command duration limit page mode. For more information see **[RS_COMMAND_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-rs_command_descriptor)**.

### `MultipleLogicalUnits`

The *MultipleLogicalUnits* field values are described in the following table:

| Value | Description |
|--|--|
| 0 | The effect of this command on other logical units is not reported. |
| 1 | This command affects only this logical unit. |
| 2 | This command affects more than one, but not all, logical units contained in this SCSI target device. |
| 3 | This command affects all of the logical units contained in this SCSI target device. |

### `CommandTimeoutsDescriptorPresent`

Indicates that the command timeouts descriptor is included in the command descriptor.

### `CdbSize[2]`

The size of the command data block (CDB).

### `CdbUsageData[ANYSIZE_ARRAY]`

A bit field containing information about the command data block (CDB). The first byte contains the operation code. If the command contains a service action, that code is in the *CdbUsageData* field in the same location as the *ServiceAction* field of the command CDB. All other bytes of the *CdbUsageData* field contain a usage map for bits in the command data block.

## Remarks

## See also

- **[RS_COMMAND_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-rs_command_descriptor)**