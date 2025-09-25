# PINSPECT_MEMORY_CALLBACK callback function

## Description

Provides a function pointer to the callback used by the [RoInspectCapturedStackBackTrace](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roinspectcapturedstackbacktrace) function.

## Parameters

### `context` [in]

Custom context data provided to the [RoInspectCapturedStackBackTrace](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roinspectcapturedstackbacktrace) function.

### `readAddress` [in]

The address to read data from.

### `length` [in]

The number of bytes to read, starting at *readAddress*.

### `buffer` [out]

The buffer that receives a copy of the bytes that are read.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[RoInspectCapturedStackBackTrace](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roinspectcapturedstackbacktrace)