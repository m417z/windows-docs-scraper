# PTERMINATE_IEEE_MODE callback

## Description

The PTERMINATE_IEEE_MODE-typed callback routine terminates the current IEEE operating mode and sets the mode to IEEE 1284-compatible. The system-supplied bus driver for parallel ports supplies this routine.

## Parameters

### `Context` [in]

Pointer to the device extension of a parallel device's physical device object ([PDO](https://learn.microsoft.com/windows-hardware/drivers/)).

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operating mode was set to IEEE 1284-compatible mode. |

## Prototype

```cpp
typedef NTSTATUS ( *PTERMINATE_IEEE_MODE)(
  _In_ PVOID Context
);
```

## Remarks

To obtain a pointer to the system-supplied PTERMINATE_IEEE_MODE callback, a kernel-mode driver uses an [IOCTL_INTERNAL_PARCLASS_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_connect) request, which returns a [PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information) structure. The **TerminateIeeeMode** member of the PARCLASS_INFORMATION structure is a pointer to this callback.

The PTERMINATE_IEEE_MODE callback runs in the caller's thread at the IRQL of the caller.

For more information, see [Setting and Clearing a Communication Mode for a Parallel Device](https://learn.microsoft.com/previous-versions/ff544797(v=vs.85)).

## See also

[IOCTL_PAR_GET_DEFAULT_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_default_modes)

[IOCTL_IEEE1284_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_get_mode)

[PPARALLEL_IEEE_FWD_TO_REV](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_fwd_to_rev)

[PNEGOTIATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pnegotiate_ieee_mode)

[IOCTL_IEEE1284_NEGOTIATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_negotiate)

[PDETERMINE_IEEE_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pdetermine_ieee_modes)

[PPARALLEL_IEEE_REV_TO_FWD](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_rev_to_fwd)