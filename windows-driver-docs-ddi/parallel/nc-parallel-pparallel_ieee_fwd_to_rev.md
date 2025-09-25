# PPARALLEL_IEEE_FWD_TO_REV callback

## Description

The PPARALLEL_IEEE_FWD_TO_REV-typed callback routine changes the transfer mode from forward to reverse. The system-supplied bus driver for parallel ports supplies this routine.

## Parameters

### `Context` [in]

Pointer to a device extension of a parallel device's physical device object ([PDO](https://learn.microsoft.com/windows-hardware/drivers/)).

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The transfer mode was changed from forward to reverse. |
| **STATUS_*Xxx*** | An internal operation resulted in an NTSTATUS error. |

## Prototype

```cpp
typedef NTSTATUS ( *PPARALLEL_IEEE_FWD_TO_REV)(
  _In_ PVOID Context
);
```

## Remarks

To obtain a pointer to the system-supplied PPARALLEL_IEEE_FWD_TO_REV callback, a kernel-mode driver uses an [IOCTL_INTERNAL_PARCLASS_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_connect) request, which returns a [PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information) structure. The **IeeeFwdToRevMode** member of the PARCLASS_INFORMATION structure is a pointer to this callback.

If the device is connected and in the reverse mode, the PPARALLEL_IEEE_FWD_TO_REV callback returns without further processing. Otherwise, the callback puts the parallel device into reverse mode and connects a previously negotiated reverse protocol. The [PNEGOTIATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pnegotiate_ieee_mode) callback can be used to negotiate the reverse protocol.

The PPARALLEL_IEEE_FWD_TO_REV callback runs in the caller's thread at the caller's IRQL.

## See also

[IOCTL_PAR_GET_DEFAULT_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_default_modes)

[IOCTL_IEEE1284_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_get_mode)

[PTERMINATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pterminate_ieee_mode)

[PNEGOTIATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pnegotiate_ieee_mode)

[IOCTL_IEEE1284_NEGOTIATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_negotiate)

[PDETERMINE_IEEE_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pdetermine_ieee_modes)

[PPARALLEL_IEEE_REV_TO_FWD](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_rev_to_fwd)