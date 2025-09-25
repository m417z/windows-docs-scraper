# IoIsOperationSynchronous function

## Description

The **IoIsOperationSynchronous** routine determines whether a given IRP represents a synchronous or asynchronous I/O request.

## Parameters

### `Irp` [in]

Pointer to the IRP for the operation.

## Return value

**IoIsOperationSynchronous** returns TRUE if the operation is synchronous, otherwise FALSE.

## Remarks

**IoIsOperationSynchronous** determines whether a given IRP requests a synchronous or asynchronous I/O operation, according to the following conditions:

* If the IRP requests asynchronous paging I/O, the operation is asynchronous, even if one of the other conditions is true.

* If the IRP requests synchronous paging I/O, the operation is synchronous.

* If the file object was opened for synchronous I/O, the operation is synchronous.

* If the IRP_SYNCHRONOUS_API flag is set in the IRP, the operation is synchronous. This flag is set for operations, such as [**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) and [**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile), that are always synchronous, even when performed on a file object that was opened for asynchronous I/O.

* If none of the above conditions is true, the operation is asynchronous.

**IoIsOperationSynchronous** also returns TRUE if the IRP contains an IOCTL or FSCTL request with an I/O or file system control code that was defined with METHOD_BUFFERED, even if the file object was opened for asynchronous I/O. Such a request is likely to be made synchronous by the file system, but this is not necessarily true in all cases.

## See also

[**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[**IoBuildSynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[**IoCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatefile)

[**IoCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)

[**IoCreateFileSpecifyDeviceObjectHint**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefilespecifydeviceobjecthint)

[**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[**ZwSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)