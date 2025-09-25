# NtDeviceIoControlFile function

## Description

The **ZwDeviceIoControlFile** routine sends a control code directly to a specified device driver, causing the corresponding driver to perform the specified operation.

## Parameters

### `FileHandle` [in]

Handle returned by [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) or [**ZwOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile) for the file object representing the device to which the control information should be given or from which information should be returned. The file object must have been opened for asynchronous I/O if the caller specifies an **Event**, **ApcRoutine**, and an APC context (in **ApcContext**), or a completion context (in **ApcContext**). For I/O to an underlying mass-storage device, the file object must have been opened for Direct Access to Storage Device (DASD) access.

### `Event` [in, optional]

Handle for a caller-created event. If this parameter is supplied, the caller will be put into a wait state until the requested operation is completed and the given event is set to the Signaled state. This parameter is optional and can be NULL. It must be NULL if the caller will wait for the **FileHandle** to be set to the Signaled state.

### `ApcRoutine` [in, optional]

Address of an optional, caller-supplied APC routine to be called when the requested operation completes. This parameter can be NULL. It must be NULL if there is an I/O completion object associated with the file object.

### `ApcContext` [in, optional]

Pointer to a caller-determined context area. This parameter value is used as the APC context if the caller supplies an APC, or is used as the completion context if an I/O completion object has been associated with the file object. When the operation completes, either the APC context is passed to the APC, if one was specified, or the completion context is included as part of the completion message that the I/O Manager posts to the associated I/O completion object.

This parameter is optional and can be NULL. It must be NULL if **ApcRoutine** is NULL and there is no I/O completion object associated with the file object.

### `IoStatusBlock` [out]

Pointer to a variable that receives the final completion status and information about the operation. For successful calls that return data, the number of bytes written to the **OutputBuffer** is returned in the **Information** member.

### `IoControlCode` [in]

IOCTL_*Xxx* code that indicates which device I/O control operation is to be carried out on, usually by the underlying device driver. The value of this parameter determines the format and required length of the **InputBuffer** and **OutputBuffer**, as well as which of the following parameter pairs are required. For detailed information about the system-defined, device-type-specific IOCTL_*Xxx* codes, see the [device technology-specific section](https://learn.microsoft.com/windows-hardware/drivers/) of the Microsoft Windows Driver Kit (WDK) documentation and [Device Input and Output Control Codes](https://learn.microsoft.com/windows/desktop/DevIO/device-input-and-output-control-ioctl-).

### `InputBuffer` [in, optional]

Pointer to a caller-allocated input buffer that contains device-specific information to be given to the target device. If **IoControlCode** specifies an operation that does not require input data, this pointer can be NULL.

### `InputBufferLength` [in]

Size, in bytes, of the buffer at **InputBuffer**. If **InputBuffer** is NULL, set **InputBufferLength** to zero.

### `OutputBuffer` [out, optional]

Pointer to a caller-allocated output buffer in which information is returned from the target device. If **IoControlCode** specifies an operation that does not produce output data, this pointer can be NULL.

### `OutputBufferLength` [in]

Size, in bytes, of the buffer at **OutputBuffer**. If **OutputBuffer** is NULL, set **OutputBufferLength** to zero.

## Return value

**ZwDeviceIoControlFile** returns STATUS_SUCCESS if the underlying driver(s) successfully carried out the requested operation. Otherwise, the return value can be an error status code propagated from an underlying driver. Possible error status codes include the following:

## Remarks

**ZwDeviceIoControlFile** provides a consistent view of the input and output data to the system and to kernel-mode drivers, while providing applications and underlying drivers with a device-dependent method of specifying a communications interface.

For more information about system-defined IOCTL_*Xxx* codes, and about defining driver-specific IOCTL_*Xxx* or FSCTL_*Xxx* values, see [Using I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-i-o-control-codes) and [Device Input and Output Control Codes](https://learn.microsoft.com/windows/desktop/DevIO/device-input-and-output-control-ioctl-).

If the caller opened the file for asynchronous I/O (with neither FILE_SYNCHRONOUS_*Xxx* create/open option set), the specified event, if any, will be set to the signaled state when the device control operation completes. Otherwise, the file object specified by **FileHandle** will be set to the signaled state. If an **ApcRoutine** was specified, it is called with the **ApcContext** and **IoStatusBlock** pointers.

Minifilters should use [**FltDeviceIoControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeviceiocontrolfile) instead of **ZwDeviceIoControlFile**.

Callers of **ZwDeviceIoControlFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

If the call to the **ZwDeviceIoControlFile** function occurs in user mode, you should use the name "**NtDeviceIoControlFile**" instead of "**ZwDeviceIoControlFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**FltDeviceIoControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeviceiocontrolfile)

[**IoBuildAsynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[**IoBuildSynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[**IoCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[**ZwOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile)