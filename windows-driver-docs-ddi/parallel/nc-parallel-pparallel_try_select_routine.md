# PPARALLEL_TRY_SELECT_ROUTINE callback

## Description

The *PPARALLEL_TRY_SELECT_ROUTINE*-typed callback routine selects an IEEE 1284.3 daisy chain device or an IEEE 1284 end-of-chain device that is attached to a parallel port. The system-supplied function driver for parallel ports supplies this routine.

## Parameters

### `TrySelectContext` [in]

Pointer to the device extension of a parallel port's functional device object ([FDO](https://learn.microsoft.com/windows-hardware/drivers/)).

### `TrySelectCommand` [in]

Pointer to a [PARALLEL_1284_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_1284_command) structure. The caller specifies the following members:

#### ID

Specifies the 1284.3 device ID.

#### CommandFlags

Specifies a bitwise OR of zero or more of the following flags:

| Value | Description |
| --- | --- |
| PAR_END_OF_CHAIN_DEVICE | Specifies an end-of-chain device. |
| PAR_HAVE_PORT_KEEP_PORT | Specifies that the caller has the port allocated and to keep the port allocated. |

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The device was selected. |
| **STATUS_INVALID_PARAMETER** | The device ID is not valid. |
| **STATUS_PENDING** | The caller did not specify PAR_HAVE_PORT_KEEP_PORT, and the parallel port is already allocated. |
| **STATUS_UNSUCCESSFUL** | The caller has allocated the parallel port, but the system-supplied function driver for parallel ports could not select the specified parallel device. |

## Prototype

```cpp
typedef NTSTATUS (*PPARALLEL_TRY_SELECT_ROUTINE)(
  _In_ PVOID TrySelectContext,
  _In_ PVOID TrySelectCommand
);
```

## Remarks

To obtain a pointer to the system-supplied *PPARALLEL_TRY_SELECT_ROUTINE* callback, a kernel-mode driver uses an [IOCTL_INTERNAL_GET_PARALLEL_PNP_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_pnp_info) request, which returns a [PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information) structure. The **TrySelectDevice** member of the PARALLEL_PNP_INFORMATION structure is a pointer to this callback.

A kernel-mode driver can use an [IOCTL_INTERNAL_SELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_select_device) request or the *PPARALLEL_TRY_SELECT_ROUTINE* callback to select a parallel device on a parallel port. The parallel port function driver queues a select request if the parallel port is already allocated. However, the *PPARALLEL_TRY_SELECT_ROUTINE* callback does not queue a select request, and the routine returns immediately if the port cannot be allocated.

**Note**
If a client uses only the *PPARALLEL_TRY_SELECT_ROUTINE* callback to attempt to select a parallel device, and other clients are contending for the parallel port, the system-supplied function driver for parallel ports might never allocate the port to the client. To ensure success, a client must use an [IOCTL_INTERNAL_SELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_select_device) request. (The parallel port function driver queues, and subsequently processes, port allocate requests and device select requests in the order in which select device requests are received.)

For more information, see [Selecting and Deselecting an IEEE 1284 Device Attached to a ParallelPort](https://learn.microsoft.com/previous-versions/ff544793(v=vs.85)).

## See also

[PARALLEL_1284_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_1284_command)

[IOCTL_INTERNAL_GET_PARALLEL_PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_get_parallel_port_info)

[IOCTL_INTERNAL_SELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_select_device)

[IOCTL_INTERNAL_DESELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_deselect_device)

[PARALLEL_PNP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parallel_pnp_information)

[PPARALLEL_DESELECT_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_deselect_routine)