# PERF_MEM_FREE callback function

## Description

Providers implement this function to provide custom memory management for PERFLIB. PERFLIB calls this callback when it needs to free memory that it allocated using [AllocateMemory](https://learn.microsoft.com/windows/desktop/api/perflib/nc-perflib-perf_mem_alloc).

The **PERF_MEM_FREE** type defines a pointer to this callback function. The **FreeMemory** function is a placeholder for the application-defined function name.

## Parameters

### `pBuffer` [in]

Memory to free.

### `pContext` [in]

Context information set in the **pMemContext** member of [PERF_PROVIDER_CONTEXT](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_provider_context).

## Remarks

If you used the **-MemoryRoutines** when calling [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp), you must implement this callback function. You pass the name of your callback function to [CounterInitialize](https://learn.microsoft.com/windows/desktop/PerfCtrs/counterinitialize).

**Windows Vista:** The [CounterInitialize](https://learn.microsoft.com/windows/desktop/PerfCtrs/counterinitialize) function is named **PerfAutoInitialize**.

## See also

[AllocateMemory](https://learn.microsoft.com/windows/desktop/api/perflib/nc-perflib-perf_mem_alloc)

[PERF_PROVIDER_CONTEXT](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_provider_context)