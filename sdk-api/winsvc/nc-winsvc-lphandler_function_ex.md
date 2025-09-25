# LPHANDLER_FUNCTION_EX callback function

## Description

An application-defined callback function used with the
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa) function. A
service program can use it as the control handler function of a particular service.

The **LPHANDLER_FUNCTION_EX** type defines a pointer to this function.
**HandlerEx** is a placeholder for the application-defined
name.

This function supersedes the [Handler](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function) control handler
function used with the
[RegisterServiceCtrlHandler](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlera) function. A
service can use either control handler, but the new control handler supports user-defined context data and
additional extended control codes.

## Parameters

### `dwControl` [in]

The control code. This parameter can be one of the following values.

| Control code | Meaning |
| --- | --- |
| **SERVICE_CONTROL_CONTINUE**<br><br>0x00000003 | Notifies a paused service that it should resume. |
| **SERVICE_CONTROL_INTERROGATE**<br><br>0x00000004 | Notifies a service to report its current status information to the service control manager.<br><br>The handler should simply return **NO_ERROR**; the SCM is aware of the current state of the service. |
| **SERVICE_CONTROL_NETBINDADD**<br><br>0x00000007 | Notifies a network service that there is a new component for binding. The service should bind to the new component.<br><br>Applications should use Plug and Play functionality instead. |
| **SERVICE_CONTROL_NETBINDDISABLE**<br><br>0x0000000A | Notifies a network service that one of its bindings has been disabled. The service should reread its binding information and remove the binding.<br><br>Applications should use Plug and Play functionality instead. |
| **SERVICE_CONTROL_NETBINDENABLE**<br><br>0x00000009 | Notifies a network service that a disabled binding has been enabled. The service should reread its binding information and add the new binding.<br><br>Applications should use Plug and Play functionality instead. |
| **SERVICE_CONTROL_NETBINDREMOVE**<br><br>0x00000008 | Notifies a network service that a component for binding has been removed. The service should reread its binding information and unbind from the removed component.<br><br>Applications should use Plug and Play functionality instead. |
| **SERVICE_CONTROL_PARAMCHANGE**<br><br>0x00000006 | Notifies a service that service-specific startup parameters have changed. The service should reread its startup parameters. |
| **SERVICE_CONTROL_PAUSE**<br><br>0x00000002 | Notifies a service that it should pause. |
| **SERVICE_CONTROL_PRESHUTDOWN**<br><br>0x0000000F | Notifies a service that the system will be shutting down. Services that need additional time to perform cleanup tasks beyond the tight time restriction at system shutdown can use this notification. The service control manager sends this notification to applications that have registered for it before sending a **SERVICE_CONTROL_SHUTDOWN** notification to applications that have registered for that notification.<br><br>A service that handles this notification blocks system shutdown until the service stops or the preshutdown time-out interval specified through [SERVICE_PRESHUTDOWN_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_preshutdown_info) expires. Because this affects the user experience, services should use this feature only if it is absolutely necessary to avoid data loss or significant recovery time at the next system start.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **SERVICE_CONTROL_SHUTDOWN**<br><br>0x00000005 | Notifies a service that the system is shutting down so the service can perform cleanup tasks. Note that services that register for **SERVICE_CONTROL_PRESHUTDOWN** notifications cannot receive this notification because they have already stopped.<br><br>If a service accepts this control code, it must stop after it performs its cleanup tasks and return **NO_ERROR**. After the SCM sends this control code, it will not send other control codes to the service.<br><br>For more information, see the Remarks section of this topic. |
| **SERVICE_CONTROL_STOP**<br><br>0x00000001 | Notifies a service that it should stop.<br><br>If a service accepts this control code, it must stop upon receipt and return **NO_ERROR**. After the SCM sends this control code, it will not send other control codes to the service. **Windows XP:** If the service returns **NO_ERROR** and continues to run, it continues to receive control codes. This behavior changed starting with Windows Server 2003 and Windows XP with SP2. |

This parameter can also be one of the following extended control codes. Note that these control codes are not
supported by the [Handler](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function) function.

