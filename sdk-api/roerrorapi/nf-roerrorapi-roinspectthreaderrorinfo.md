# RoInspectThreadErrorInfo function

## Description

Gets the error object that represents the call stack at the point where the error originated

## Parameters

### `targetTebAddress` [in]

The target thread environment block (TEB).

### `machine`

The machine to debug.

### `readMemoryCallback`

A callback function to read the buffer from the target TEB address space.

### `context` [in, optional]

Custom context data.

### `targetErrorInfoAddress` [out]

The address of the error object.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the call to **RoInspectThreadErrorInfo** is successful, *targetErrorInfoAddress* contains the address of an error object that you can pass to the [RoInspectCapturedStackBackTrace](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roinspectcapturedstackbacktrace) function to get the call stack at the point where the error was originated.

## See also

[PINSPECT_MEMORY_CALLBACK](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nc-roerrorapi-pinspect_memory_callback)

[RoInspectCapturedStackBackTrace](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roinspectcapturedstackbacktrace)