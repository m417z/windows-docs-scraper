# PPARALLEL_QUERY_WAITERS_ROUTINE callback

## Description

The *PPARALLEL_QUERY_WAITERS_ROUTINE*-typed callback routine returns the number of [IOCTL_INTERNAL_PARALLEL_PORT_ALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_port_allocate) and [IOCTL_INTERNAL_SELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_select_device) requests that are queued on the work queue of a parallel port. The system-supplied function driver for parallel ports supplies this routine.

## Parameters

### `QueryAllocsContext` [in]

Pointer to the device extension of a functional device object ([FDO](https://learn.microsoft.com/windows-hardware/drivers/)) that represents a parallel port.

## Return value

The number of requests that are queued on the work queue of the parallel port.

## Prototype

```cpp
typedef ULONG (*PPARALLEL_QUERY_WAITERS_ROUTINE)(
  _In_ PVOID QueryAllocsContext
);
```

## Remarks

To obtain a pointer to the system-supplied *PPARALLEL_QUERY_WAITERS_ROUTINE* callback, a kernel-mode driver uses an [IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info) request, which returns a [PARALLEL_PORT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_port_information) structure. The **QueryNumWaiters** member of the PARALLEL_PORT_INFORMATION structure is a pointer to this callback.

A driver can use the *PPARALLEL_QUERY_WAITERS_ROUTINE* callback to adjust its use of the parallel port based on the number of other clients that are waiting for access to the parallel port. The system-supplied function driver for parallel ports queues only allocate and select requests.

For more information, see [Synchronizing the Use of a ParallelPort](https://learn.microsoft.com/previous-versions/ff544809(v=vs.85)).

## See also

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[IOCTL_INTERNAL_PARALLEL_PORT_ALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_port_allocate)

[PPARALLEL_FREE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_free_routine)

[IOCTL_INTERNAL_PARALLEL_PORT_FREE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_port_free)

[PARALLEL_PORT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_port_information)