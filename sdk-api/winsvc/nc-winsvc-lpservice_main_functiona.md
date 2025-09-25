# LPSERVICE_MAIN_FUNCTIONA callback function

## Description

The entry point for a service.

The **LPSERVICE_MAIN_FUNCTION** type defines a pointer to this callback function.
**ServiceMain** is a placeholder for an application-defined function name.

## Parameters

### `dwNumServicesArgs` [in]

The number of arguments in the *lpServiceArgVectors* array.

### `lpServiceArgVectors` [in]

The null-terminated argument strings passed to the service by the call to the
[StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea) function that started the service. If there are no arguments, this parameter can be NULL. Otherwise, the first argument (lpServiceArgVectors[0]) is the name of the service, followed by any additional arguments (lpServiceArgVectors[1] through lpServiceArgVectors[dwNumServicesArgs-1]).

If the user starts a manual service using the Services snap-in from the Control Panel, the strings for the *lpServiceArgVectors* parameter come from the properties dialog box for the service (from the Services snap-in, right-click the service entry, click **Properties**, and enter the parameters in **Start parameters**.)

## Remarks

A service program can start one or more services. A service process has a
[SERVICE_TABLE_ENTRY](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_table_entrya) structure for each service that it can start. The structure specifies the service name and a pointer to the
**ServiceMain** function for that service.

When the service control manager receives a request to start a service, it starts the service process (if it is not already running). The main thread of the service process calls the
[StartServiceCtrlDispatcher](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicectrldispatchera) function with a pointer to an array of
[SERVICE_TABLE_ENTRY](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_table_entrya) structures. Then the service control manager sends a start request to the service control dispatcher for this service process. The service control dispatcher creates a new thread to execute the
**ServiceMain** function of the service being started.

The
**ServiceMain** function should immediately call the
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa) function to specify a
[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function) function to handle control requests. Next, it should call the
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) function to send status information to the service control manager. After these calls, the function should complete the initialization of the service. Do not attempt to start another service in the
**ServiceMain** function.

The Service Control Manager (SCM) waits until the service reports a status of SERVICE_RUNNING. It is recommended that the service reports this status as quickly as possible, as other components in the system that require interaction with SCM will be blocked during this time. Some functions may require interaction with the SCM either directly or indirectly.

The SCM locks the service control database during initialization, so if a service attempts to call [StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea) during initialization, the call will block. When the service reports to the SCM that it has successfully started, it can call **StartService**. If the service requires another service to be running, the service should set the required dependencies.

Furthermore, you should not call any system functions during service initialization. The service code should call system functions only after it reports a status of SERVICE_RUNNING.

The
**ServiceMain** function should create a global event, call the
[RegisterWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerwaitforsingleobject) function on this event, and exit. This will terminate the thread that is running the
**ServiceMain** function, but will not terminate the service. When the service is stopping, the service control handler should call [SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) with SERVICE_STOP_PENDING and signal this event. A thread from the thread pool will execute the wait callback function; this function should perform clean-up tasks, including closing the global event, and call
**SetServiceStatus** with SERVICE_STOPPED. After the service has stopped, you should not execute any additional service code because you can introduce a race condition if the service receives a start control and **ServiceMain** is called again. Note that this problem is more likely to occur when multiple services share a process.

#### Examples

For an example, see
[Writing a ServiceMain Function](https://learn.microsoft.com/windows/desktop/Services/writing-a-servicemain-function).

> [!NOTE]
> The winsvc.h header defines LPSERVICE_MAIN_FUNCTION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex)

[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa)

[RegisterWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerwaitforsingleobject)

[SERVICE_TABLE_ENTRY](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_table_entrya)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[Service ServiceMain Function](https://learn.microsoft.com/windows/desktop/Services/service-servicemain-function)

[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus)

[StartServiceCtrlDispatcher](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicectrldispatchera)