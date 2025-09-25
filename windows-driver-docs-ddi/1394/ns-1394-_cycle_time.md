# _CYCLE_TIME structure

## Description

The CYCLE_TIME structure contains the IEEE 1394 isochronous cycle time.

## Members

### `CL_CycleOffset`

Specifies the number of clock ticks (based on a 24.576 MHz clock) since the current isochronous cycle began.

### `CL_CycleCount`

Specifies the number of isochronous cycles in the current second.

### `CL_SecondCount`

Specifies the number of seconds. This count wraps to zero every 128 seconds.

## Remarks

The layout of this structure matches that of the CYCLE_TIME register in the *IEEE 1394-1995 specification*.

## See also

[ISOCH_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_isoch_descriptor)

[REQUEST_ISOCH_ALLOCATE_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_ISOCH_LISTEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_ISOCH_QUERY_CYCLE_TIME](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_ISOCH_TALK](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)