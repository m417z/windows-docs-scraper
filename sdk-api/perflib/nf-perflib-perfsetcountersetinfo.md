# PerfSetCounterSetInfo function

## Description

Specifies the layout of a particular counter set.

## Parameters

### `ProviderHandle` [in]

The handle of the provider. Use the handle variable that the [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp) tool generated for you. For the name of the variable, see the **symbol** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element.

**Windows Vista:** The [PerfStartProvider](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstartprovider) function returns the handle.

### `Template` [in]

Buffer that contains the counter set information. For details, see [PERF_COUNTERSET_INFO](https://learn.microsoft.com/windows/desktop/api/perflib/ns-perflib-perf_counterset_info).

### `TemplateSize` [in]

Size, in bytes, of the *pTemplate* buffer.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The [CounterInitialize](https://learn.microsoft.com/windows/desktop/PerfCtrs/counterinitialize) function calls this function; do not call this function directly.

**Windows Vista:** The **PerfAutoInitialize** function calls this function.