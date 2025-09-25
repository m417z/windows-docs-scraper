# SerCxGetReadIntervalTimeout function

## Description

The **SerCxGetReadIntervalTimeout** method returns the interval time-out value for a read (receive) operation.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

## Return value

**SerCxGetReadIntervalTimeout** returns the read-interval time-out value in milliseconds. A value of zero indicates that read-interval time-outs are not used.

## Remarks

The read-interval time-out value is the maximum amount of time, in milliseconds, that is allowed between two consecutive bytes in a read operation. A read operation that exceeds this maximum times out. For more information about time-out values, see [SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts).

A read ([IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)) request successfully completes when the requested read operation times out. The request returns the **STATUS_TIMEOUT** status code to indicate that the operation timed out.

## See also

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)

[SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts)