## Description

The **FLT_IS_REISSUED_IO** macro determines whether the given callback data structure represents a reissued I/O operation.

## Parameters

### `Data`

[in] Pointer to the callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for an I/O operation.

## Remarks

**FLT_IS_REISSUED_IO** returns TRUE if the reissued I/O operation flag is set in the callback data structure; FALSE otherwise.

The **FLT_IS_REISSUED_IO** macro checks whether the FLTFL_CALLBACK_DATA_REISSUED_IO flag is set in the **Flags** member of the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure that the **Data** parameter points to. This flag is set by [**FltReissueSynchronousIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreissuesynchronousio) when an I/O operation is reissued. This flag is valid only for IRP-based I/O operations. To determine whether an I/O operation is IRP-based, use the [**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_irp_operation) macro.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation)

[**FLT_IS_FS_FILTER_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fs_filter_operation)

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_irp_operation)

[**FLT_IS_SYSTEM_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_system_buffer)

[**FltIsOperationSynchronous**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltisoperationsynchronous)

[**FltReissueSynchronousIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreissuesynchronousio)