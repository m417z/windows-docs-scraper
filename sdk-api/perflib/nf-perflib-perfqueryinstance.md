# PerfQueryInstance function

## Description

Retrieves a pointer to the specified counter set instance. Providers use this function.

## Parameters

### `ProviderHandle` [in]

The handle of the provider. Use the handle variable that the [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool generated for you. For the name of the variable, see the **symbol** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element.

**Windows Vista:** The [PerfStartProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstartprovider) function returns the handle.

### `CounterSetGuid` [in]

GUID that uniquely identifies the counter set that you want to query. This is the same GUID specified in the **guid** attribute of the [counterSet](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-counters-counterset--provider--element) element. Use the GUID variable that the [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool generated for you. For the name of the variable, see the **symbol** attribute of the **counterSet** element.

**Windows Vista:** The GUID variable is not available.

### `Name` [in]

**Null**-terminated Unicode string that contains the name of counter set instance that you want to retrieve.

### `Id` [in]

Unique identifier of the counter set instance that you want to retrieve.

## Return value

A [PERF_COUNTERSET_INSTANCE](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_instance) structure that contains the counter set instance or **NULL** if the instance does not exist.

This function returns **NULL** if an error occurred. To determine the error that occurred, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Use the same instance name and identifier that you used when calling [PerfCreateInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfcreateinstance) to retrieve a specific instance of the counter set.

Providers should cache the pointer to the instance when they create the instance instead of calling this function to retrieve the pointer.

## See also

[PerfCreateInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfcreateinstance)