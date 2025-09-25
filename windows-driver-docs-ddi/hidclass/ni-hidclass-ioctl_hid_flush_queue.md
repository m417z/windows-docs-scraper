# IOCTL_HID_FLUSH_QUEUE IOCTL

## Description

The IOCTL_HID_FLUSH_QUEUE request dequeues all of the unparsed input reports from a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) input report queue.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

 None.

### Input buffer length

None.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The HID class driver sets the **Status** member of **Irp->IoStatus** to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

## See also

[HidD_FlushQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_flushqueue)