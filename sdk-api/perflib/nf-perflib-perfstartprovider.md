# PerfStartProvider function

## Description

Registers the provider.

## Parameters

### `ProviderGuid` [in]

GUID that uniquely identifies the provider. The **providerGuid** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element specifies the GUID.

### `ControlCallback` [in, optional]

[ControlCallback](https://learn.microsoft.com/windows/desktop/api/perflib/nc-perflib-perflibrequest) function that PERFLIB calls to notify you of consumer requests, such as a request to add or remove counters from the query. This parameter is set if the **callback** attribute of the **counters** element is "custom"; otherwise, **NULL**.

### `phProvider` [out]

Handle to the provider. You must call [PerfStopProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstopprovider) to release resources associated with the handle.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The [CounterInitialize](https://learn.microsoft.com/windows/desktop/PerfCtrs/counterinitialize) function calls this function; do not call this function directly.

**Windows Vista:** The **PerfAutoInitialize** function calls this function.

## See also

[PerfStopProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstopprovider)