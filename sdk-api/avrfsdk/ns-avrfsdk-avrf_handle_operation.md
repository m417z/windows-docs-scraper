# AVRF_HANDLE_OPERATION structure

## Description

Contains information required to collect handle trace information.

## Members

### `Handle`

The handle to the heap in which handle traces are being enumerated.

### `ProcessId`

A unique identifier associated with the process in which the application is running.

### `ThreadId`

A unique identifier of the thread (returned by the [GetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid) function) that has performed an operation on the given handle.

### `OperationType`

One of the constants in the [eHANDLE_TRACE_OPERATIONS](https://learn.microsoft.com/windows/desktop/api/avrfsdk/ne-avrfsdk-ehandle_trace_operations) enum that indicate whether the handle operation is an open(create), close, or invalid.

### `Spare0`

The alignment of the structure on a natural boundary even if the user has changed the size of the original structure.

### `BackTraceInformation`

Identifies the [AVRF_BACKTRACE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/avrfsdk/ns-avrfsdk-avrf_backtrace_information) structure containing information required for completing the enumeration of handles.

## See also

[Resource Enumeration](https://learn.microsoft.com/windows/desktop/DevNotes/resource-enumeration)

[VerifierEnumerateResource](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nf-avrfsdk-verifierenumerateresource)