# ResUtilSetResourceServiceStartParametersEx function

## Description

Adjusts the start parameters of a specified [service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly) so that it operates correctly as a cluster [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). It must be called from a [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls). The **PRESUTIL_SET_RESOURCE_SERVICE_START_PARAMETERS_EX** type defines a pointer to this function.

## Parameters

### `pszServiceName` [in]

A pointer to a null-terminated Unicode string that specifies the name of the service.

### `schSCMHandle` [in]

A handle to the Service Control Manager (SCM) or **NULL**. If **NULL**, the function attempts to open a handle to the SCM.

### `phService` [in, out]

On input, a **NULL** service handle. On output, handle to the specified service if the call was successful; otherwise **NULL**.

### `dwDesiredAccess` [in]

The requested access privileges. This might be any combination of **GENERIC_READ** (0x80000000), **GENERIC_ALL** (0x10000000), or **MAXIMUM_ALLOWED** (0x02000000). If this value is zero (0), an undefined error might be returned. Using **GENERIC_ALL** is the same as calling [ResUtilSetResourceServiceStartParameters](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetresourceservicestartparameters).

### `pfnLogEvent` [in]

A pointer to the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) entry point function of the resource DLL that manages the service.

### `hResourceHandle` [in]

A resource handle that is required by the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) entry point function. Use the handle that is passed to the DLL in the [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine) entry point function.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

**ResUtilSetResourceServiceStartParametersEx** verifies that the service is not disabled, changes the service configuration to manual start, and prevents the service from restarting in response to failure. This enables the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and the resource DLL to control the service.

If your resource DLL manages a service, use **ResUtilSetResourceServiceStartParametersEx** and [ResUtilSetResourceServiceEnvironment](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetresourceserviceenvironment) before you bring the service online.

## See also

[ResUtilSetResourceServiceStartParameters](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetresourceservicestartparameters)

[Service Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/service-utility-functions)