# PPARALLEL_DESELECT_ROUTINE callback

## Description

The *PPARALLEL_DESELECT_ROUTINE*-typed callback routine deselects either an IEEE 1284.3 daisy chain device or an IEEE 1284 end-of-chain device that is attached to a parallel port. The system-supplied function driver for parallel ports supplies this routine.

## Parameters

### `DeselectContext` [in]

Pointer to the device extension of a functional device object ([FDO](https://learn.microsoft.com/windows-hardware/drivers/)) that represents a parallel port.

### `DeselectCommand` [in]

Pointer to a PARALLEL_1284_COMMAND structure. The caller specifies the following members:

#### ID

Specifies the 1284.3 device ID (zero or 1).

#### CommandFlags

Specifies a bitwise OR of zero or more of the following flags:

| Value | Description |
| --- | --- |
| PAR_END_OF_CHAIN_DEVICE | Specifies an end-of-chain device. |
| PAR_HAVE_PORT_KEEP_PORT | Specifies that the port be kept allocated. |

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The device was deselected. |
| **STATUS_INVALID_PARAMETER** | The specified device ID is invalid. |
| **STATUS_UNSUCCESSFUL** | The system-supplied function driver for parallel ports could not deselect the device. |

## Prototype

```cpp
typedef NTSTATUS (*PPARALLEL_DESELECT_ROUTINE)(
  _In_ PVOID DeselectContext,
  _In_ PVOID DeselectCommand
);
```

## Remarks

To obtain a pointer to the system-supplied *PPARALLEL_DESELECT_ROUTINE* callback, a kernel-mode driver uses an [IOCTL_INTERNAL_GET_PARALLEL_PNP_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_pnp_info) request, which returns a [PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information) structure. The **DeselectDevice** member of the PARALLEL_PNP_INFORMATION structure is a pointer to this callback.

A kernel-mode driver can use an [IOCTL_INTERNAL_DESELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_deselect_device) request or the *PPARALLEL_CLEAR_CHIP_MODE* callback to deselect a device on a parallel port represented by a parallel port. To deselect a device, a caller should have the parallel port allocated. If the caller does not set the PAR_HAVE_PORT_KEEP_PORT flag, the system-supplied function driver for parallel ports frees the parallel port after deselecting the device.

For more information, see [Selecting and Deselecting an IEEE 1284 Device Attached to a ParallelPort](https://learn.microsoft.com/previous-versions/ff544793(v=vs.85)).

## See also

[IOCTL_INTERNAL_SELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_select_device)

[PPARALLEL_TRY_SELECT_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_select_routine)

[IOCTL_INTERNAL_DESELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_deselect_device)

[PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information)