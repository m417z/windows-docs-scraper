# TARGET_STATE enumeration

## Description

Indicates the state of a target.

## Constants

### `TARGET_UNKNOWN:0x1`

The target state is unknown.

### `TARGET_INITIALIZING`

The target is initializing.

### `TARGET_RUNNING`

The target is running.

### `TARGET_DOWN`

The target is not running. If a resource plug-in calls **OnStateChange** and the target is in this state, RD Connection Broker will delete the target object from its database.

### `TARGET_HIBERNATED`

The target is hibernated.

### `TARGET_CHECKED_OUT`

The target is checked out.

### `TARGET_STOPPED`

The target is stopped.

### `TARGET_INVALID`

### `TARGET_STARTING`

### `TARGET_STOPPING`

### `TARGET_MAXSTATE`

## See also

[Remote Desktop Virtualization API reference](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-virtualization-api-reference)

[SetTargetState](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbresourcepluginstore-settargetstate)

[TargetState](https://learn.microsoft.com/windows/desktop/api/sbtsv/nf-sbtsv-itssbtarget-get_targetstate)