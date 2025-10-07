# CounterInitialize function

Registers the provider and initializes the counter sets.

## Parameters

This function has no parameters.

## Return value

Returns ERROR\_SUCCESS on success; otherwise, a standard Win32 error code.

## Remarks

Your provider calls this function. The function includes calls to the [**PerfStartProvider**](https://learn.microsoft.com/windows/desktop/api/Perflib/nf-perflib-perfstartprovider) function and the [**PerfSetCounterSetInfo**](https://learn.microsoft.com/windows/desktop/api/Perflib/nf-perflib-perfsetcountersetinfo) function.

The [**CTRPP**](https://learn.microsoft.com/windows/win32/perfctrs/ctrpp) tool generates this inline function when you specify the **-o** argument. The function's name include a *prefix* string if you specify the **-prefix** argument.

If you specify the **-MemoryRoutines** or **-NotificationCallback** arguments (or specify the **callback** attribute for the [**provider**](https://learn.microsoft.com/windows/desktop/PerfCtrs/performance-counters-provider--counters--element) element), the **CounterInitialize** signature changes to the following:

``` syntax
ULONG WINAPI CounterInitialize(
    __in_opt PERFLIBREQUEST NotificationCallback,
    __in_opt PERF_MEM_ALLOC MemoryAllocationFunction,
    __in_opt PERF_MEM_FREE MemoryFreeFunction,
    __inout_opt PVOID MemoryFunctionContext
);
```

where,

NotificationCallback

The name of your [*ControlCallback*](https://learn.microsoft.com/windows/desktop/api/Perflib/nc-perflib-perflibrequest) callback function that you implement to receive notification of consumer requests (for example, requests to add or remove counters from the query). Set to **NULL** if you do not implement the *ControlCallback* callback function.

MemoryAllocationFunction

The name of your [*AllocateMemory*](https://learn.microsoft.com/windows/desktop/api/Perflib/nc-perflib-perf_mem_alloc) callback function that PERFLIB calls to allocate memory. Set to **NULL** if you did not specify the **-MemoryRoutines** argument.

MemoryFreeFunction

The name of your [*FreeMemory*](https://learn.microsoft.com/windows/desktop/api/Perflib/nc-perflib-perf_mem_free) callback function that PERFLIB calls to free the memory allocated using the [*AllocateMemory*](https://learn.microsoft.com/windows/desktop/api/Perflib/nc-perflib-perf_mem_alloc) function. Set to **NULL** if *MemoryAllocationFunction* is **NULL**.

MemoryFunctionContext

Context information to pass to your memory allocation and free routines. Can be **NULL**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |

