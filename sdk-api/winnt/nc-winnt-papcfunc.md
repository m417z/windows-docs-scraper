# PAPCFUNC callback function

## Description

An application-defined completion routine. Specify this address when calling the [QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc) function. The **PAPCFUNC** type defines a pointer to this callback function. **APCProc** is a placeholder for the application-defined function name.

## Parameters

### `Parameter` [in]

The data passed to the function using the *dwData* parameter of the [QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc) function.

## See also

[Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls)

[QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)