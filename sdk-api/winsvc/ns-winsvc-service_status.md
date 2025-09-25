# SERVICE_STATUS structure

## Description

Contains status information for a service. The
[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice),
[EnumDependentServices](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumdependentservicesa),
[EnumServicesStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumservicesstatusa), and
[QueryServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicestatus) functions use this structure. A service uses this structure in the
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) function to report its current status to the service control manager.

## Members

### `dwServiceType`

The type of service. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_FILE_SYSTEM_DRIVER**<br><br>0x00000002 | The service is a file system driver. |
| **SERVICE_KERNEL_DRIVER**<br><br>0x00000001 | The service is a device driver. |
| **SERVICE_WIN32_OWN_PROCESS**<br><br>0x00000010 | The service runs in its own process. |
| **SERVICE_WIN32_SHARE_PROCESS**<br><br>0x00000020 | The service shares a process with other services. |
| **SERVICE_USER_OWN_PROCESS**<br><br>0x00000050 | The service runs in its own process under the logged-on user account. |
| **SERVICE_USER_SHARE_PROCESS**<br><br>0x00000060 | The service shares a process with one or more other services that run under the logged-on user account. |

If the service type is either SERVICE_WIN32_OWN_PROCESS or SERVICE_WIN32_SHARE_PROCESS, and the service is running in the context of the
[LocalSystem account](https://learn.microsoft.com/windows/desktop/Services/localsystem-account), the following type may also be specified.

| Value | Meaning |
| --- | --- |
| **SERVICE_INTERACTIVE_PROCESS**<br><br>0x00000100 | The service can interact with the desktop. <br><br>For more information, see [Interactive Services](https://learn.microsoft.com/windows/desktop/Services/interactive-services). |

### `dwCurrentState`

The current state of the service. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SERVICE_CONTINUE_PENDING**<br><br>0x00000005 | The service continue is pending. |
| **SERVICE_PAUSE_PENDING**<br><br>0x00000006 | The service pause is pending. |
| **SERVICE_PAUSED**<br><br>0x00000007 | The service is paused. |
| **SERVICE_RUNNING**<br><br>0x00000004 | The service is running. |
| **SERVICE_START_PENDING**<br><br>0x00000002 | The service is starting. |
| **SERVICE_STOP_PENDING**<br><br>0x00000003 | The service is stopping. |
| **SERVICE_STOPPED**<br><br>0x00000001 | The service is not running. |

### `dwControlsAccepted`

The control codes the service accepts and processes in its handler function (see
[Handler](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function) and
[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex)). A user interface process can control a service by specifying a control command in the
[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice) or [ControlServiceEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlserviceexa) function. By default, all services accept the **SERVICE_CONTROL_INTERROGATE** value.

To accept the **SERVICE_CONTROL_DEVICEEVENT** value, the service must register to receive device events by using the [RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa) function.

The following are the control codes.

| Control code | Meaning |
| --- | --- |
| **SERVICE_ACCEPT_NETBINDCHANGE**<br><br>0x00000010 | The service is a network component that can accept changes in its binding without being stopped and restarted. <br><br>This control code allows the service to receive **SERVICE_CONTROL_NETBINDADD**, **SERVICE_CONTROL_NETBINDREMOVE**, **SERVICE_CONTROL_NETBINDENABLE**, and **SERVICE_CONTROL_NETBINDDISABLE** notifications. |
| **SERVICE_ACCEPT_PARAMCHANGE**<br><br>0x00000008 | The service can reread its startup parameters without being stopped and restarted. <br><br>This control code allows the service to receive **SERVICE_CONTROL_PARAMCHANGE** notifications. |
| **SERVICE_ACCEPT_PAUSE_CONTINUE**<br><br>0x00000002 | The service can be paused and continued. <br><br>This control code allows the service to receive **SERVICE_CONTROL_PAUSE** and **SERVICE_CONTROL_CONTINUE** notifications. |
| **SERVICE_ACCEPT_PRESHUTDOWN**<br><br>0x00000100 | The service can perform preshutdown tasks. <br><br>This control code enables the service to receive **SERVICE_CONTROL_PRESHUTDOWN** notifications. Note that [ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice) and [ControlServiceEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlserviceexa) cannot send this notification; only the system can send it.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_ACCEPT_SHUTDOWN**<br><br>0x00000004 | The service is notified when system shutdown occurs. <br><br>This control code allows the service to receive **SERVICE_CONTROL_SHUTDOWN** notifications. Note that [ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice) and [ControlServiceEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlserviceexa) cannot send this notification; only the system can send it. |
| **SERVICE_ACCEPT_STOP**<br><br>0x00000001 | The service can be stopped. <br><br>This control code allows the service to receive **SERVICE_CONTROL_STOP** notifications. |

This member can also contain the following extended control codes, which are supported only by
[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex). (Note that these control codes cannot be sent by
[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice) or [ControlServiceEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlserviceexa).)

| Control code | Meaning |
| --- | --- |
| **SERVICE_ACCEPT_HARDWAREPROFILECHANGE**<br><br>0x00000020 | The service is notified when the computer's hardware profile has changed. This enables the system to send **SERVICE_CONTROL_HARDWAREPROFILECHANGE** notifications to the service. |
| **SERVICE_ACCEPT_POWEREVENT**<br><br>0x00000040 | The service is notified when the computer's power status has changed. This enables the system to send **SERVICE_CONTROL_POWEREVENT** notifications to the service. |
| **SERVICE_ACCEPT_SESSIONCHANGE**<br><br>0x00000080 | The service is notified when the computer's session status has changed. This enables the system to send **SERVICE_CONTROL_SESSIONCHANGE** notifications to the service. |
| **SERVICE_ACCEPT_TIMECHANGE**<br><br>0x00000200 | The service is notified when the system time has changed. This enables the system to send **SERVICE_CONTROL_TIMECHANGE** notifications to the service.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This control code is not supported. |
| **SERVICE_ACCEPT_TRIGGEREVENT**<br><br>0x00000400 | The service is notified when an event for which the service has registered occurs. This enables the system to send **SERVICE_CONTROL_TRIGGEREVENT** notifications to the service.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This control code is not supported. |
| **SERVICE_ACCEPT_USERMODEREBOOT**<br><br>0x00000800 | The services is notified when the user initiates a reboot.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This control code is not supported. |

### `dwWin32ExitCode`

The error code the service uses to report an error that occurs when it is starting or stopping. To return an error code specific to the service, the service must set this value to **ERROR_SERVICE_SPECIFIC_ERROR** to indicate that the **dwServiceSpecificExitCode** member contains the error code. The service should set this value to **NO_ERROR** when it is running and on normal termination.

### `dwServiceSpecificExitCode`

A service-specific error code that the service returns when an error occurs while the service is starting or stopping. This value is ignored unless the **dwWin32ExitCode** member is set to **ERROR_SERVICE_SPECIFIC_ERROR**.

### `dwCheckPoint`

The check-point value the service increments periodically to report its progress during a lengthy start, stop, pause, or continue operation. For example, the service should increment this value as it completes each step of its initialization when it is starting up. The user interface program that invoked the operation on the service uses this value to track the progress of the service during a lengthy operation. This value is not valid and should be zero when the service does not have a start, stop, pause, or continue operation pending.

### `dwWaitHint`

The estimated time required for a pending start, stop, pause, or continue operation, in milliseconds. Before the specified amount of time has elapsed, the service should make its next call to the
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) function with either an incremented **dwCheckPoint** value or a change in **dwCurrentState**. If the amount of time specified by **dwWaitHint** passes, and **dwCheckPoint** has not been incremented or **dwCurrentState** has not changed, the service control manager or service control program can assume that an error has occurred and the service should be stopped. However, if the service shares a process with other services, the service control manager cannot terminate the service application because it would have to terminate the other services sharing the process as well.

## See also

[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice)

[ControlServiceEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlserviceexa)

[EnumDependentServices](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumdependentservicesa)

[EnumServicesStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumservicesstatusa)

[QueryServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicestatus)

[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus)