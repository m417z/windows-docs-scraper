# _PARALLEL_INTERRUPT_SERVICE_ROUTINE structure

## Description

The PARALLEL_INTERRUPT_SERVICE_ROUTINE structure specifies interrupt services that a kernel-mode driver can connect to the operation of a parallel port.

## Members

### `InterruptServiceRoutine`

Pointer to an interrupt service routine.

### `InterruptServiceContext`

Pointer to a context for the interrupt service routine.

### `DeferredPortCheckRoutine`

Pointer to an optional deferred port check routine:

```
VOID
(*DeferredPortCheckRoutine) (
    IN PVOID DeferredContext
);
```

**Parameters**

#### DeferredContext

Pointer to a context for the deferred port check routine.

### `DeferredPortCheckContext`

Pointer to an optional context for the deferred port check routine.

## Syntax

```cpp
typedef struct _PARALLEL_INTERRUPT_SERVICE_ROUTINE {
  PKSERVICE_ROUTINE          InterruptServiceRoutine;
  PVOID                      InterruptServiceContext;
  PPARALLEL_DEFERRED_ROUTINE DeferredPortCheckRoutine;
  PVOID                      DeferredPortCheckContext;
} PARALLEL_INTERRUPT_SERVICE_ROUTINE, *PPARALLEL_INTERRUPT_SERVICE_ROUTINE;
```

## Remarks

A kernel-mode driver can connect a device-specific interrupt service routine and a deferred port check routine to the parallel port.

**Note** Microsoft does not recommend using a client-supplied interrupt routine. The use of interrupts might cause system instability. By default, the [IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt) request is disabled. For more information, see [Connecting an Interrupt Service Routine to a ParallelPort](https://learn.microsoft.com/previous-versions/ff543934(v=vs.85)).

## See also

[IOCTL_INTERNAL_PARALLEL_DISCONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_disconnect_interrupt)

[IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt)

[PARALLEL_INTERRUPT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_interrupt_information)