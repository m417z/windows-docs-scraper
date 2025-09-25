# PPARALLEL_CLEAR_CHIP_MODE callback

## Description

The *PPARALLEL_CLEAR_CHIP_MODE*-typed callback routine clears the operating mode of a parallel port by resetting the communication mode of the host chipset to IEEE 1284-compatibility mode. The system-supplied function driver for parallel ports supplies this routine.

## Parameters

### `ClearChipContext` [in]

Pointer to the device extension of a parallel port's functional device object ([FDO](https://learn.microsoft.com/windows-hardware/drivers/)).

### `ChipMode` [in]

Specifies the current operating mode of the parallel port.

For more information about operating modes, see the modes that are defined for the enhanced capabilities register (ECR) in the *parallel.h* file that is included in the Microsoft Windows Driver Kit (WDK).

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operating mode was set to IEEE 1284-compatibility mode. |
| **STATUS_INVALID_DEVICE_STATE** | The specified mode does not match the current mode. |

## Prototype

```cpp
typedef NTSTATUS (*PPARALLEL_CLEAR_CHIP_MODE)(
  _In_ PVOID ClearChipContext,
  _In_ UCHAR ChipMode
);
```

## Remarks

To obtain a pointer to the system-supplied *PPARALLEL_CLEAR_CHIP_MODE* callback, a kernel-mode driver uses an [IOCTL_INTERNAL_GET_PARALLEL_PNP_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_pnp_info) request, which returns a [PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information) structure. The **ClearChipMode** member of the PARALLEL_PNP_INFORMATION structure is a pointer to this callback.

A caller uses the *PPARALLEL_CLEAR_CHIP_MODE* callback in conjunction with the [PPARALLEL_SET_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_set_chip_mode) callback.

To set a mode, a caller must first clear the current mode.

For more information, see [Setting and Clearing the Communication Mode on a ParallelPort](https://learn.microsoft.com/previous-versions/ff544801(v=vs.85)).

## See also

[IOCTL_INTERNAL_PARALLEL_SET_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_set_chip_mode)

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information)

[IOCTL_INTERNAL_PARALLEL_CLEAR_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parallel_clear_chip_mode)

[PPARALLEL_SET_CHIP_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_set_chip_mode)