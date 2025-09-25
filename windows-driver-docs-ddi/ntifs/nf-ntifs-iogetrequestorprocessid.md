# IoGetRequestorProcessId function

## Description

The **IoGetRequestorProcessId** routine returns the unique 32-bit process ID for the thread that originally requested a given I/O operation.

## Parameters

### `Irp` [in]

A pointer to the I/O request packet (IRP) for the specified I/O operation.

## Return value

**IoGetRequestorProcessId** returns the process ID for the thread that requested the I/O operation. If the IRP is not associated with any thread, **IoGetRequestorProcessId** returns zero.

## Remarks

On Microsoft Windows XP and later, **IoGetRequestorProcessId** returns the process ID for the process to which the thread is currently attached.

On Microsoft Windows 2000 and earlier, **IoGetRequestorProcessId** returns the process ID for the process that created the thread.

For more information about using system threads and managing synchronization within a nonarbitrary thread context, see [Driver Threads, Dispatcher Objects, and Resources](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#driver-threads-dispatcher-objects-and-resources).

## See also

[IoGetRequestorProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetrequestorprocess)