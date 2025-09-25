# _IO_ERROR_LOG_PACKET structure

## Description

The **IO_ERROR_LOG_PACKET** structure serves as the header for an error log entry.

## Members

### `MajorFunctionCode`

Indicates the **IRP_MJ_*XXX*** major function code of the IRP the driver was handling when the error occurred. Setting this value is optional.

### `RetryCount`

Indicates the number of times the driver has retried the operation and encountered this error. Use zero to indicate the driver attempted the operation once, or add one for each retry beyond the initial attempt.

### `DumpDataSize`

Indicates the size, in bytes, of the variable-length **DumpData** member of this structure. The specified value must be a multiple of **sizeof**(ULONG).

### `NumberOfStrings`

Indicates the number of insertion strings the driver will supply with this error log entry. Drivers set this value to zero for errors that need no insertion strings. The Event Viewer uses these strings to fill in the "%2" through "%*n*" entries in the string template for this error code.

The null-terminated Unicode strings themselves follow the **IO_ERROR_LOG_PACKET** structure in memory.

### `StringOffset`

Indicates the offset, in bytes, from the beginning of the structure, at which any driver-supplied insertion string data begins. Normally this will be **sizeof**(**IO_ERROR_LOG_PACKET**) plus the value of the **DumpDataSize** member. If there are no driver-supplied insertion strings, **StringOffset** can be zero.

### `EventCategory`

Specifies the event category for the error. A driver specifies the event categories it supports and corresponding descriptive strings in its message catalog. The Event Viewer displays the descriptive string as the **Category** value for the error.

### `ErrorCode`

Specifies the type of error. The Event Viewer uses the error code to determine which string to display as the Description value for the error. The Event Viewer takes the string template for the error supplied in the driver's message catalog, replaces "%1" in the template with the name of the driver's device object, and replaces "%2" through "%*n*" with the insertion strings supplied with the error log entry.

**ErrorCode** is a system-defined or driver-defined constant; see [Logging Errors](https://learn.microsoft.com/windows-hardware/drivers/kernel/logging-errors) for more information.

### `UniqueErrorValue`

A driver-specific value that indicates where the error was detected in the driver. Setting this value is optional.

### `FinalStatus`

Specifies the NTSTATUS value to be returned for the operation that triggered the error. Setting this value is optional.

### `SequenceNumber`

Specifies a driver-assigned sequence number for the current IRP, which should be constant for the life of a given request. Setting this value is optional.

### `IoControlCode`

For an [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control) or [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) IRP, this member specifies the I/O control code for the request that trigged the error. Otherwise, this value is zero. Setting this value is optional.

### `DeviceOffset`

Specifies the driver-specified offset into the device where the error occurred. Setting this value is optional.

### `DumpData`

A variable-size array that can be used to store driver-specific binary data, such as register values or any other information useful in identifying the cause of the error. Drivers must specify the size, in bytes, of the array in the **DumpDataSize** member of this structure.

## Remarks

Drivers use the [IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry) routine to allocate an error log entry. The **IO_ERROR_LOG_PACKET** structure serves as the header for the returned buffer. It is followed in memory by any insertion strings for the log entry.

Note that the I/O manager itself inserts some information into the system error log, such as the name of the device and driver. The I/O manager reserves 80 bytes to hold this information. If the size of this information exceeds 80 bytes, then the I/O manager truncates the driver's insertion strings as necessary.

For more information about how to use this structure, see [Logging Errors](https://learn.microsoft.com/windows-hardware/drivers/kernel/logging-errors).

## See also

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control)

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

[IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry)

[IoFreeErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeerrorlogentry)

[IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry)