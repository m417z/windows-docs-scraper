# _PARALLEL_INTERRUPT_INFORMATION structure

## Description

The PARALLEL_INTERRUPT_INFORMATION structure specifies information that a kernel-mode driver can use in the context of an ISR that the driver connects to a parallel port.

## Members

### `InterruptObject`

Pointer to the parallel port interrupt object.

### `TryAllocatePortAtInterruptLevel`

Pointer to the system-supplied [PPARALLEL_TRY_ALLOCATE_ROUTINE (ISR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_allocate_routine) callback routine that a kernel-mode driver can use to attempt to allocate the parallel port at IRQL = DIRQL.

### `FreePortFromInterruptLevel`

Pointer to the system-supplied [PPARALLEL_FREE_ROUTINE (ISR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_free_routine) callback routine that a kernel-mode driver can use to free the parallel port at IRQL = DIRQL.

### `Context`

Pointer to the device extension of a functional device object that represents the parallel port.

## Syntax

```cpp
typedef struct _PARALLEL_INTERRUPT_INFORMATION {
  PKINTERRUPT                    InterruptObject;
  PPARALLEL_TRY_ALLOCATE_ROUTINE TryAllocatePortAtInterruptLevel;
  PPARALLEL_FREE_ROUTINE         FreePortFromInterruptLevel;
  PVOID                          Context;
} PARALLEL_INTERRUPT_INFORMATION, *PPARALLEL_INTERRUPT_INFORMATION;
```

## Remarks

A kernel-mode driver can use the parallel interrupt information in the context of an interrupt service routine (ISR). A driver connects an ISR using an [IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt) request.

**Note** Microsoft does not recommend using a client-supplied interrupt routine. The use of interrupts might cause system instability. By default, the IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT request is disabled. For more information, see [Connecting an Interrupt Service Routine to a ParallelPort](https://learn.microsoft.com/previous-versions/ff543934(v=vs.85)).

## See also

[IOCTL_INTERNAL_PARALLEL_DISCONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_disconnect_interrupt)

[PARALLEL_INTERRUPT_SERVICE_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_service_routine)

[IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt)

[PPARALLEL_TRY_ALLOCATE_ROUTINE (ISR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_allocate_routine)

[PPARALLEL_FREE_ROUTINE (ISR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_free_routine)