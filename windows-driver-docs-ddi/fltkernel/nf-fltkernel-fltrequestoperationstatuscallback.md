# FltRequestOperationStatusCallback function

## Description

**FltRequestOperationStatusCallback** returns status information for the given I/O operation.

## Parameters

### `Data` [in]

A pointer to the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the I/O operation. This parameter is required and cannot be **NULL**.

### `CallbackRoutine` [in]

A pointer to a callback routine that the Filter Manager calls after [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) returns. This parameter is required and cannot be **NULL**.

### `RequesterContext` [in, optional]

A context pointer to be passed to the *CallbackRoutine*. This parameter is optional and can be **NULL**.

## Return value

**FltRequestOperationStatusCallback** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The minifilter driver's instance is being torn down. This is an error code. |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltRequestOperationStatusCallback** encountered a pool allocation failure. This is an error code. |
| **STATUS_INVALID_PARAMETER** | **FltRequestOperationStatusCallback** was called from a routine that was not a preoperation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine, or the I/O operation was an IRP_MJ_CLOSE request. This is an error code. |

## Remarks

A minifilter driver can call **FltRequestOperationStatusCallback** for an IRP-based I/O operation to obtain the status value that [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) returned for the operation.

Most minifilter drivers never need to call **FltRequestOperationStatusCallback**. Normally, a minifilter driver only calls this routine to determine whether a requested oplock was granted.

**FltRequestOperationStatusCallback** can only be called from a minifilter driver's preoperation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine.

**FltRequestOperationStatusCallback** can only be called for non-IRP_MJ_CLOSE IRP-based operations. To determine whether the operation is an IRP-based operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

If the IRP-based operation is an IRP_MJ_CLOSE request, STATUS_INVALID_PARAMETER is returned.

**FltRequestOperationStatusCallback** copies the contents of the I/O parameter block ([FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)) to the **Iopb** member of the callback data (FLT_CALLBACK_DATA), and this is the callback data that the Filter Manager will pass to the routine specified in the *CallbackRoutine* parameter. The copied data represents a snapshot of the I/O parameter block at the time that the preoperation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine calls **FltRequestOperationStatusCallback**. If the preoperation callback routine changes the I/O parameter block after calling **FltRequestOperationStatusCallback**, the I/O parameter block that the Filter Manager passes to *CallbackRoutine* will be different from the I/O parameter block that the filter driver passes down the driver stack when it calls [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver).

The following example code from a preoperation callback routine illustrates how this might happen:

```
PFLT_CALLBACK_DATA Data;
PFLT_GET_OPERATION_STATUS_CALLBACK CallbackRoutine;
PVOID RequesterContext;
...
if (iopb->MajorFunction == IRP_MJ_READ) {
    FltRequestOperationStatusCallback (Data, CallbackRoutine, RequesterContext);
 Data->Iopb->Parameters.Read.ReadBuffer = newBuffer;
    ...
}
```

In the example, the read buffer is changed after the call to **FltRequestOperationStatusCallback**, so when the Filter Manager calls *CallbackRoutine*, it will pass in a pointer to the old buffer instead of the new one.

The Filter Manager calls the given *CallbackRoutine* in the context of the originating thread at IRQL <= APC_LEVEL.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[PFLT_GET_OPERATION_STATUS_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_get_operation_status_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)