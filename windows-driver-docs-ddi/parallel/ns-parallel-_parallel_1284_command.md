# _PARALLEL_1284_COMMAND structure

## Description

The PARALLEL_1284_COMMAND structure specifies information that a client uses to select and deselect an IEEE 1284.3 daisy-chain device or an IEEE 1284 end-of-chain device.

## Members

### `ID`

Specifies the IEEE 1284.3 device ID.

### `Port`

Reserved (set to zero).

### `CommandFlags`

Specifies a bitwise OR of zero or more of the following flags:

#### PAR_END_OF_CHAIN_DEVICE

Specifies an end-of-chain device.

#### PAR_HAVE_PORT_KEEP_PORT

Specifies that the client has the parallel port allocated, and makes a request to keep the port allocated.

## Syntax

```cpp
typedef struct _PARALLEL_1284_COMMAND {
  UCHAR ID;
  UCHAR Port;
  ULONG CommandFlags;
} PARALLEL_1284_COMMAND, *PPARALLEL_1284_COMMAND;
```

## Remarks

The system-supplied function driver for parallel ports supports the simultaneous connection of zero to two IEEE 1284.3 daisy-chain devices and an IEEE 1284 end-of-chain device. In Windows XP, the parallel port function driver supports the simultaneous connection of zero to four IEEE 1284.3 daisy-chain devices and an IEEE 1284 end-of-chain device. The end-of-chain device must be an IEEE 1284 device, but does not have to be an IEEE 1284.3 device.

For more information, see [Selecting and Deselecting an IEEE 1284 Device Attached to a ParallelPort](https://learn.microsoft.com/previous-versions/ff544793(v=vs.85)).

## See also

[IOCTL_INTERNAL_SELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_select_device)

[PPARALLEL_DESELECT_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_deselect_routine)

[PPARALLEL_TRY_SELECT_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_try_select_routine)

[IOCTL_INTERNAL_DESELECT_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_deselect_device)