# PerfDeleteInstance function

## Description

Deletes an instance of the counter set created by the [PerfCreateInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfcreateinstance) function. Providers use this function.

## Parameters

### `Provider` [in]

The handle of the provider. Use the handle variable that the [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool generated for you. For the name of the variable, see the **symbol** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element.

**Windows Vista:** The [PerfStartProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstartprovider) function returns the handle.

### `InstanceBlock` [in]

A [PERF_COUNTERSET_INSTANCE](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_instance) structure that contains the instance of the counter set to delete.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

If the provider process terminates abnormally, all allocated instances will be released.

The provider determines when it deletes an instance. If the counter data is more static, the provider can delete an instance at cleanup time. For example, the number of processors on a computer would be considered static, so a provider that provides counter data for processors could delete an instance for each processor on the computer at cleanup time. For counters that are more dynamic, such as disk or process counters, the providers would delete the instances in response to a USB device being removed or a process being terminated.

## See also

[PerfCreateInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfcreateinstance)

[PerfQueryInstance](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfqueryinstance)