# CancelDC function

## Description

The **CancelDC** function cancels any pending operation on the specified device context (DC).

## Parameters

### `hdc` [in]

A handle to the DC.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **CancelDC** function is used by multithreaded applications to cancel lengthy drawing operations. If thread A initiates a lengthy drawing operation, thread B may cancel that operation by calling this function.

If an operation is canceled, the affected thread returns an error and the result of its drawing operation is undefined. The results are also undefined if no drawing operation was in progress when the function was called.

## See also

[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[GetCurrentThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread)