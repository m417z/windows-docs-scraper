# PPARALLEL_FREE_ROUTINE callback

## Description

The *PPARALLEL_FREE_ROUTINE*-typed callback routine frees a parallel port. The system-supplied function driver for parallel ports supplies this routine.

## Parameters

### `FreeContext` [in]

Pointer to the device extension of a parallel port's functional device object ([FDO](https://learn.microsoft.com/windows-hardware/drivers/)).

## Prototype

```cpp
typedef VOID (*PPARALLEL_FREE_ROUTINE)(
  _In_ PVOID FreeContext
);
```

## Remarks

To obtain a pointer to the system-supplied *PPARALLEL_FREE_ROUTINE* callback, a kernel-mode driver uses an [IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info) request, which returns a [PARALLEL_PORT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_port_information) structure. The **FreePort** member of the PARALLEL_PORT_INFORMATION structure is a pointer to this callback.

The driver should allocate a parallel port before freeing it. A driver can use [PPARALLEL_QUERY_WAITERS_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_query_waiters_routine) to determine the number of clients that are waiting to allocate the parallel port, and [PPARALLEL_TRY_ALLOCATE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_allocate_routine) to try to allocate the parallel port.

For more information, see [Synchronizing the Use of a ParallelPort](https://learn.microsoft.com/previous-versions/ff544809(v=vs.85)).

## See also

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[PARALLEL_PORT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_port_information)

[PPARALLEL_TRY_ALLOCATE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_allocate_routine)

[PPARALLEL_QUERY_WAITERS_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_query_waiters_routine)