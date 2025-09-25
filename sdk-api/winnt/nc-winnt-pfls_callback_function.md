# PFLS_CALLBACK_FUNCTION callback function

## Description

An application-defined function. If the FLS slot is in use, **FlsCallback** is called on fiber deletion, thread exit, and when an FLS index is freed. Specify this function when calling the
[FlsAlloc](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsalloc) function. The *PFLS_CALLBACK_FUNCTION* type defines a pointer to this callback function.
**FlsCallback** is a placeholder for the application-defined function name.

## Parameters

### `lpFlsData` [in]

The value stored in the FLS slot for the calling fiber.

## Remarks

Each FLS index has an associated
**FlsCallback** function. The callback function can be used for any purpose, but it is intended to be used primarily to free memory.

## See also

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[FlsAlloc](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsalloc)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)