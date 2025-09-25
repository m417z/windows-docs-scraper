# _PARALLEL_CHIP_MODE structure

## Description

The PARALLEL_CHIP_MODE structure specifies the operating mode of a parallel port.

## Members

### `ModeFlags`

Specifies an operating mode of a parallel port, either an enhanced parallel port (EPP) mode or an extended capabilities port (ECP) mode.

### `success`

Not used.

## Syntax

```cpp
typedef struct _PARALLEL_CHIP_MODE {
  UCHAR   ModeFlags;
  BOOLEAN success;
} PARALLEL_CHIP_MODE, *PPARALLEL_CHIP_MODE;
```

## Remarks

A client uses a PARALLEL_CHIP_MODE structure with internal device control requests to set and clear the operating mode of a parallel port.

**Note** Microsoft does not recommend using a client-supplied interrupt routine. The use of interrupts might cause system instability. By default, the [IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt) request is disabled. For more information, see [Connecting an Interrupt Service Routine to a ParallelPort](https://learn.microsoft.com/previous-versions/ff543934(v=vs.85)).

## See also

[IOCTL_INTERNAL_PARALLEL_SET_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_set_chip_mode)

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[IOCTL_INTERNAL_PARALLEL_CONNECT_INTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_connect_interrupt)

[IOCTL_INTERNAL_PARALLEL_CLEAR_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_clear_chip_mode)

[PPARALLEL_SET_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_set_chip_mode)

[PPARALLEL_CLEAR_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_clear_chip_mode)