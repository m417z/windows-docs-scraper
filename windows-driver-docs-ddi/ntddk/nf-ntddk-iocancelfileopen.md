## Description

The **IoCancelFileOpen** routine can be used by a file system filter driver to close a file that has been opened by a file system driver in the filter driver's device stack.

## Parameters

### `DeviceObject` [in]

Pointer to the top of the device stack immediately below the filter driver's device object.

### `FileObject` [in]

Pointer to the file object for the file to be closed.

## Remarks

If a file system filter driver determines that a file-open or file-create request must fail after the lower-level drivers have already completed the request with STATUS_SUCCESS, it can use **IoCancelFileOpen** to close the file opened by the lower-level drivers.

Although STATUS_REPARSE is a success NTSTATUS value, it is not necessary to call **IoCancelFileOpen** for a create operation that was completed with STATUS_REPARSE, because this status value indicates that the file was not successfully opened.

A successful call to **IoCancelFileOpen** has the following effect: To minifilters and legacy filters that are above the caller in the file system stack, the create request appears to have failed. To those that are below the caller, the file appears to have been opened (or created) and then closed.

Note that **IoCancelFileOpen** does not undo any modifications to the file. For example, **IoCancelFileOpen** does not delete a newly created file or restore a file that was overwritten or superseded to its previous state.

A typical example is as follows:

- A filter driver exists between a higher-level filter driver and a lower-level file system driver.

- The filter driver passes an IRP_MJ_CREATE request down the device stack to the file system driver, and the file system driver completes the IRP_MJ_CREATE request with status STATUS_SUCCESS.

- Before the filter driver completes the create request, it determines that the file must be closed.

- The filter driver uses **IoCancelFileOpen** to close the file that was opened by the file system driver.

After calling **IoCancelFileOpen**, the filter driver should complete the create request with an appropriate error code such as STATUS_UNSUCCESSFUL or STATUS_ACCESS_DENIED. In addition, it should set the **Irp->IoStatus.Information** field to zero.

**IoCancelFileOpen** must be called before any handles are created for the file. Callers can check the **Flags** member of the [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that the *FileObject* parameter points to. If the FO_HANDLE_CREATED flag is set, this means that one or more handles have been created for the file, so it is not safe to call **IoCancelFileOpen**.

**IoCancelFileOpen** sets the FO_FILE_OPEN_CANCELLED flag in the **Flags** member of the file object that *FileObject* points to. This flag indicates that the IRP_MJ_CREATE request has been canceled, and an IRP_MJ_CLOSE request will be issued for this file object. Once the create operation has been canceled, it cannot be reissued - that is, STATUS_REPARSE cannot be returned by the legacy filter driver if it has called the **IoCreateFileOpen** routine.

Minifilters should use [FltCancelFileOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelfileopen) instead of **IoCancelFileOpen**.

## See also

[FltCancelFileOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelfileopen)

[FltReissueSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreissuesynchronousio)

[IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[IoCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatefile)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)

[IoCreateFileSpecifyDeviceObjectHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefilespecifydeviceobjecthint)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[ZwOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile)