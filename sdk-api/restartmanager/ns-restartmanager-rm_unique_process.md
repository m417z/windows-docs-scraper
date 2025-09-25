# RM_UNIQUE_PROCESS structure

## Description

Uniquely identifies a process by its PID and the time the process began. An array of **RM_UNIQUE_PROCESS** structures can be passed to the [RmRegisterResources](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmregisterresources) function.

## Members

### `dwProcessId`

The product identifier (PID).

### `ProcessStartTime`

The creation time of the process. The time is provided as a **FILETIME** structure that is returned by the *lpCreationTime* parameter of the [GetProcessTimes](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocesstimes) function.

## Remarks

The **RM_UNIQUE_PROCESS** structure can be used to uniquely identify an application in an [RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info) structure or registered with the Restart Manager session by the [RmRegisterResources](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmregisterresources) function.