## Description

The **IoAllocateErrorLogEntry** routine allocates an error log entry, and returns a pointer to the packet that the caller uses to supply information about an I/O error.

## Parameters

### `IoObject` [in]

Pointer to a device object representing the device on which an I/O error occurred, or to a driver object representing the driver that found an error.

### `EntrySize` [in]

Specifies the size, in bytes, of the error log entry to be allocated. This value cannot exceed ERROR_LOG_MAXIMUM_SIZE.

> [!WARNING]
> *EntrySize* is a **UCHAR** value. If you specify a larger value, the compiler will silently truncate that value to a (wrong) **UCHAR**.

## Return value

**IoAllocateErrorLogEntry** returns a pointer to the error log entry, or **NULL** if a log entry could not be allocated.

## Remarks

The driver must first fill in the packet with information about the error, then call [IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry) to post the entry to the error log. The error log entry buffer is automatically freed once the log entry is recorded. Entry buffers that are not going to be written to the log can be freed by using [IoFreeErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeerrorlogentry).

An error log entry consists of a variable-length [IO_ERROR_LOG_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_error_log_packet) structure, possibly followed by one or more zero-counted Unicode strings. The Event Viewer inserts these strings into the error message it displays for the entry. **IO_ERROR_LOG_PACKET** contains one variable-length member, the **DumpData** member. Thus, the value for *EntrySize* must be **sizeof**(**IO_ERROR_LOG_PACKET**) + size of the **DumpData** member + combined size of any driver-supplied insertion strings.

Drivers should check that the value for *EntrySize* is less than ERROR_LOG_MAXIMUM_SIZE before calling **IoAllocateErrorLogEntry**. Since *EntrySize* is declared as a UCHAR, and the compiler will silently truncate any value too big to fit into a UCHAR, the routine itself cannot reliably detect if the passed value is too large.

Drivers must not treat **IoAllocateErrorLogEntry** returning **NULL** as a fatal error. The driver must continue to function normally, regardless of whether it can log errors.

## See also

[IO_ERROR_LOG_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_error_log_packet)

[IoFreeErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeerrorlogentry)

[IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry)