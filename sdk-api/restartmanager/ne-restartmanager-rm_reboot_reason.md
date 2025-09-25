# RM_REBOOT_REASON enumeration

## Description

Describes the reasons a restart of the system is needed.

## Constants

### `RmRebootReasonNone:0x0`

A system restart is not required.

### `RmRebootReasonPermissionDenied:0x1`

The current user does not have
sufficient privileges to shut down one or more processes.

### `RmRebootReasonSessionMismatch:0x2`

One or more processes are
running in another Terminal Services session.

### `RmRebootReasonCriticalProcess:0x4`

A system restart is needed because one or more processes to be shut down are critical processes.

### `RmRebootReasonCriticalService:0x8`

A system restart is needed because one or more services to be shut down are critical services.

### `RmRebootReasonDetectedSelf`

A system restart is needed because the current process must be shut down.

## See also

[RmGetList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetlist)