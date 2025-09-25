# StartServiceW function

## Description

Starts a service.

## Parameters

### `hService` [in]

A handle to the service. This handle is returned by the
[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea) or
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function, and it must have the SERVICE_START access right. For more information, see
[Service Security and Access Rights](https://learn.microsoft.com/windows/desktop/Services/service-security-and-access-rights).

### `dwNumServiceArgs` [in]

The number of strings in the *lpServiceArgVectors* array. If *lpServiceArgVectors* is NULL, this parameter can be zero.

### `lpServiceArgVectors` [in, optional]

The null-terminated strings to be passed to the [ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function for the service as arguments. If there are no arguments, this parameter can be NULL. Otherwise, the first argument (lpServiceArgVectors[0]) is the name of the service, followed by any additional arguments (lpServiceArgVectors[1] through lpServiceArgVectors[dwNumServiceArgs-1]).

Driver services do not receive these arguments.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Others can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The handle does not have the SERVICE_START access right. |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |
| **ERROR_PATH_NOT_FOUND** | The service binary file could not be found. |
| **ERROR_SERVICE_ALREADY_RUNNING** | An instance of the service is already running. |
| **ERROR_SERVICE_DATABASE_LOCKED** | The database is locked. |
| **ERROR_SERVICE_DEPENDENCY_DELETED** | The service depends on a service that does not exist or has been marked for deletion. |
| **ERROR_SERVICE_DEPENDENCY_FAIL** | The service depends on another service that has failed to start. |
| **ERROR_SERVICE_DISABLED** | The service has been disabled. |
| **ERROR_SERVICE_LOGON_FAILED** | The service did not start due to a logon failure. This error occurs if the service is configured to run under an account that does not have the "Log on as a service" right. |
| **ERROR_SERVICE_MARKED_FOR_DELETE** | The service has been marked for deletion. |
| **ERROR_SERVICE_NO_THREAD** | A thread could not be created for the service. |
| **ERROR_SERVICE_REQUEST_TIMEOUT** | The process for the service was started, but it did not call [StartServiceCtrlDispatcher](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicectrldispatchera), or the thread that called **StartServiceCtrlDispatcher** may be blocked in a control handler function. |

## Remarks

When a driver service is started, the
**StartService** function does not return until the device driver has finished initializing.

When a service is started, the Service Control Manager (SCM) spawns the service process, if necessary. If the specified service shares a process with other services, the required process may already exist. The
**StartService** function does not wait for the first status update from the new service, because it can take a while. Instead, it returns when the SCM receives notification from the service control dispatcher that the
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) thread for this service was created successfully.

The SCM sets the following default status values before returning from
**StartService**:

* Current state of the service is set to SERVICE_START_PENDING.
* Controls accepted is set to none (zero).
* The CheckPoint value is set to zero.
* The WaitHint time is set to 2 seconds.

The calling process can determine if the new service has finished its initialization by calling the
[QueryServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicestatus) function periodically to query the service's status.

A service cannot call
**StartService** during initialization. The reason is that the SCM locks the service control database during initialization, so a call to
**StartService** will block. After the service reports to the SCM that it has successfully started, it can call
**StartService**.

As with [ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice), **StartService** will block for 30 seconds if any service is busy handling a control code. If the busy service still has not returned from its handler function when the timeout expires, **StartService** fails with ERROR_SERVICE_REQUEST_TIMEOUT. This is because the SCM processes only one service control notification at a time.

#### Examples

For an example, see
[Starting a Service](https://learn.microsoft.com/windows/desktop/Services/starting-a-service).

> [!NOTE]
> The winsvc.h header defines StartService as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice)

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[DeleteService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-deleteservice)

[OpenService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-openservicea)

[QueryServiceDynamicInformation](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicedynamicinformation)

[QueryServiceStatusEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryservicestatusex)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[Service Startup](https://learn.microsoft.com/windows/desktop/Services/service-startup)

[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona)