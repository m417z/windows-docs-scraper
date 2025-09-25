# PERF_PROVIDER_CONTEXT structure

## Description

Defines provider context information.

## Members

### `ContextSize`

The size of this structure.

### `Reserved`

Reserved.

### `ControlCallback`

The name of the [ControlCallback](https://learn.microsoft.com/windows/desktop/api/perflib/nc-perflib-perflibrequest) function that PERFLIB calls to notify you of consumer requests, such as a request to add or remove counters from the query. Set this member if the **callback** attribute of the [provider](https://learn.microsoft.com/previous-versions/aa373164(v=vs.85)) element is "custom" or you used the **-NotificationCallback** argument when calling [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp). Otherwise, **NULL**.

### `MemAllocRoutine`

The name of the [AllocateMemory](https://learn.microsoft.com/windows/desktop/api/perflib/nc-perflib-perf_mem_alloc) function that PERFLIB calls to allocate memory. Set this member if you used the **-MemoryRoutines** argument when calling [CTRPP](https://learn.microsoft.com/windows/desktop/PerfCtrs/ctrpp). Otherwise, **NULL**.

### `MemFreeRoutine`

The name of the [FreeMemory](https://learn.microsoft.com/windows/desktop/api/perflib/nc-perflib-perf_mem_free) function that PERFLIB calls to free memory allocated by the [AllocateMemory](https://learn.microsoft.com/windows/desktop/api/perflib/nc-perflib-perf_mem_alloc) function. Must be **NULL** if **MemAllocRoutine** is **NULL**.

### `pMemContext`

Context information passed to the memory allocation and free routines. Can be **NULL**.

## Remarks

By default, PERFLIB uses process heap. The memory allocation and free routines lets you provide custom memory management.

## See also

[PerfStartProviderEx](https://learn.microsoft.com/windows/desktop/api/perflib/nf-perflib-perfstartproviderex)