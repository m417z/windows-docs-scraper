# PerfStopProvider function

## Description

Removes the provider's registration from the list of registered providers and frees all resources associated with the provider.

## Parameters

### `ProviderHandle` [in]

Handle to the provider.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The [CounterCleanup](https://learn.microsoft.com/windows/desktop/PerfCtrs/countercleanup) function calls this function; do not call this function directly.

**Windows Vista:** The **PerfAutoCleanup** function calls this function.

## See also

[PerfStartProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstartprovider)