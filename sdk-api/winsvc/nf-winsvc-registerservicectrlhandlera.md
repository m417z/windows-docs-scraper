# RegisterServiceCtrlHandlerA function

## Description

Registers a function to handle service control requests.

This function has been superseded by the
[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa) function. A service can use either function, but the new function supports user-defined context data, and the new handler function supports additional extended control codes.

## Parameters

### `lpServiceName` [in]

The name of the service run by the calling thread. This is the service name that the service control program specified in the
[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea) function when creating the service.

If the service type is SERVICE_WIN32_OWN_PROCESS, the function does not verify that the specified name is valid, because there is only one registered service in the process.

### `lpHandlerProc` [in]

A pointer to the handler function to be registered. For more information, see
[Handler](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function).

## Return value

If the function succeeds, the return value is a service status handle.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following error codes can be set by the service control manager.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to convert an ANSI string parameter to Unicode. This error does not occur for Unicode string parameters. |
| **ERROR_SERVICE_NOT_IN_EXE** | The service entry was specified incorrectly when the process called the [StartServiceCtrlDispatcher](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicectrldispatchera) function. |

## Remarks

The
[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) function of a new service should immediately call the
**RegisterServiceCtrlHandler** function to register a control handler function with the control dispatcher. This enables the control dispatcher to invoke the specified function when it receives control requests for this service. For a list of possible control codes, see [Handler](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function). The threads of the calling process can use the service status handle returned by this function to identify the service in subsequent calls to the
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) function.

The
**RegisterServiceCtrlHandler** function must be called before the first
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) call because
**RegisterServiceCtrlHandler** returns a service status handle for the caller to use so that no other service can inadvertently set this service status. In addition, the control handler must be in place to receive control requests by the time the service specifies the controls it accepts through the
**SetServiceStatus** function.

When the control handler function is invoked with a control request, the service must call
[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus) to report status to the service control manager only if the service status has changed, such as when the service is processing stop or shutdown controls. If the service status has not changed, the service should not report status to the service control manager.

The service status handle does not have to be closed.

#### Examples

For an example, see
[Writing a ServiceMain Function](https://learn.microsoft.com/windows/desktop/Services/writing-a-servicemain-function).

> [!NOTE]
> The winsvc.h header defines RegisterServiceCtrlHandler as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-createservicea)

[Handler](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function)

[RegisterServiceCtrlHandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-registerservicectrlhandlerexa)

[Service Control Handler Function](https://learn.microsoft.com/windows/desktop/Services/service-control-handler-function)

[Service Functions](https://learn.microsoft.com/windows/desktop/Services/service-functions)

[ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona)

[SetServiceStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setservicestatus)