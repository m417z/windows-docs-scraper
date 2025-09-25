# _PARALLEL_PORT_INFORMATION structure

## Description

The PARALLEL_PORT_INFORMATION structure specifies information about the resources assigned to a parallel port, the capabilities of the parallel port, and pointers to callback routines that a kernel-mode driver can use to operate the parallel port.

## Members

### `OriginalController`

Specifies the bus relative base I/O address of the parallel port registers.

### `Controller`

Pointer to the system-mapped base I/O location of the parallel port registers.

### `SpanOfController`

Specifies the size, in bytes, of the I/O space, allocated to the parallel port.

### `TryAllocatePort`

Pointer to the system-supplied [PPARALLEL_TRY_ALLOCATE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_allocate_routine) callback that a kernel-mode driver can use to attempt to allocate the parallel port.

### `FreePort`

Pointer to the system-supplied [PPARALLEL_FREE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_free_routine) callback that a kernel-mode driver can use to free the parallel port.

### `QueryNumWaiters`

Pointer to the system-supplied [PPARALLEL_QUERY_WAITERS_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_query_waiters_routine) callback that a kernel-mode driver can use to determine the number of requests on the work queue of the parallel port.

### `Context`

Pointer to the device extension of parallel port.

## Syntax

```cpp
typedef struct _PARALLEL_PORT_INFORMATION {
  PHYSICAL_ADDRESS                OriginalController;
  PUCHAR                          Controller;
  ULONG                           SpanOfController;
  PPARALLEL_TRY_ALLOCATE_ROUTINE  TryAllocatePort;
  PPARALLEL_FREE_ROUTINE          FreePort;
  PPARALLEL_QUERY_WAITERS_ROUTINE QueryNumWaiters;
  PVOID                           Context;
} PARALLEL_PORT_INFORMATION, *PPARALLEL_PORT_INFORMATION;
```

## Remarks

An [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request from the Plug and Play manager passes a translated resource list that contains the port information in a PARALLEL_PORT_INFORMATION structure. The system-supplied function driver for parallel ports saves the information in the extension of the parallel port and returns the information in response to an [IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info) request.

For more information, see [Obtaining Information About a ParallelPort](https://learn.microsoft.com/previous-versions/ff544223(v=vs.85)).

## See also

[PPARALLEL_TRY_ALLOCATE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_allocate_routine)

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[PPARALLEL_FREE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_free_routine)

[IOCTL_INTERNAL_GET_MORE_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_more_parallel_port_info)

[PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information)

[MORE_PARALLEL_PORT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_more_parallel_port_information)

[IOCTL_INTERNAL_GET_PARALLEL_PNP_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_pnp_info)

[PPARALLEL_QUERY_WAITERS_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_query_waiters_routine)