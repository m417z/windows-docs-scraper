## Description

The PNEGOTIATE_IEEE_MODE-typed callback routine selects the fastest forward and reverse protocols that the system-supplied bus driver for parallel ports supports from among those specified by the caller. The system-supplied bus driver for parallel ports supplies this routine.

## Parameters

### `Context` [in]

Pointer to the device extension of a parallel device's physical device object ([PDO](https://learn.microsoft.com/windows-hardware/drivers/)).

### `ModeMaskFwd` [in]

Specifies the forward protocols. *ModeMaskFwd* is a bitwise OR of the constants that represent the protocols that the parallel port bus driver supports. For the forward and reverse protocol values, see the protocol constants defined in *ntddpar.h* (from NONE to ECP_ANY).

### `ModeMaskRev` [in]

Specifies the reverse protocols. *ModeMaskRev* is a bitwise OR of the constants that represent the protocols that the parallel port bus driver supports.

### `ModeSafety` [in]

Specifies the safety mode. Must be set to the SAFE_MODE enumeration value of the PARALLEL_SAFETY enumeration type:

```cpp
typedef enum {
  SAFE_MODE,
  UNSAFE_MODE
} PARALLEL_SAFETY;
```

### `IsForward` [in]

Specifies whether to connect the forward or the reverse protocol that the routine negotiates. If *IsForward* is **TRUE**, the forward protocol is connected. Otherwise, the reverse protocol is connected.

## Return value

| Return code | Description |
|--|--|
| STATUS_SUCCESSFUL | The IEEE mode was successfully negotiated. |
| STATUS_DEVICE_PROTOCOL_ERROR | An IEEE mode is already set on the device. |
| STATUS_*Xxx* | An internal operation resulted in an NTSTATUS error. |

## Remarks

To obtain a pointer to the system-supplied PNEGOTIATE_IEEE_MODE callback, a kernel-mode driver uses an [IOCTL_INTERNAL_PARCLASS_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_connect) request, which returns a [PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information) structure. The **NegotiateIeeeMode** member of the PARCLASS_INFORMATION structure is a pointer to this callback.

The PNEGOTIATE_IEEE_MODE callback runs in the caller's thread at the IRQL of the caller.

## See also

- [IOCTL_PAR_GET_DEFAULT_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_default_modes)
- [IOCTL_IEEE1284_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_get_mode)
- [PTERMINATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pterminate_ieee_mode)
- [PPARALLEL_IEEE_FWD_TO_REV](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_fwd_to_rev)
- [IOCTL_IEEE1284_NEGOTIATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_negotiate)
- [PDETERMINE_IEEE_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pdetermine_ieee_modes)
- [PPARALLEL_IEEE_REV_TO_FWD](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_rev_to_fwd)