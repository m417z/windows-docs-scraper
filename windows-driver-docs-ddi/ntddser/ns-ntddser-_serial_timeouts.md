# _SERIAL_TIMEOUTS structure

## Description

The **SERIAL_TIMEOUTS** structure specifies the time-out parameters for read and write operations by the serial port.

## Members

### `ReadIntervalTimeout`

The maximum amount of time, in milliseconds, that is allowed between two consecutive bytes in a read operation. A read operation that exceeds this maximum times out. This maximum does not apply to the time interval that precedes the reading of the first byte. A value of zero indicates that interval time-outs are not used. For more information, see Remarks.

### `ReadTotalTimeoutMultiplier`

The maximum amount of time, in milliseconds, that is allowed per byte in a read operation. A read operation that exceeds this maximum times out. For more information, see Remarks.

### `ReadTotalTimeoutConstant`

The maximum amount of additional time, in milliseconds, that is allowed per read operation. A read operation that exceeds this maximum times out. For more information, see Remarks.

### `WriteTotalTimeoutMultiplier`

The maximum total time, in milliseconds, that is allowed per byte in a write operation. A write operation that exceeds this maximum times out. For more information, see Remarks.

### `WriteTotalTimeoutConstant`

The maximum amount of additional time, in milliseconds, that is allowed per write operation. A write operation that exceeds this maximum times out. For more information, see Remarks.

## Remarks

The **SERIAL_TIMEOUTS** structure is used by the [IOCTL_SERIAL_SET_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_timeouts) and [IOCTL_SERIAL_GET_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_timeouts) I/O control requests. An **IOCTL_SERIAL_SET_TIMEOUTS** I/O control request uses this structure to specify a set of time-out parameters for the serial port to use for read and write operations. An **IOCTL_SERIAL_GET_TIMEOUTS** I/O control request uses this structure to retrieve the time-out parameters that were set by the previous **IOCTL_SERIAL_SET_TIMEOUTS** request.

A read or write request successfully completes when either the specified number of bytes is transferred or the requested read or write operation times out. The request returns the STATUS_SUCCESS status code to indicate that the specified number of bytes was transferred. The request returns the STATUS_TIMEOUT status code to indicate that the operation timed out.

If an [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) request specifies a read operation that is Nₜₒₜₐₗ bytes in length, the maximum amount of time, Tₘₐₓ, that the serial port allows for the operation to complete is calculated as follows:

Tₘₐₓ = Nₜₒₜₐₗ * **ReadTotalTimeoutMultiplier** + **ReadTotalTimeoutConstant**

A read request that exceeds this maximum completes when the time-out occurs, and returns the STATUS_TIMEOUT status code. The **Information** field of the I/O status block indicates the number of bytes successfully read before the time-out occurred.

If an [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write) request specifies a write operation that is Nₜₒₜₐₗ bytes in length, the maximum amount of time, Tₘₐₓ, that the serial port allows for the operation to complete is calculated as follows:

Tₘₐₓ = Nₜₒₜₐₗ * **WriteTotalTimeoutMultiplier** + **WriteTotalTimeoutConstant**

A write request that exceeds this maximum completes when the time-out occurs, and returns the STATUS_TIMEOUT status code. The **Information** field of the I/O status block indicates the number of bytes successfully written before the time-out occurred.

The maximum time, Tₘₐₓ, that is allowed for a read or write operation to complete is always measured from when the serial port starts the requested operation, and not from when the client submits the request.

If **ReadIntervalTimeout**, **ReadTotalTimeoutMultiplier**, and **ReadTotalTimeoutConstant** are all zero, read operations never time out. If **WriteTotalTimeoutMultiplier** and **WriteTotalTimeoutConstant** are both zero, write operations never time out.

If **ReadIntervalTimeout** is zero, there is no maximum interval between consecutive bytes in read operations, and time-outs are based solely on the **ReadTotalTimeoutMultiplier** and **ReadTotalTimeoutConstant** members.

If both **ReadTotalTimeoutMultiplier** and **ReadTotalTimeoutConstant** are zero, and **ReadIntervalTimeout** is less than MAXULONG and greater than zero, a read operation times out only if the interval between a pair of consecutively received bytes exceeds **ReadIntervalTimeout**. If these three time-out values are used, and the serial port's input buffer is empty when a read request is sent to the port, this request never times out until after the port receives at least one byte of new data.

If **ReadIntervalTimeout** is set to MAXULONG, and both **ReadTotalTimeoutConstant** and **ReadTotalTimeoutMultiplier** are zero, a read request completes immediately with the bytes that have already been received, even if no bytes have been received. In this case, the read request returns the STATUS_SUCCESS status code.

If both **ReadIntervalTimeout** and **ReadTotalTimeoutMultiplier** are set to MAXULONG, and **ReadTotalTimeoutConstant** is set to a value greater than zero and less than MAXULONG, a read request behaves as follows:

* If there are any bytes in the serial port's input buffer, the read request completes immediately with the bytes that are in the buffer and returns the STATUS_SUCCESS status code.
* If there are no bytes in the input buffer, the serial port waits until a byte arrives, and then immediately completes the read request with the one byte of data and returns the STATUS_SUCCESS status code.
* If no bytes arrive within the time specified by **ReadTotalTimeoutConstant**, the read request times out, sets the **Information** field of the I/O status block to zero, and returns the STATUS_TIMEOUT status code.

An **IOCTL_SERIAL_SET_TIMEOUTS** request fails and returns an INVALID_PARAMETER error status code if **ReadIntervalTimeout** and **ReadTotalTimeoutConstant** are both set to MAXULONG.

A read-interval time-out can be used to detect the end of an incoming data stream when the length of the data stream is not known in advance. If a read request uses this technique, a STATUS_TIMEOUT completion status code usually means that the request completed successfully.

A read-interval time-out occurs when the interval between incoming bytes exceeds the **ReadIntervalTimeout** value. Time-out intervals are measured relative to the system clock, and the accuracy of the time-out measurement is limited by the granularity of the system clock. As a result, a time-out can occur between one system clock tick earlier and one tick later than the specified time-out interval, depending on where exactly the start and end times of this interval fall between system clock ticks. Time-outs might occur even later if system clock interrupt processing is delayed by interrupt processing for other devices. If a specified time-out interval is close to or smaller than the period between system clock ticks, the time-out might occur immediately, with no delay.

A possible way to more accurately measure smaller time-out intervals is to decrease the time between system clock ticks, but doing so is likely to increase power consumption. In addition, reducing the system clock period might not reliably achieve a finer system clock granularity unless interrupt-related processing by the various drivers in the platform can be guaranteed not to delay the processing of system clock interrupts.

The **SERIAL_TIMEOUTS** structure is similar to the [COMMTIMEOUTS](https://learn.microsoft.com/windows/win32/api/winbase/ns-winbase-commtimeouts) structure, which is used by the user-mode [SetCommTimeouts](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-setcommtimeouts) and [GetCommTimeouts](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getcommtimeouts) functions.

For more information, see [Setting Read and Write Timeouts for a Serial Device](https://learn.microsoft.com/previous-versions/ff547486(v=vs.85)).

## See also

[COMMTIMEOUTS](https://learn.microsoft.com/windows/win32/api/winbase/ns-winbase-commtimeouts)

[GetCommTimeouts](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getcommtimeouts)

[IOCTL_SERIAL_SET_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_timeouts)

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)

[IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write)

[SerCxGetReadIntervalTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxgetreadintervaltimeout)

[SetCommTimeouts](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-setcommtimeouts)