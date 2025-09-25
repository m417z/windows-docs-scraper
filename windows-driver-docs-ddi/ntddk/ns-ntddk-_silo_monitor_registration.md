# _SILO_MONITOR_REGISTRATION structure

## Description

This structure specifies a server silo monitor that can receive notifications about server silo events.

## Members

### `Version`

Set to **SILO_MONITOR_REGISTRATION_VERSION**.

### `MonitorHost`

If **true**, a create notification will be delivered for the host context.

### `MonitorExistingSilos`

If **true**, create and terminate notifications will be delivered for any silos that currently exist at the time of registration; otherwise, only notifications for new silos will be delivered.

### `Reserved`

Reserved for system use.

### `DriverObjectName`

### `ComponentName`

### `CreateCallback`

A pointer to a callback that is invoked whenever a new server silo is created on the system. This value may be **NULL**. This gives drivers to opportunity to handle the event and set up per-silo data structures.

### `TerminateCallback`

A pointer to a callback that is invoked whenever a server silo is terminated (about to be destroyed) on the system. This value may be **NULL**. This gives drivers the opportunity to complete work within the silo and begin tearing down their per-silo data structures.

#### DriverObjectName

A pointer to the unicode name for the driver object registering for notifications.

#### ComponentName

A pointer to the unicode name for the component registering for notifications.