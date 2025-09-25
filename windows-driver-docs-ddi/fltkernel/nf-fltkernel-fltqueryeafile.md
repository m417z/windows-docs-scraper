# FltQueryEaFile function

## Description

**FltQueryEaFile** returns information about extended-attribute (EA) values for a file.

## Parameters

### `Instance` [in]

Opaque instance pointer for the minifilter driver instance that the *QueryEa* operation is to be sent to. The instance must be attached to the volume where the file resides.

### `FileObject` [in]

File object pointer for the file.

### `ReturnedEaData` [out]

Pointer to a caller-supplied [FILE_FULL_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)-structured input buffer where the extended attribute values are to be returned.

### `Length` [in]

Length, in bytes, of the buffer that the *ReturnedEaData* parameter points to.

### `ReturnSingleEntry` [in]

Set to **TRUE** if **FltQueryEaFile** should return only the first entry that is found.

### `EaList` [in, optional]

Pointer to a caller-supplied [FILE_GET_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_ea_information)-structured input buffer specifying the extended attributes to be queried. This parameter is optional and can be **NULL**.

### `EaListLength` [in]

Length, in bytes, of the buffer that the *EaList* parameter points to.

### `EaIndex` [in, optional]

Index of the entry at which to begin scanning the file's extended-attribute list. This parameter is ignored if the *EaList* parameter points to a nonempty list. This parameter is optional and can be **NULL**.

### `RestartScan` [in]

Set to **TRUE** if **FltQueryEaFile** should begin the scan at the first entry in the file's extended-attribute list. If this parameter is not set to **TRUE**, the scan is resumed from a previous call to **FltQueryEaFile**.

### `LengthReturned` [out, optional]

Pointer to a caller-allocated variable that receives the size, in bytes, of the information returned in the *ReturnedEaData* buffer. This parameter is optional and can be **NULL**.

## Return value

**FltQueryEaFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_EAS_NOT_SUPPORTED** | The file system does not support extended attributes. This is an error code. |
| **STATUS_FLT_DELETING_OBJECT** | The instance or volume is being torn down. This is an error code. |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltQueryEaFile** encountered a pool allocation failure. This is an error code. |

## See also

[FILE_FULL_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)

[FILE_GET_EA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_ea_information)

[FltSetEaFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltseteafile)

[IoCheckEaBufferValidity](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckeabuffervalidity)