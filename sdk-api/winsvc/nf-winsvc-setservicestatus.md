# SetServiceStatus function

## Description

Updates the service control manager's status information for the calling service.

## Parameters

### `hServiceStatus` [in]

A handle to the status information structure for the current service. This handle is returned by the
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa) function.

### `lpServiceStatus` [in]

A pointer to the
[SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status) structure the contains the latest status information for the calling service.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager. Other error codes can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_DATA** | The specified service status structure is invalid. |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |

## Remarks

A
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function first calls the
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa) function to get the service's SERVICE_STATUS_HANDLE. Then it immediately calls the
**SetServiceStatus** function to notify the service control manager that its status is SERVICE_START_PENDING. During initialization, the service can provide updated status to indicate that it is making progress but it needs more time. A common bug is for the service to have the main thread perform the initialization while a separate thread continues to call
**SetServiceStatus** to prevent the service control manager from marking it as hung. However, if the main thread hangs, then the service start ends up in an infinite loop because the worker thread continues to report that the main thread is making progress.

After processing a control request, the service's
[Handler](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex) function must call
**SetServiceStatus** if the service status changes to report its new status to the service control manager. It is only necessary to do so when the service is changing state, such as when it is processing stop or shutdown controls. A service can also use this function at any time from any thread of the service to notify the service control manager of state changes, such as when the service must stop due to a recoverable error.

A service can call this function only after it has called
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa) to get a service status handle.

If a service calls
**SetServiceStatus** with the **dwCurrentState** member set to SERVICE_STOPPED and the **dwWin32ExitCode** member set to a nonzero value, the following entry is written into the System event log:

``` syntax
   Event ID    = 7023
   Source      = Service Control Manager
   Type        = Error
   Description = <ServiceName> terminated with the following error:
                 <ExitCode>.
```

The following are best practices when calling this function:

* Initialize all fields in the [SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status) structure, ensuring that there are valid check-point and wait hint values for pending states. Use reasonable wait hints.
* Do not register to accept controls while the status is SERVICE_START_PENDING or the service can crash. After initialization is completed, accept the SERVICE_CONTROL_STOP code.
* Call this function with checkpoint and wait-hint values only if the service is making progress on the tasks related to the pending start, stop, pause, or continue operation. Otherwise, SCM cannot detect if your service is hung.
* Enter the stopped state with an appropriate exit code if [ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) fails.
* If the status is SERVICE_STOPPED, perform all necessary cleanup and call **SetServiceStatus** one time only. This function makes an LRPC call to the SCM. The first call to the function in the SERVICE_STOPPED state closes the RPC context handle and any subsequent calls can cause the process to crash.
* Do not attempt to perform any additional work after calling **SetServiceStatus** with SERVICE_STOPPED, because the service process can be terminated at any time.

#### Examples

For an example, see
[Writing a ServiceMain Function](https://learn.microsoft.com/windows/desktop/Services/writing-a-servicemain-function).

## See also

[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex)

[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa)

[SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona)

[SetServiceBits](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-setservicebits)