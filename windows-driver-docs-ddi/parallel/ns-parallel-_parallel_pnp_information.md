# _PARALLEL_PNP_INFORMATION structure

## Description

The PARALLEL_PNP_INFORMATION structure specifies information about the capabilities of a parallel port.

## Members

### `OriginalEcpController`

Specifies the base physical address that the system-supplied function driver for parallel ports uses to control the ECP operation of the parallel port.

### `EcpController`

Pointer to the I/O port resource that is used to control the port in ECP mode.

### `SpanOfEcpController`

Specifies the size, in bytes, of the I/O port resource.

### `PortNumber`

Not used.

### `HardwareCapabilities`

Specifies the hardware capabilities of the parallel port. The following capabilities can be set using a bitwise OR of the following constants:

#### PPT_1284_3_PRESENT

#### PPT_BYTE_PRESENT

#### PPT_ECP_PRESENT

#### PPT_EPP_32_PRESENT

#### PPT_EPP_PRESENT

#### PT_NO_HARDWARE_PRESENT

### `TrySetChipMode`

Pointer to the system-supplied [PPARALLEL_SET_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_set_chip_mode) callback that a kernel-mode driver can use to change the operating mode of the parallel port.

### `ClearChipMode`

Pointer to the system-supplied [PPARALLEL_CLEAR_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_clear_chip_mode) callback that a kernel-mode driver can use to clear the operating mode of the parallel port.

### `FifoDepth`

Specifies the size, in words, of the hardware first in/first out (FIFO) buffer. The FIFO word size, in bits, is the value of **FifoWidth**.

### `FifoWidth`

Specifies the FIFO word size, in bits, which is the number of bits handled in parallel.

### `EppControllerPhysicalAddress`

Not used.

### `SpanOfEppController`

Not used.

### `Ieee1284_3DeviceCount`

Specifies the number of daisy-chain devices currently attached to a parallel port. In Microsoft Windows XP, from zero to two devices can be simultaneously connected to a parallel port. In Windows 2000, from zero to four devices can be simultaneously connected to a parallel port.

### `TrySelectDevice`

Pointer to the system-supplied [PPARALLEL_TRY_SELECT_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_select_routine) callback that a kernel-mode driver can use to attempt to select an IEEE 1284.3 device.

### `DeselectDevice`

Pointer to the system-supplied [PPARALLEL_DESELECT_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_deselect_routine) callback that a kernel-mode driver can use to deselect an IEEE 1284.3 device.

### `Context`

Pointer to the device extension of a parallel port's functional device object ([FDO](https://learn.microsoft.com/windows-hardware/drivers/)).

### `CurrentMode`

The current operating mode of the parallel port.

### `PortName`

The symbolic link name of the parallel port.

## Syntax

```cpp
typedef struct _PARALLEL_PNP_INFORMATION {
  PHYSICAL_ADDRESS             OriginalEcpController;
  PUCHAR                       EcpController;
  ULONG                        SpanOfEcpController;
  ULONG                        PortNumber;
  ULONG                        HardwareCapabilities;
  PPARALLEL_SET_CHIP_MODE      TrySetChipMode;
  PPARALLEL_CLEAR_CHIP_MODE    ClearChipMode;
  ULONG                        FifoDepth;
  ULONG                        FifoWidth;
  PHYSICAL_ADDRESS             EppControllerPhysicalAddress;
  ULONG                        SpanOfEppController;
  ULONG                        Ieee1284_3DeviceCount;
  PPARALLEL_TRY_SELECT_ROUTINE TrySelectDevice;
  PPARALLEL_DESELECT_ROUTINE   DeselectDevice;
  PVOID                        Context;
  ULONG                        CurrentMode;
  PWSTR                        PortName;
} PARALLEL_PNP_INFORMATION, *PPARALLEL_PNP_INFORMATION;
```

## Remarks

For more information, see [Obtaining Information About a ParallelPort](https://learn.microsoft.com/previous-versions/ff544223(v=vs.85)).

## See also

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[PPARALLEL_TRY_SELECT_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_select_routine)

[PARALLEL_PORT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_port_information)

[IOCTL_INTERNAL_GET_MORE_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_more_parallel_port_info)

[MORE_PARALLEL_PORT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_more_parallel_port_information)

[PPARALLEL_SET_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_set_chip_mode)

[PPARALLEL_DESELECT_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_deselect_routine)

[PPARALLEL_CLEAR_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_clear_chip_mode)

[IOCTL_INTERNAL_GET_PARALLEL_PNP_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_pnp_info)