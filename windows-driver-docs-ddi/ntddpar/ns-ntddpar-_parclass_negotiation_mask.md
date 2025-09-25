# _PARCLASS_NEGOTIATION_MASK structure

## Description

The PARCLASS_NEGOTIATION_MASK structure specifies the read and write protocols that a driver selects for a parallel device.

## Members

### `usReadMask`

Specifies the read protocols. For read and write protocol values, see the constants that are defined in *ntddpar.h* (from NONE to ECP_ANY).

### `usWriteMask`

Specifies the write protocols.

## Syntax

```cpp
typedef struct _PARCLASS_NEGOTIATION_MASK {
  USHORT usReadMask;
  USHORT usWriteMask;
} PARCLASS_NEGOTIATION_MASK, *PPARCLASS_NEGOTIATION_MASK;
```

## Remarks

A client specifies a set of requested protocols by setting a bitwise OR of the constants that represent each protocol. The system-supplied bus driver for parallel ports selects the fastest protocol that it supports from among those specified by the client.

For more information, see [Setting and Clearing a Communication Mode for a Parallel Device](https://learn.microsoft.com/previous-versions/ff544797(v=vs.85)).

## See also

[IOCTL_PAR_GET_DEFAULT_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_get_default_modes)

[IOCTL_IEEE1284_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_get_mode)

[PNEGOTIATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pnegotiate_ieee_mode)

[IOCTL_IEEE1284_NEGOTIATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_ieee1284_negotiate)

[PDETERMINE_IEEE_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pdetermine_ieee_modes)