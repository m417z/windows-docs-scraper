# PDETERMINE_IEEE_MODES callback

## Description

The PDETERMINE_IEEE_MODES-typed callback routine determines which IEEE 1284 protocols a parallel device supports. The system-supplied bus driver for parallel ports supplies this routine.

## Parameters

### `Context` [in]

Pointer to a device extension of a parallel device's physical device object ([PDO](https://learn.microsoft.com/windows-hardware/drivers/)).

## Return value

The return value indicates which protocols a parallel device supports. The return value is a bitwise OR of one or more of the following constants that represent the protocols that are supported by the system-supplied bus driver for parallel ports. The protocol constants are listed in order of decreasing data transfer rate.

BOUNDED_ECP

ECP_HW_NOIRQ

EPP_HW

EPP_SW

ECP_SW

IEEE_COMPATIBILITY

CENTRONICS

NONE

## Prototype

```cpp
typedef USHORT ( *PDETERMINE_IEEE_MODES)(
  _In_ PVOID Context
);
```

## Remarks

To obtain a pointer to the system-supplied PDETERMINE_IEEE_MODES callback, a kernel-mode driver uses an [IOCTL_INTERNAL_PARCLASS_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_connect) request, which returns a [PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information) structure. The **DetermineIeeeModes** member of the PARCLASS_INFORMATION structure is a pointer to this callback.

The PDETERMINE_IEEE_MODES callback runs in the caller's thread at the IRQL of the caller.

## See also

[IOCTL_PAR_GET_DEFAULT_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_default_modes)

[IOCTL_IEEE1284_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_get_mode)

[PTERMINATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pterminate_ieee_mode)

[PNEGOTIATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pnegotiate_ieee_mode)

[PPARALLEL_IEEE_FWD_TO_REV](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_fwd_to_rev)

[IOCTL_IEEE1284_NEGOTIATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_negotiate)

[PPARALLEL_IEEE_REV_TO_FWD](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_rev_to_fwd)