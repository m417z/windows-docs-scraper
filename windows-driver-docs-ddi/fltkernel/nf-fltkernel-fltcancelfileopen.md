# FltCancelFileOpen function

## Description

A minifilter driver can use the **FltCancelFileOpen** routine to close a newly opened or created file.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for the file. This parameter is required and cannot be **NULL**.

## Return value

None

## Remarks

If a minifilter driver determines that a file-open or file-create ([IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)) operation must fail after the file system has already completed the operation with a success NTSTATUS value such as STATUS_SUCCESS, the minifilter driver can call **FltCancelFileOpen** from its post-create callback routine to close the file.

**Note** Although STATUS_REPARSE is a success NTSTATUS value, it is not necessary to call **FltCancelFileOpen** for a create operation that was completed with STATUS_REPARSE, because this status value indicates that the file was not successfully opened.

A successful call to **FltCancelFileOpen** has the following effect: To minifilter drivers and legacy filters that are above the caller in the minifilter driver instance stack, the create request appears to have failed. To those that are below the caller, the file appears to have been opened (or created) and then closed.

Note that **FltCancelFileOpen** does not undo any modifications to the file. For example, **FltCancelFileOpen** does not delete a newly created file or restore a file that was overwritten or superseded to its previous state.

**FltCancelFileOpen** must be called before any handles are created for the file. Callers can check the **Flags** member of the [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that the *FileObject* parameter points to. If the FO_HANDLE_CREATED flag is set, this means that one or more handles have been created for the file, so it is not safe to call **FltCancelFileOpen**.

**FltCancelFileOpen** sets the FO_FILE_OPEN_CANCELLED flag in the **Flags** member of the file object that *FileObject* points to. This flag indicates that the create operation has been canceled, and a close ([IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)) request will be issued for this file object.

Once the create operation has been canceled, it cannot be reissued. For more information, see [FltReissueSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreissuesynchronousio).

**FltCancelFileOpen** can only be called from a minifilter driver's post-create callback routine. Calling **FltCancelFileOpen** from a postoperation callback ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routine for any other type of I/O operation, or calling it from a preoperation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine, is a programming error.

Callers of **FltCancelFileOpen** must be running at IRQL PASSIVE_LEVEL. However, it is safe for minifilter drivers to call this routine from a post-create callback routine, because post-create callback routines are guaranteed to be called at IRQL PASSIVE_LEVEL, in the context of the thread that originated the IRP_MJ_CREATE request.

## See also

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IS_REISSUED_IO](https://learn.microsoft.com/previous-versions/ff544660(v=vs.85))

[FLT_PARAMETERS for IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-create)

[FltReissueSynchronousIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreissuesynchronousio)

[FltSetCallbackDataDirty](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty)

[IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[IoCancelFileOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocancelfileopen)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)