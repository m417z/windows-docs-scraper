# ControlServiceExW function

## Description

Sends a control code to a service.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function. The
[access rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights) required for this handle depend on the *dwControl* code requested.

### `dwControl` [in]

This parameter can be one of the following control codes.

| Control code | Meaning |
| --- | --- |
| **SERVICE_CONTROL_CONTINUE**<br><br>0x00000003 | Notifies a paused service that it should resume. The *hService* handle must have the SERVICE_PAUSE_CONTINUE access right. |
| **SERVICE_CONTROL_INTERROGATE**<br><br>0x00000004 | Notifies a service that it should report its current status information to the service control manager. The *hService* handle must have the SERVICE_INTERROGATE access right.<br><br>Note that this control is not generally useful as the SCM is aware of the current state of the service. |
| **SERVICE_CONTROL_NETBINDADD**<br><br>0x00000007 | Notifies a network service that there is a new component for binding. The *hService* handle must have the SERVICE_PAUSE_CONTINUE access right. However, this control code has been deprecated; use Plug and Play functionality instead. |
| **SERVICE_CONTROL_NETBINDDISABLE**<br><br>0x0000000A | Notifies a network service that one of its bindings has been disabled. The *hService* handle must have the SERVICE_PAUSE_CONTINUE access right. However, this control code has been deprecated; use Plug and Play functionality instead. |
| **SERVICE_CONTROL_NETBINDENABLE**<br><br>0x00000009 | Notifies a network service that a disabled binding has been enabled. The *hService* handle must have the SERVICE_PAUSE_CONTINUE access right. However, this control code has been deprecated; use Plug and Play functionality instead. |
| **SERVICE_CONTROL_NETBINDREMOVE**<br><br>0x00000008 | Notifies a network service that a component for binding has been removed. The *hService* handle must have the SERVICE_PAUSE_CONTINUE access right. However, this control code has been deprecated; use Plug and Play functionality instead. |
| **SERVICE_CONTROL_PARAMCHANGE**<br><br>0x00000006 | Notifies a service that its startup parameters have changed. The *hService* handle must have the SERVICE_PAUSE_CONTINUE access right. |
| **SERVICE_CONTROL_PAUSE**<br><br>0x00000002 | Notifies a service that it should pause. The *hService* handle must have the SERVICE_PAUSE_CONTINUE access right. |
| **SERVICE_CONTROL_STOP**<br><br>0x00000001 | Notifies a service that it should stop. The *hService* handle must have the SERVICE_STOP access right.<br><br>After sending the stop request to a service, you should not send other controls to the service. |

This parameter can also be a user-defined control code, as described in the following table.

| Control code | Meaning |
| --- | --- |
| Range 128 to 255 | The service defines the action associated with the control code. The *hService* handle must have the SERVICE_USER_DEFINED_CONTROL access right. |

### `dwInfoLevel` [in]

The information level for the service control parameters. This parameter must be set to SERVICE_CONTROL_STATUS_REASON_INFO (1).

### `pControlParams` [in, out]

A pointer to the service control parameters. If *dwInfoLevel* is SERVICE_CONTROL_STATUS_REASON_INFO, this member is a pointer to a [SERVICE_CONTROL_STATUS_REASON_PARAMS](https://learn.microsoft.com/windows/win32/api/winsvc/ns-winsvc-service_control_status_reason_paramsa) structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Other error codes can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the required access right. |
| **ERROR_DEPENDENT_SERVICES_RUNNING** | The service cannot be stopped because other running services are dependent on it. |
| **ERROR_INVALID_HANDLE** | The specified handle was not obtained using [CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) or [OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea), or the handle is no longer valid. |
| **ERROR_INVALID_PARAMETER** | The requested control code in the *dwControl* parameter is undefined, or *dwControl* is SERVICE_CONTROL_STOP but the **dwReason** or **pszComment** members of the [SERVICE_CONTROL_STATUS_REASON_PARAMS](https://learn.microsoft.com/windows/win32/api/winsvc/ns-winsvc-service_control_status_reason_paramsa) structure are not valid. |
| **ERROR_INVALID_SERVICE_CONTROL** | The requested control code is not valid, or it is unacceptable to the service. |
| **ERROR_SERVICE_CANNOT_ACCEPT_CTRL** | The requested control code cannot be sent to the service because the state of the service is SERVICE_STOPPED, SERVICE_START_PENDING, or SERVICE_STOP_PENDING. |
| **ERROR_SERVICE_NOT_ACTIVE** | The service has not been started. |
| **ERROR_SERVICE_REQUEST_TIMEOUT** | The process for the service was started, but it did not call [StartServiceCtrlDispatcher](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicectrldispatchera), or the thread that called **StartServiceCtrlDispatcher** may be blocked in a control handler function. |
| **ERROR_SHUTDOWN_IN_PROGRESS** | The system is shutting down. |

## Remarks

The
**ControlServiceEx** function asks the Service Control Manager (SCM) to send the requested control code to the service. The SCM sends the code if the service has specified that it will accept the code, and is in a state in which a control code can be sent to it.

The SCM processes service control notifications in a serial fashion — it waits for one service to complete processing a service control notification before sending the next one. Because of this, a call to **ControlServiceEx** blocks for 30 seconds if any service is busy handling a control code. If the busy service still has not returned from its handler function when the timeout expires, **ControlServiceEx** fails with ERROR_SERVICE_REQUEST_TIMEOUT.

To stop and start a service requires a security descriptor that allows you to do so. The default security descriptor allows the
[LocalSystem account](https://learn.microsoft.com/windows/desktop/Services/localsystem-account), and members of the Administrators and Power Users groups to stop and start services. To change the security descriptor of a service, see
[Modifying the DACL for a Service](https://learn.microsoft.com/windows/desktop/Services/modifying-the-dacl-for-a-service).

The
[QueryServiceStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicestatusex) function returns a
[SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status_process) structure whose **dwCurrentState** and **dwControlsAccepted** members indicate the current state and controls accepted by a running service. All running services accept the SERVICE_CONTROL_INTERROGATE control code by default. Drivers do not accept control codes other than SERVICE_CONTROL_STOP and SERVICE_CONTROL_INTERROGATE. Each service specifies the other control codes that it accepts when it calls the
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) function to report its status. A service should always accept these codes when it is running, no matter what it is doing.

The following table shows the action of the SCM in each of the possible service states.

| Service state | Stop | Other controls |
| --- | --- | --- |
| STOPPED | (c) | (c) |
| STOP_PENDING | (b) | (b) |
| START_PENDING | (a) | (b) |
| RUNNING | (a) | (a) |
| CONTINUE_PENDING | (a) | (a) |
| PAUSE_PENDING | (a) | (a) |
| PAUSED | (a) | (a) |

(a)

If the service accepts this control code, send the request to the service; otherwise, **ControlServiceEx** returns
zero and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_INVALID_SERVICE_CONTROL**.

(b)

The service is not in a state in which a control can be sent to it, so **ControlServiceEx** returns zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_SERVICE_CANNOT_ACCEPT_CTRL**.

(c)

The service is not active, so **ControlServiceEx** returns zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_SERVICE_NOT_ACTIVE**.

> [!NOTE]
> The winsvc.h header defines ControlServiceEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[QueryServiceStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicestatusex)

[SERVICE_CONTROL_STATUS_REASON_PARAMS](https://learn.microsoft.com/windows/win32/api/winsvc/ns-winsvc-service_control_status_reason_paramsa)

[SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status)

[Service Control Requests](https://learn.microsoft.com/windows/desktop/Services/service-control-requests)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[SetServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setserviceobjectsecurity)

[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus)