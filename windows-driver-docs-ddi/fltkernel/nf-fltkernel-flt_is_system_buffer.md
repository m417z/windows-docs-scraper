## Description

The **FLT_IS_SYSTEM_BUFFER** macro tests the system buffer flag in a callback data structure.

## Parameters

### `Data`

[in] Pointer to a callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure.

## Remarks

**FLT_IS_SYSTEM_BUFFER** returns TRUE if the system buffer flag is set in the callback data structure; FALSE otherwise.

The **FLT_IS_SYSTEM_BUFFER** macro checks whether the system buffer flag (**FLTFL_CALLBACK_DATA_SYSTEM_BUFFER**) is set in a callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure.

The system buffer flag is set in the callback data structure for an I/O operation if the buffer for the operation is allocated from nonpaged pool. If this flag is set, minifilter drivers can assume that the buffer is already locked down and can be accessed safely.

Note that minifilter drivers must never set the system buffer flag.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation)

[**FLT_IS_FS_FILTER_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fs_filter_operation)

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_irp_operation)

[**FLT_IS_REISSUED_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_reissued_io)