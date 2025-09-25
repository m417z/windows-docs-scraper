# PPARALLEL_TRY_ALLOCATE_ROUTINE callback

## Description

The *PPARALLEL_TRY_ALLOCATE_ROUTINE*-typed (ISR) callback routine attempts to allocate a parallel port at IRQL = DIRQL. The system-supplied function driver for parallel ports supplies this routine.

## Parameters

### `TryAllocateContext` [in]

Pointer to the device extension of a functional device object that represents a parallel port.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The parallel port was allocated. |
| **FALSE** | The parallel port was not allocated. |

## Prototype

```cpp
typedef BOOLEAN ParallelTryAllocateRoutine(
  _In_ PVOID TryAllocateContext
);
```

## Remarks

A kernel-mode driver connects an interrupt service routine by using an [IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt), which returns a [PARALLEL_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_information) structure. This structure includes the **TryAllocatePortAtInterruptLevel** member, which is a pointer to the system-supplied *PPARALLEL_TRY_ALLOCATE_ROUTINE* (ISR) callback.

The *PPARALLEL_TRY_ALLOCATE_ROUTINE* (ISR) callback is nonblocking, does not queue an allocate request, and returns immediately.

A driver uses the *PPARALLEL_TRY_ALLOCATE_ROUTINE* (ISR) callback in conjunction with a driver-supplied ISR. If the driver does not have a parallel port allocated when the driver's ISR is called, the driver can use this callback.

For more information about allocating a parallel port in an ISR, see [Connecting an Interrupt Service Routine to a ParallelPort](https://learn.microsoft.com/previous-versions/ff543934(v=vs.85)).

**Note** The *PPARALLEL_TRY_ALLOCATE_ROUTINE* (ISR) callback is untested. Microsoft does not recommend using a client-supplied interrupt routine. The use of interrupts might cause system instability. By default, the [IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt) request is disabled.

## See also

[IOCTL_INTERNAL_PARALLEL_DISCONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_disconnect_interrupt)

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[IOCTL_INTERNAL_PARALLEL_PORT_ALLOCATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_port_allocate)

[IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt)

[IOCTL_INTERNAL_PARALLEL_PORT_FREE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_port_free)

[PPARALLEL_FREE_ROUTINE (ISR)](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_free_routine)

[PARALLEL_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_information)