# PerfSetCounterRefValue function

## Description

Updates the value of a counter whose value is a pointer to the actual data. Providers use this function.

## Parameters

### `Provider` [in]

The handle of the provider. Use the handle variable that the [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool generated for you. For the name of the variable, see the **symbol** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element.

**Windows Vista:** The [PerfStartProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstartprovider) function returns the handle.

### `Instance` [in]

A [PERF_COUNTERSET_INSTANCE](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_instance) structure that contains the counter set instance. The [PerfCreateInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfcreateinstance) function returns this pointer.

### `CounterId` [in]

Identifier that uniquely identifies the counter to update in the instance block. The identifier is defined in the **id** attribute of the [counter](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-counters-counter--counterset--element) element and must match the **CounterId** member of one of the [PERF_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_info) structures in the instance block. Use the counter ID constant that the [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool generated for you. For the name of the constant, see the **symbol** attribute of the **counter** element.

**Windows Vista:** The counter ID constant is not available.

### `Address` [in]

Pointer to the actual counter data.

If **NULL**, the consumer receives ERROR_NO_DATA.

To indicate that the counter data is accessed by reference, the counter declaration in the manifest must include a [counterAttribute](https://learn.microsoft.com/previous-versions/aa371909(v=vs.85)) element whose **name** attribute is set to "reference".

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This is a convenience function for specifying a reference to the raw counter data. To update the reference to the raw counter data yourself, use the **Offset** member of the [PERF_COUNTER_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counter_info) structure to access the counter value for a specific counter. The **Attrib** member must include the PERF_ATTRIB_BY_REFERENCE flag. The [PERF_COUNTERSET_INSTANCE](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_instance) structure block contains one or more counter information structures.

Depending on the counter type, the pointer must reference a 4-byte or 8-byte unsigned integer. When collecting the counter data, PERFLIB dereferences the pointer and returns the actual data.

## See also

[PerfSetULongCounterValue](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfsetulongcountervalue)

[PerfSetULongLongCounterValue](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfsetulonglongcountervalue)