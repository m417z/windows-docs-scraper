## Description

The **FLT_IS_IRP_OPERATION** macro determines whether the given callback data structure represents an I/O request packet (IRP)-based I/O operation.

## Parameters

### `Data`

[in] A pointer to a callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure.

## Remarks

**FLT_IS_IRP_OPERATION** returns a nonzero value if the IRP operation flag is set in the callback data structure. Otherwise, it returns zero.

The **FLT_IS_IRP_OPERATION** macro checks whether the **FLTFL_CALLBACK_DATA_IRP_OPERATION** bit is set in the **Flags** member of the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure that the **Data** parameter points to. Thus, the return type of **FLT_IS_IRP_OPERATION** is of the same type as the **Flags** member.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation)

[**FLT_IS_FS_FILTER_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fs_filter_operation)

[**FLT_IS_REISSUED_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_reissued_io)

[**FLT_IS_SYSTEM_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_system_buffer)