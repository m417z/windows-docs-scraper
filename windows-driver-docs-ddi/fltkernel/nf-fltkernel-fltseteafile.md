# FltSetEaFile function

## Description

**FltSetEaFile** sets extended-attribute (EA) values for a file.

## Parameters

### `Instance` [in]

Opaque instance pointer for the minifilter driver instance that the SetEa operation is to be sent to. The instance must be attached to the volume where the file resides.

### `FileObject` [in]

File object pointer for the file.

### `EaBuffer` [in]

Pointer to a caller-supplied, [FILE_FULL_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)-structured input buffer that contains the extended attribute (EA) values to be set.

### `Length` [in]

Length, in bytes, of the buffer that the *EaBuffer* parameter points to.

## Return value

**FltSetEaFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The instance or volume is being torn down. This is an error code. |

## See also

[FILE_FULL_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)

[FltQueryEaFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryeafile)

[IoCheckEaBufferValidity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckeabuffervalidity)