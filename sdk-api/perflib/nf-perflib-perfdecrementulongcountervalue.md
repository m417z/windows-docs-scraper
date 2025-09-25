# PerfDecrementULongCounterValue function

## Description

Decrements the value of a counter whose value is a 4-byte unsigned integer. Providers use this function.

## Parameters

### `Provider` [in]

The handle of the provider. Use the handle variable that the [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool generated for you. For the name of the variable, see the **symbol** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element.

**Windows Vista:** The [PerfStartProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstartprovider) function returns the handle.

### `Instance` [in]

A [PERF_COUNTERSET_INSTANCE](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_instance) structure that contains the counter set instance. The [PerfCreateInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfcreateinstance) function returns this pointer.

### `CounterId` [in]

Identifier that uniquely identifies the counter to update in the instance block. The identifier is defined in the **id** attribute of the [counter](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-counters-counter--counterset--element) element and must match the **CounterId** member of one of the [PERF_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_info) structures in the instance block. Use the counter ID constant that the [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool generated for you. For the name of the constant, see the **symbol** attribute of the **counter** element.

**Windows Vista:** The counter ID constant is not available.

### `Value` [in]

Value by which to decrement the counter.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This is a convenience function for decrementing raw counter data. To decrement the raw counter data yourself, use the **Offset** member of the [PERF_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_info) structure to access the raw counter data for a specific counter. The [PERF_COUNTERSET_INSTANCE](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_instance) structure block contains one or more counter information structures.

Use the [PerfSetULongCounterValue](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfsetulongcountervalue) function to initially set the counter value.

Note that the counter value will underflow when the counter value decrements past zero.

## See also

[PerfDecrementULongLongCounterValue](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfdecrementulonglongcountervalue)

[PerfIncrementULongCounterValue](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfincrementulongcountervalue)

[PerfSetULongCounterValue](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfsetulongcountervalue)