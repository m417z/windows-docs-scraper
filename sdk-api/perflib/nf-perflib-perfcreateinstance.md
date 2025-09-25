# PerfCreateInstance function

## Description

Creates an instance of the specified counter set. Providers use this function.

## Parameters

### `ProviderHandle` [in]

The handle of the provider. Use the handle variable that the [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool generated for you. For the name of the variable, see the **symbol** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element.

**Windows Vista:** The [PerfStartProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstartprovider) function returns the handle.

### `CounterSetGuid` [in]

GUID that uniquely identifies the counter set that you want to create an instance of. This is the same GUID specified in the **guid** attribute of the [counterSet](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-counters-counterset--provider--element) element. Use the GUID variable that the [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool generated for you. For the name of the variable, see the **symbol** attribute of the **counterSet** element.

**Windows Vista:** The GUID variable is not available.

### `Name` [in]

**Null**-terminated Unicode string that contains a unique name for this instance.

### `Id` [in]

Unique identifier for this instance of the counter set. The identifier can be a serial number that you increment for each new instance.

## Return value

A [PERF_COUNTERSET_INSTANCE](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_instance) structure that contains the instance of the counter set or **NULL** if PERFLIB could not create the instance. Cache this pointer to use in later calls instead of calling [PerfQueryInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfqueryinstance) to retrieve the pointer to the instance.

This function returns **NULL** if an error occurred. To determine the error that occurred, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The provider determines when it creates an instance. If the counter data is more static, the provider can create an instance at initialization time. For example, the number of processors on a computer would be considered static, so a provider that provides counter data for processors could create an instance for each processor on the computer at initialization time. For counters that are more dynamic, such as disk or process counters, the providers would create the new instances in response to a new USB device being added or a new process being created.

When the provider calls this function, PERFLIB allocates local memory for the new instance and builds the instance block. PERFLIB deletes the memory when the provider calls the [PerfDeleteInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfdeleteinstance) function.

The instance contains the raw counter data. Providers use the following three functions to update the raw counter data:

* [PerfSetUlongCounterValue](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfsetulongcountervalue)
* [PerfSetUlongLongCounterValue](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfsetulonglongcountervalue)
* [PerfSetCounterRefValue](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfsetcounterrefvalue)

Typically, the provider keeps the counter data up-to-date at all times. As an alternative, the provider can implement the [ControlCallback](https://learn.microsoft.com/windows/desktop/api/perflib/nc-perflib-perflibrequest) function and use the **PERF_COLLECT_START** request code to trigger the updates.

## See also

[PerfDeleteInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfdeleteinstance)

[PerfQueryInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfqueryinstance)