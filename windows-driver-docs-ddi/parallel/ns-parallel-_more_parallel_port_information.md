# _MORE_PARALLEL_PORT_INFORMATION structure

## Description

The MORE_PARALLEL_PORT_INFORMATION structure specifies information about the system interface that supports the operation of a parallel port.

## Members

### `InterfaceType`

Specifies the I/O bus interface type that is associated with a parallel port. See *wdm.h* or *ntddk.h* for the definition of INTERFACE_TYPE.

### `BusNumber`

Specifies the bus number for the interface.

### `InterruptLevel`

Specifies the interrupt level for the parallel port.

### `InterruptVector`

Specifies the interrupt vector for the parallel port.

### `InterruptAffinity`

Specifies a [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity) interrupt affinity value.

### `InterruptMode`

Specifies the interrupt mode. See *wdm.h* or *ntddk.h* for the declaration of KINTERRUPT_MODE.

## Syntax

```cpp
typedef struct _MORE_PARALLEL_PORT_INFORMATION {
  INTERFACE_TYPE  InterfaceType;
  ULONG           BusNumber;
  ULONG           InterruptLevel;
  ULONG           InterruptVector;
  KAFFINITY       InterruptAffinity;
  KINTERRUPT_MODE InterruptMode;
} MORE_PARALLEL_PORT_INFORMATION, *PMORE_PARALLEL_PORT_INFORMATION;
```

## Remarks

An [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request from the Plug and Play manager passes a translated resource list that contains the information in a MORE_PARALLEL_PORT_INFORMATION structure. The system-supplied function driver for parallel ports saves the information in the device extension of the parallel port functional device object [FDO](https://learn.microsoft.com/windows-hardware/drivers/), and returns the information in response to an [IOCTL_INTERNAL_GET_MORE_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_more_parallel_port_info) request.

For more information, see [Obtaining Information About a ParallelPort](https://learn.microsoft.com/previous-versions/ff544223(v=vs.85)).

## See also

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[PARALLEL_PORT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_port_information)

[IOCTL_INTERNAL_GET_MORE_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_more_parallel_port_info)

[PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information)

[IOCTL_INTERNAL_GET_PARALLEL_PNP_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_pnp_info)