# IOCTL_GET_NUM_DEVICE_INPUT_BUFFERS IOCTL

## Description

The IOCTL_GET_NUM_DEVICE_INPUT_BUFFERS request obtains the size of the input report queue for a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

The input report queue is implemented as a ring buffer. If a collection transmits data to the HID class driver faster than the input reports are read, reports can be lost. The size of the input report queue can be adjusted using [IOCTL_SET_NUM_DEVICE_INPUT_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_set_num_device_input_buffers).

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer, which must be >= **sizeof**(ULONG).

### Input buffer length

The size of the buffer is **sizeof**(ULONG).

### Output buffer

**Irp->AssociatedIrp.SystemBuffer** points to a buffer that will receive the size of the report input queue.

### Output buffer length

The size of the buffer is **sizeof**(ULONG).

### Input/output buffer

### Input/output buffer length

### Status block

The HID class driver sets the following fields of **Irp->IoStatus**:

* **Information** is set to **sizeof**(ULONG) if the size of the report input queue is successfully retrieved.
* **Status** is set to STATUS_SUCCESS if the transfer completed without error. Otherwise, it is set to an appropriate NTSTATUS error code.

## See also

[HidD_SetNumInputBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setnuminputbuffers)