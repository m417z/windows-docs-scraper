# IOCTL_SET_NUM_DEVICE_INPUT_BUFFERS IOCTL

## Description

The IOCTL_SET_NUM_DEVICE_INPUT_BUFFERS request sets the number of buffers for the input report queue of a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

Each input report queue is implemented as a ring buffer. If a collection transmits data to the HID class driver faster than the driver can read it, some of the data may be lost. To prevent this type of loss, you can use an IOCTL_SET_NUM_DEVICE_INPUT_BUFFERS request to adjust the number of buffers that the input report queue contains. The HID class driver requires a minimum of two input buffers. On Windows 2000, the maximum number of input buffers that the HID class driver supports is 200, and on Windows XP and later, the maximum number of input buffers that the HID class driver supports is 512. The default number of input buffers is 32.

For general information about HIDClass devices, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## Parameters

### Major code

### Input buffer

**Irp->AssociatedIrp.SystemBuffer** points to a ULONG-sized input buffer that receives the new number of buffers for the input report queue.

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP contains the size, in bytes, of the input buffer at **Irp->AssociatedIrp.SystemBuffer**. This size must be **sizeof**(ULONG).

### Input buffer length

The size of a ULONG.

### Output buffer

 None.

### Output buffer length

 None.

### Input/output buffer

### Input/output buffer length

### Status block

If the request succeeds, the HID class driver sets the **Status** field of **Irp->IoStatus** to STATUS_SUCCESS; otherwise, it sets the **Status** field to an appropriate NTSTATUS error code.

## See also

[HidD_GetNumInputBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getnuminputbuffers)