| Control Code | Meaning |
| --- | --- |
| **SERVICE_CONTROL_DEVICEEVENT**<br><br>0x0000000B | Notifies a service of device events. (The service must have registered to receive these notifications using the [RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa) function.) The *dwEventType* and *lpEventData* parameters contain additional information. |
| **SERVICE_CONTROL_HARDWAREPROFILECHANGE**<br><br>0x0000000C | Notifies a service that the computer's hardware profile has changed. The *dwEventType* parameter contains additional information. |
| **SERVICE_CONTROL_POWEREVENT**<br><br>0x0000000D | Notifies a service of system power events. The *dwEventType* parameter contains additional information. If *dwEventType* is [PBT_POWERSETTINGCHANGE](https://learn.microsoft.com/windows/desktop/Power/pbt-powersettingchange), the *lpEventData* parameter also contains additional information. |
| **SERVICE_CONTROL_SESSIONCHANGE**<br><br>0x0000000E | Notifies a service of session change events. Note that a service will only be notified of a user logon if it is fully loaded before the logon attempt is made. The *dwEventType* and *lpEventData* parameters contain additional information. |
| **SERVICE_CONTROL_TIMECHANGE**<br><br>0x00000010 | Notifies a service that the system time has changed. The *lpEventData* parameter contains additional information. The *dwEventType* parameter is not used.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This control code is not supported. |
| **SERVICE_CONTROL_TRIGGEREVENT**<br><br>0x00000020 | Notifies a service registered for a [service trigger event](https://learn.microsoft.com/windows/desktop/Services/service-trigger-events) that the event has occurred. <br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This control code is not supported. |
| **SERVICE_CONTROL_USERMODEREBOOT**<br><br>0x00000040 | Notifies a service that the user has initiated a reboot.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This control code is not supported. |

This parameter can also be a user-defined control code, as described in the following table.

| Control code | Meaning |
| --- | --- |
| Range 128 to 255. | The service defines the action associated with the control code. |

### `dwEventType` [in]

The type of event that has occurred. This parameter is used if *dwControl* is
**SERVICE_CONTROL_DEVICEEVENT**, **SERVICE_CONTROL_HARDWAREPROFILECHANGE**, **SERVICE_CONTROL_POWEREVENT**, or
**SERVICE_CONTROL_SESSIONCHANGE**. Otherwise, it is zero.

If *dwControl* is **SERVICE_CONTROL_DEVICEEVENT**, this parameter can be one of the
following values:

* [DBT_DEVICEARRIVAL](https://learn.microsoft.com/windows/desktop/DevIO/dbt-devicearrival)
* [DBT_DEVICEREMOVECOMPLETE](https://learn.microsoft.com/windows/desktop/DevIO/dbt-deviceremovecomplete)
* [DBT_DEVICEQUERYREMOVE](https://learn.microsoft.com/windows/desktop/DevIO/dbt-devicequeryremove)
* [DBT_DEVICEQUERYREMOVEFAILED](https://learn.microsoft.com/windows/desktop/DevIO/dbt-devicequeryremovefailed)
* [DBT_DEVICEREMOVEPENDING](https://learn.microsoft.com/windows/desktop/DevIO/dbt-deviceremovepending)
* [DBT_CUSTOMEVENT](https://learn.microsoft.com/windows/desktop/DevIO/dbt-customevent)

If *dwControl* is **SERVICE_CONTROL_HARDWAREPROFILECHANGE**, this parameter can be
one of the following values:

* [DBT_CONFIGCHANGED](https://learn.microsoft.com/windows/desktop/DevIO/dbt-configchanged)
* [DBT_QUERYCHANGECONFIG](https://learn.microsoft.com/windows/desktop/DevIO/dbt-querychangeconfig)
* [DBT_CONFIGCHANGECANCELED](https://learn.microsoft.com/windows/desktop/DevIO/dbt-configchangecanceled)

If *dwControl* is **SERVICE_CONTROL_POWEREVENT**, this parameter can be one of the values specified in the *wParam* parameter of the [WM_POWERBROADCAST](https://learn.microsoft.com/windows/desktop/Power/wm-powerbroadcast) message.

If *dwControl* is **SERVICE_CONTROL_SESSIONCHANGE**, this parameter can be one of the
values specified in the *wParam* parameter of the
[WM_WTSSESSION_CHANGE](https://learn.microsoft.com/windows/desktop/TermServ/wm-wtssession-change) message.

### `lpEventData` [in]

Additional device information, if required. The format of this data depends on the value of the
*dwControl* and *dwEventType* parameters.

If
*dwControl* is **SERVICE_CONTROL_DEVICEEVENT**, this data corresponds to the
*lParam* parameter that applications receive as part of a
[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange) message.

If
*dwControl* is **SERVICE_CONTROL_POWEREVENT** and *dwEventType* is PBT_POWERSETTINGCHANGE, this data is a pointer to a
[POWERBROADCAST_SETTING](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-powerbroadcast_setting) structure.

If
*dwControl* is **SERVICE_CONTROL_SESSIONCHANGE**, this parameter is a pointer to a
[WTSSESSION_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wtssession_notification)
structure.

If *dwControl* is **SERVICE_CONTROL_TIMECHANGE**, this data is a pointer to a [SERVICE_TIMECHANGE_INFO](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_timechange_info) structure.

### `lpContext` [in]

User-defined data passed from
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa).
When multiple services share a process, the *lpContext* parameter can help identify the
service.

## Return value

The return value for this function depends on the control code received.

The following list identifies the rules for this return value:

* In general, if your service does not handle the control, return **ERROR_CALL_NOT_IMPLEMENTED**. However, your service should return **NO_ERROR** for **SERVICE_CONTROL_INTERROGATE** even if your service does not handle it.
* If your service handles **SERVICE_CONTROL_STOP** or **SERVICE_CONTROL_SHUTDOWN**, return **NO_ERROR**.
* If your service handles **SERVICE_CONTROL_DEVICEEVENT**, return **NO_ERROR** to grant the request and an error
  code to deny the request.
* If your service handles **SERVICE_CONTROL_HARDWAREPROFILECHANGE**, return **NO_ERROR** to grant the request and
  an error code to deny the request.
* If your service handles **SERVICE_CONTROL_POWEREVENT**, return **NO_ERROR** to grant the request and an error
  code to deny the request.
* For all other control codes your service handles, return **NO_ERROR**.

## Remarks

When a service is started, its [ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function
should immediately call the
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa)
function to specify a **HandlerEx** function to process control
requests. To specify the control codes to be accepted, use the
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) and
[RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa) functions.

The control dispatcher in the main thread of a service invokes the control handler function for the specified
service whenever it receives a control request from the service control manager. After processing the control
request, the control handler must call
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) if the service state changes to
report its new status to the service control manager.

The control handler function is intended to receive notification and return immediately. The
callback function should save its parameters and create other threads to perform additional work. (Your application
must ensure that such threads have exited before stopping the service.) In particular, a control handler should avoid operations that might block, such as taking a lock, because this could result in a deadlock or cause the system to stop responding.

When the service control manager sends a control code to a service, it waits for the handler function to
return before sending additional control codes to other services. The control handler should return as quickly as possible; if it does not return within 30
seconds, the SCM returns an error. If a service must do lengthy processing when the service is executing the
control handler, it should create a secondary thread to perform the lengthy processing, and then return from the
control handler. This prevents the service from tying up the control dispatcher and blocking other services from
receiving control codes.

The **SERVICE_CONTROL_SHUTDOWN** control code should only be processed by services that must absolutely clean up
during shutdown, because there is a limited time (about 20 seconds) available for service shutdown. After this
time expires, system shutdown proceeds regardless of whether service shutdown is complete. Note that if the system
is left in the shutdown state (not restarted or powered down), the service continues to run. If your service registers to accept **SERVICE_CONTROL_SHUTDOWN**, it must handle the control code and return **NO_ERROR**. Returning an error for this control code and not stopping in a timely fashion can increase the time required to shut down the system, because the system must wait for the full amount of time allowed for service shutdown before system shutdown can proceed.

If the service requires more time to clean up, it should send **STOP_PENDING** status messages, along with a wait
hint, so the service controller knows how long to wait before reporting to the system that service shutdown is
complete. However, to prevent a service from stopping shutdown, there is a limit to how long the service
controller waits. If the service is being shut down through the Services snap-in, the limit is 125 seconds. If the operating system is rebooting, the time limit is specified in the **WaitToKillServiceTimeout** value of the following registry key:

**HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control**

Be sure to handle Plug and Play device events as quickly as possible; otherwise, the system may become
unresponsive. If your event handler is to perform an operation that may block execution (such as I/O), it is best
to start another thread to perform the operation asynchronously.

Services can also use the
[SetConsoleCtrlHandler](https://learn.microsoft.com/windows/console/setconsolectrlhandler) function to receive
shutdown notification. This notification is received when the running applications are shutting down, which occurs
before services are shut down.

## See also

[POWERBROADCAST_SETTING](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-powerbroadcast_setting)

[RegisterDeviceNotification](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerdevicenotificationa)

[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa)

[Service Control Handler Function](https://learn.microsoft.com/windows/desktop/Services/service-control-handler-function)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona)

[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus)

[WM_DEVICECHANGE](https://learn.microsoft.com/windows/desktop/DevIO/wm-devicechange)

[WM_POWERBROADCAST](https://learn.microsoft.com/windows/desktop/Power/wm-powerbroadcast)

[WM_WTSSESSION_CHANGE](https://learn.microsoft.com/windows/desktop/TermServ/wm-wtssession-change)

[WTSSESSION_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-wtssession_notification)