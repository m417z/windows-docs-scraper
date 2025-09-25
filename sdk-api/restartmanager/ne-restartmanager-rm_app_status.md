# RM_APP_STATUS enumeration

## Description

Describes the current status of an application that is acted upon by the Restart Manager.

## Constants

### `RmStatusUnknown:0x0`

The application is in a state that is not described by any other enumerated state.

### `RmStatusRunning:0x1`

The application is currently running.

### `RmStatusStopped:0x2`

The Restart Manager has stopped the application.

### `RmStatusStoppedOther:0x4`

An action outside the Restart Manager has stopped the application.

### `RmStatusRestarted:0x8`

The Restart Manager has restarted the application.

### `RmStatusErrorOnStop:0x10`

The Restart Manager encountered an error when stopping the application.

### `RmStatusErrorOnRestart:0x20`

The Restart Manager encountered an error when restarting the application.

### `RmStatusShutdownMasked:0x40`

Shutdown is masked by a filter.

### `RmStatusRestartMasked:0x80`

Restart is masked by a filter.

## Remarks

The constants of **RM_APP_STATUS** can be combined with OR operators. The combination describes the history of actions taken by Restart Manager on the application.

## See also

[RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info)