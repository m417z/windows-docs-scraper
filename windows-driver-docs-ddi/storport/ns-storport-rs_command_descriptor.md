## Description

The **RS_COMMAND_DESCRIPTOR** structure contains information about a single supported command descriptor block (CDB).

## Members

### `OperationCode`

Specifies the command being requested by the command descriptor block (CDB).

### `Reserved`

Reserved for internal use.

### `ServiceAction[2]`

Provides qualification for the *OperationCode* field for some commands, allowing:

- Unrelated commands that share the same operation code, such as the Report Supported Operation Codes and the Report Target Port Groups commands.
- A set of related functions that share the same operation code, for example, the Persistent Reserve In command.

### `Reserved1`

Reserved for internal use.

### `ServiceActionValid`

Indicates that the contents of the *OperationCode* and *ServiceAction* fields are valid.

### `CommandTimeoutsDescriptorPresent`

Indicates that the command timeouts descriptor is included in this command descriptor.

### `CommandDurationLimitPage`

The *ReadWriteCommandDurationLimitsPage* and the *CommandDurationLimitPage* fields together indicate the mode page that specifies the command duration limit for the command.

### `MultipleLogicalUnits`

The *MultipleLogicalUnits* field is described in the following table.

| Value | Description |
|--|--|
| 0 | The effect of this command on other logical units is not reported. |
| 1 | This command only affects this logical unit. |
| 2 | This command affects more than one but not all logical units contained in this target device. |
| 3 | This command affects all of the logical units contained in this target device. |

### `ReadWriteCommandDurationLimitsPage`

The *ReadWriteCommandDurationLimitsPage* and the *CommandDurationLimitPage* fields together indicate the mode page that specifies the command duration limit for the command.

### `Reserved2`

Reserved for internal use.

### `CdbLength[2]`

Indicates the length of the command descriptor block in bytes for the *OperationCode*, and if the *ServiceActionValid* is **TRUE**, the action indicated by the *ServiceAction* field.

## Remarks

The values for the *ReadWriteCommandDurationLimitsPage* and the *CommandDurationLimitPage* fields are reflected in the following table.

| ReadWriteCommandDurationLimitsPage | CommandDurationLimitPage | Description |
|--|--|--|
| 0 | 0 | No command duration limit mode page is indicated for this command. |
| 1 | 0 | Reserved |
| 0 | 1 | Command duration limit A mode page |
| 0 | 2 | Command duration limit B mode page |
| 1 | 1 | Command duration limit T2A mode page |
| 1 | 2 | Command duration limit T2B mode page |
| 0 or 1 | 3 | Reserved |

## See also