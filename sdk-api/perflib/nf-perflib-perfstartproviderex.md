# PerfStartProviderEx function

## Description

Registers the provider.

## Parameters

### `ProviderGuid` [in]

GUID that uniquely identifies the provider. The **providerGuid** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element specifies the GUID.

### `ProviderContext` [in, optional]

A [PERF_PROVIDER_CONTEXT](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_provider_context) structure that contains pointers to the control callback, memory management routines, and context information.

### `Provider` [out]

Handle to the provider. You must call [PerfStopProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstopprovider) to release resources associated with the handle.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The [CounterInitialize](https://learn.microsoft.com/windows/desktop/PerfCtrs/counterinitialize) function calls this function; do not call this function directly.

**Windows Vista:** The **PerfAutoInitialize** function calls this function.

The CTRPP tool includes this function instead of [PerfStartProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstartprovider) if you use the **-MemoryRoutines** argument or **-NotificationCallback** argument when calling [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp), or if the **callback** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element is set to "custom".

## See also

[PerfStopProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstopprovider)