# PERF_MEM_ALLOC callback function

## Description

Providers implement this function to provide custom memory management for PERFLIB. PERFLIB calls this callback when it needs to allocate memory. By default, PERFLIB uses the process heap to allocate memory.

The **PERF_MEM_ALLOC** type defines a pointer to this callback function. The **AllocateMemory** function is a placeholder for the application-defined function name.

## Parameters

### `AllocSize` [in]

Number of bytes to allocate.

### `pContext` [in]

Context information set in the **pMemContext** member of [PERF_PROVIDER_CONTEXT](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_provider_context).

## Return value

Pointer to the allocated memory or **NULL** if an error occurred.

## Remarks

If you used the **-MemoryRoutines** when calling [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp), you must implement this callback function. You pass the name of your callback function to [CounterInitialize](https://learn.microsoft.com/windows/desktop/PerfCtrs/counterinitialize).

**Windows Vista:** The [CounterInitialize](https://learn.microsoft.com/windows/desktop/PerfCtrs/counterinitialize) function is named **PerfAutoInitialize**.

## See also

[FreeMemory](https://learn.microsoft.com/windows/desktop/api/perflib/nc-perflib-perf_mem_free)

[PERF_PROVIDER_CONTEXT](https://learn.microsoft.com/windows/win32/api/perflib/ns-perflib-perf_provider_context)