# RM_APP_TYPE enumeration

## Description

Specifies the type of application that is described by the [RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info) structure.

## Constants

### `RmUnknownApp:0`

The application cannot be classified as any other type. An application of this type can only be shut down by a forced shutdown.

### `RmMainWindow:1`

A Windows application run as a stand-alone process that displays a top-level window.

### `RmOtherWindow:2`

A Windows application that does not run as a stand-alone process and does not display a top-level window.

### `RmService:3`

The application is a Windows service.

### `RmExplorer:4`

The application is Windows Explorer.

### `RmConsole:5`

The application is a stand-alone console application.

### `RmCritical:1000`

A system restart is required to complete the installation because a process cannot be shut down. The process cannot be shut down because of the following reasons. The process may be a critical process. The current user may not have permission to shut down the process. The process may belong to the primary installer that started the Restart Manager.

## See also

[RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info)