## Description

The **FLT_IS_FS_FILTER_OPERATION** macro determines whether the given callback data structure represents a file system filter (FSFilter) callback operation.

## Parameters

### `Data`

[in] A pointer to a callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure.

## Remarks

**FLT_IS_FS_FILTER_OPERATION** returns a nonzero value if the **FLTFL_CALLBACK_DATA_FS_FILTER_OPERATION** flag is set in the callback data structure. Otherwise, it returns zero.

The **FLT_IS_FS_FILTER_OPERATION** macro checks whether the **FLTFL_CALLBACK_DATA_FS_FILTER_OPERATION** bit is set in the **Flags** member of the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure that the **Data** parameter points to. If this flag is set, the callback data structure represents one of the following file system filter (FSFilter) callback operations:

* IRP_MJ_ACQUIRE_FOR_CC_FLUSH
* IRP_MJ_ACQUIRE_FOR_MOD_WRITE
* IRP_MJ_ACQUIRE_FOR_SECTION_SYNCHRONIZATION
* IRP_MJ_RELEASE_FOR_CC_FLUSH
* IRP_MJ_RELEASE_FOR_MOD_WRITE
* IRP_MJ_RELEASE_FOR_SECTION_SYNCHRONIZATION

For information about specific FSFilter callback operations, see the reference entry for [**FsRtlRegisterFileSystemFilterCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlregisterfilesystemfiltercallbacks). Note that in the legacy filter driver model, filters used **FsRtlRegisterFileSystemFilterCallbacks** to register callback functions for various FSFilter callback operations. However, **FsRtlRegisterFileSystemFilterCallbacks** is not used in the minifilter driver model, and minifilter drivers should never call it.

The return type of **FLT_IS_FS_FILTER_OPERATION** is of the same type as the **Flags** member of the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation)

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_irp_operation)

[**FLT_IS_REISSUED_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_reissued_io)

[**FLT_IS_SYSTEM_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_system_buffer)

[**FsRtlRegisterFileSystemFilterCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlregisterfilesystemfiltercallbacks)