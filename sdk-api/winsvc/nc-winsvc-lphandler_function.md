# LPHANDLER_FUNCTION callback function

## Description

An application-defined callback function used with the
[RegisterServiceCtrlHandler](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlera) function. A service program can use it as the control handler function of a particular service.

The **LPHANDLER_FUNCTION** type defines a pointer to this function.
**Handler** is a placeholder for the application-defined name.

This function has been superseded by the
[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex) control handler function used with the
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa) function. A service can use either control handler, but the new control handler supports user-defined context data and additional extended control codes.

## Parameters

### `dwControl`

#### - fdwControl [in]

The control code. This parameter can be one of the following values.

| Control code | Meaning |
| --- | --- |
| **SERVICE_CONTROL_CONTINUE**<br><br>0x00000003 | Notifies a paused service that it should resume. |
| **SERVICE_CONTROL_INTERROGATE**<br><br>0x00000004 | Notifies a service that it should report its current status information to the service control manager.<br><br>The handler should simply return **NO_ERROR**; the SCM is aware of the current state of the service. |
| **SERVICE_CONTROL_NETBINDADD**<br><br>0x00000007 | Notifies a network service that there is a new component for binding. The service should bind to the new component. <br><br>Applications should use Plug and Play functionality instead. |
| **SERVICE_CONTROL_NETBINDDISABLE**<br><br>0x0000000A | Notifies a network service that one of its bindings has been disabled. The service should reread its binding information and remove the binding. <br><br>Applications should use Plug and Play functionality instead. |
| **SERVICE_CONTROL_NETBINDENABLE**<br><br>0x00000009 | Notifies a network service that a disabled binding has been enabled. The service should reread its binding information and add the new binding. <br><br>Applications should use Plug and Play functionality instead. |
| **SERVICE_CONTROL_NETBINDREMOVE**<br><br>0x00000008 | Notifies a network service that a component for binding has been removed. The service should reread its binding information and unbind from the removed component. <br><br>Applications should use Plug and Play functionality instead. |
| **SERVICE_CONTROL_PARAMCHANGE**<br><br>0x00000006 | Notifies a service that its startup parameters have changed. The service should reread its startup parameters. |
| **SERVICE_CONTROL_PAUSE**<br><br>0x00000002 | Notifies a service that it should pause. |
| **SERVICE_CONTROL_SHUTDOWN**<br><br>0x00000005 | Notifies a service that the system is shutting down so the service can perform cleanup tasks. <br><br>If a service accepts this control code, it must stop after it performs its cleanup tasks and return **NO_ERROR**. After the SCM sends this control code, it will not send other control codes to the service.<br><br>For more information, see Remarks. |
| **SERVICE_CONTROL_STOP**<br><br>0x00000001 | Notifies a service that it should stop.<br><br>If a service accepts this control code, it must stop upon receipt and return **NO_ERROR**. After the SCM sends this control code, it does not send other control codes.**Windows XP:** If the service returns **NO_ERROR** and continues to run, it continues to receive control codes. This behavior changed starting with Windows Server 2003 and Windows XP with SP2. |

This parameter can also be a user-defined control code, as described in the following table.

| Control code | Meaning |
| --- | --- |
| Range 128 to 255. | The service defines the action associated with the control code. |

## Remarks

When a service is started, its
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function should immediately call the
[RegisterServiceCtrlHandler](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlera) function to specify a
**Handler** function to process control requests.

The control dispatcher in the main thread of a service process invokes the control handler function for the specified service whenever it receives a control request from the service control manager. After processing the control request, the control handler must call the
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) function if the service state changes to report its new status to the service control manager.

The control handler function is intended to receive notification and return immediately. The callback function should save its parameters and create other threads to perform additional work. (Your application must ensure that such threads have exited before stopping the service.) In particular, a control handler should avoid operations that might block, such as taking a lock, because this could result in a deadlock or cause the system to stop responding.

When the service control manager sends a control code to a service, it waits for the handler function to return before sending additional control codes to other services. The control handler should return as quickly as possible; if it does not return within 30 seconds, the SCM returns an error. If a service must do lengthy processing when the service is executing the control handler, it should create a secondary thread to perform the lengthy processing, and then return from the control handler. This prevents the service from tying up the control dispatcher and blocking other services from receiving control codes.

The **SERVICE_CONTROL_SHUTDOWN** control code should only be processed by services that must absolutely clean up during shutdown, because there is a limited time (about 20 seconds) available for service shutdown. After this time expires, system shutdown proceeds regardless of whether service shutdown is complete. Note that if the system is left in the shutdown state (not restarted or powered down), the service continues to run. If your service registers to accept **SERVICE_CONTROL_SHUTDOWN**, it must handle the control code and stop in a timely fashion. Otherwise, the service can increase the time required to shut down the system, because the system must wait for the full amount of time allowed for service shutdown before system shutdown can proceed.

If the service requires more time to clean up, it should send **STOP_PENDING** status messages, along with a wait hint, so the service controller knows how long to wait before reporting to the system that service shutdown is complete. However, to prevent a service from stopping shutdown, there is a limit to how long the service controller will wait. If the service is being shut down through the Services snap-in, the limit is 125 seconds. If the operating system is rebooting, the time limit is specified in the **WaitToKillServiceTimeout** value of the following registry key:

**HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control**

Services can also use the [SetConsoleCtrlHandler](https://learn.microsoft.com/windows/console/setconsolectrlhandler) function to receive shutdown notification. This notification is received when the running applications are shutting down, which occurs before services are shut down.

#### Examples

For an example, see
[Writing a Control Handler Function](https://learn.microsoft.com/windows/desktop/Services/writing-a-control-handler-function).

## See also

[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex)

[RegisterServiceCtrlHandler](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlera)

[Service Control Handler Function](https://learn.microsoft.com/windows/desktop/Services/service-control-handler-function)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona)

[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus)