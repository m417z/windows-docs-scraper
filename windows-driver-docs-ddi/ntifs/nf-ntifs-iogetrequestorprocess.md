# IoGetRequestorProcess function

## Description

The **IoGetRequestorProcess** routine returns a process pointer for the thread that originally requested a given I/O operation.

## Parameters

### `Irp` [in]

A pointer to the I/O request packet (IRP) for the I/O operation.

## Return value

**IoGetRequestorProcess** returns a process pointer for the thread that requested the I/O operation. If the IRP is not associated with any thread, **IoGetRequestorProcess** returns **NULL**.

## Remarks

Staring with Windows Vista. **IoGetRequestorProcess** returns a pointer to the process to which the thread is currently attached. For IRPs queued for file objects, such as for completion port I/O, **IoGetRequestorProcess** returns a pointer to the issuing process. If no thread is attached, **IoGetRequestorProcess** returns a pointer to the process that created the thread.

On Windows XP, **IoGetRequestorProcess** returns a pointer to the process to which the thread is currently attached.

**Note** On Windows XP, in cases where an IRP contains a non-NULL thread but has no thread attached, **IoGetRequestorProcess** will attempt to access the process information for an undefined thread. This presents a possible bug check condition if **IoGetRequestorProcess** is called without exception handling or at too high of an IRQL.

Prior to Windows XP, **IoGetRequestorProcess** returns a pointer to the process that created the thread.

An IRP is automatically associated with a thread if it is issued by the I/O Manager or obtained by calling [IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest), [IoBuildSynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest), or [IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest).

For more information about using system threads and managing synchronization within a nonarbitrary thread context, see [Driver Threads, Dispatcher Objects, and Resources](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#driver-threads-dispatcher-objects-and-resources).

## See also

[IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[IoBuildSynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[IoGetRequestorProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetrequestorprocessid)