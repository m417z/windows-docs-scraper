# StartServiceCtrlDispatcherA function

## Description

Connects the main thread of a service process to the service control manager, which causes the thread to be the service control dispatcher thread for the calling process.

## Parameters

### `lpServiceStartTable` [in]

A pointer to an array of
[SERVICE_TABLE_ENTRY](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_table_entrya) structures containing one entry for each service that can execute in the calling process. The members of the last entry in the table must have NULL values to designate the end of the table.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error code can be set by the service control manager. Other error codes can be set by the registry functions that are called by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_FAILED_SERVICE_CONTROLLER_CONNECT** | This error is returned if the program is being run as a console application rather than as a service. <br><br>If the program will be run as a console application for debugging purposes, structure it such that service-specific code is not called when this error is returned. |
| **ERROR_INVALID_DATA** | The specified dispatch table contains entries that are not in the proper format. |
| **ERROR_SERVICE_ALREADY_RUNNING** | The process has already called [StartServiceCtrlDispatcher](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicectrldispatchera). Each process can call **StartServiceCtrlDispatcher** only one time. |

## Remarks

When the service control manager starts a service process, it waits for the process to call the
**StartServiceCtrlDispatcher** function. The main thread of a service process should make this call as soon as possible after it starts up (within 30 seconds). If
**StartServiceCtrlDispatcher** succeeds, it connects the calling thread to the service control manager and does not return until all running services in the process have entered the SERVICE_STOPPED state. The service control manager uses this connection to send control and service start requests to the main thread of the service process. The main thread acts as a dispatcher by invoking the appropriate
[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex) function to handle control requests, or by creating a new thread to execute the appropriate
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function when a new service is started.

The *lpServiceTable* parameter contains an entry for each service that can run in the calling process. Each entry specifies the
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function for that service. For SERVICE_WIN32_SHARE_PROCESS services, each entry must contain the name of a service. This name is the service name that was specified by the
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function when the service was installed. For SERVICE_WIN32_OWN_PROCESS services, the service name in the table entry is ignored.

If a service runs in its own process, the main thread of the service process should immediately call
**StartServiceCtrlDispatcher**. All initialization tasks are done in the service's
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function when the service is started.

If multiple services share a process and some common process-wide initialization needs to be done before any
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function is called, the main thread can do the work before calling
**StartServiceCtrlDispatcher**, as long as it takes less than 30 seconds. Otherwise, another thread must be created to do the process-wide initialization, while the main thread calls
**StartServiceCtrlDispatcher** and becomes the service control dispatcher. Any service-specific initialization should still be done in the individual service main functions.

Services should not attempt to display a user interface directly. For more information, see [Interactive Services](https://learn.microsoft.com/windows/desktop/Services/interactive-services).

#### Examples

For an example, see
[Writing a Service Program's Main Function](https://learn.microsoft.com/windows/desktop/Services/writing-a-service-program-s-main-function).

> [!NOTE]
> The winsvc.h header defines StartServiceCtrlDispatcher as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice)

[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex)

[SERVICE_TABLE_ENTRY](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_table_entrya)

[Service Entry Point](https://learn.microsoft.com/windows/desktop/Services/service-entry-point)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona)