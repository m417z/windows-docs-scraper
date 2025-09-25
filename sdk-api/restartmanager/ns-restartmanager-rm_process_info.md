# RM_PROCESS_INFO structure

## Description

Describes an application that is to be registered with the Restart Manager.

## Members

### `Process`

Contains an [RM_UNIQUE_PROCESS](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_unique_process) structure that uniquely identifies the application by its PID and the time the process began.

### `strAppName`

If the process is a service, this parameter returns the long name for the service. If the process is not a service, this parameter returns the user-friendly name for the application. If the process is a critical process, and the installer is run with elevated privileges, this parameter returns the name of the executable file of the critical process. If the process is a critical process, and the installer is run as a service, this parameter returns the long name of the critical process.

### `strServiceShortName`

If the process is a service, this is the short name for the service. This member is not used if the process is not a service.

### `ApplicationType`

Contains an [RM_APP_TYPE](https://learn.microsoft.com/windows/desktop/api/restartmanager/ne-restartmanager-rm_app_type) enumeration value that specifies the type of application as **RmUnknownApp**, **RmMainWindow**, **RmOtherWindow**, **RmService**, **RmExplorer** or **RmCritical**.

### `AppStatus`

Contains a bit mask that describes the current status of the application. See the [RM_APP_STATUS](https://learn.microsoft.com/windows/desktop/api/restartmanager/ne-restartmanager-rm_app_status) enumeration.

### `TSSessionId`

Contains the Terminal Services session ID
of the process. If the terminal session of the process cannot be determined, the value of this member is set to **RM_INVALID_SESSION** (-1).
This member is not used if the process is a service or a system critical process.

### `bRestartable`

**TRUE** if the application can be restarted by the Restart Manager; otherwise, **FALSE**.
This member is always **TRUE** if the process is a service. This member is always **FALSE** if the process is a critical system process.

## See also

[RM_APP_TYPE](https://learn.microsoft.com/windows/desktop/api/restartmanager/ne-restartmanager-rm_app_type)

[RM_FILTER_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_filter_info)

[RM_UNIQUE_PROCESS](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_unique_process)

[RmGetList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetlist)

[RmRestart](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmrestart)

[RmShutdown](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmshutdown)