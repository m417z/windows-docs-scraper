# RoInspectCapturedStackBackTrace function

## Description

Provides a way to for debuggers to inspect a call stack from a target process.

## Parameters

### `targetErrorInfoAddress` [in]

The address of the error info object in the target process. Get the *targetErrorInfoAddress* by calling the [RoInspectThreadErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roinspectthreaderrorinfo) function.

### `machine`

The machine to debug.

### `readMemoryCallback`

A callback function to read the buffer from the target TEB address space.

### `context` [in, optional]

Custom context data.

### `frameCount` [out]

The number of stack frames stored in the error object.

### `targetBackTraceAddress` [out]

The stack back trace address in the target process.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **RoInspectCapturedStackBackTrace** function takes a pointer to a system error object and fills *frameCount* with the number of stack frames stored in the error object, and it fills *targetBackTraceAddress* with the stack back trace address in the target process. The **RoInspectCapturedStackBackTrace** function tries to confirm that *targetErrorInfoAddress* points is to a system error object and fails if it can't match the version signature.

Get the *targetErrorInfoAddress* by calling the [RoInspectThreadErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roinspectthreaderrorinfo) function.

## See also

[PINSPECT_MEMORY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nc-roerrorapi-pinspect_memory_callback)

[RoInspectThreadErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roinspectthreaderrorinfo)