# ZwQueryEaFile function

## Description

**ZwQueryEaFile** routine returns the extended attributes (EAs) associated with the specified file.

## Parameters

### `FileHandle` [in]

The handle for the file on which the operation is to be performed.

### `IoStatusBlock` [out]

A pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and other information about the requested operation.

### `Buffer` [out]

A pointer to a caller-supplied [**FILE_FULL_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)-structured output buffer in which to return the file's EAs.

### `Length` [in]

The length, in bytes, of the buffer that **Buffer** points to.

### `ReturnSingleEntry` [in]

Set to TRUE if **ZwQueryEaFile** should return only the first entry that it finds.

### `EaList` [in, optional]

A pointer to a caller-supplied [**FILE_GET_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_ea_information)-structured input buffer that specifies the EAs to be queried. This parameter is optional and can be NULL.

### `EaListLength` [in]

The length, in bytes, of the buffer that the **EaList** parameter points to.

### `EaIndex` [in, optional]

The index of the entry at which scanning the file's EA list should begin. This parameter is ignored if **EaList** points to a nonempty list. This parameter is optional and can be NULL.

### `RestartScan` [in]

Set to TRUE if **ZwQueryEaFile** should begin the scan at the first entry in the file's EA list. If this parameter is set to FALSE, the routine resumes the scan from a previous call to **ZwQueryEaFile**.

## Return value

**ZwQueryEaFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return value | Description |
| ------------ | ----------- |
| STATUS_EAS_NOT_SUPPORTED | The file system doesn't support EAs. This is an error code. |
| STATUS_INSUFFICIENT_RESOURCES | There isn't enough memory available to complete the operation. This is an error code. |
| STATUS_EA_LIST_INCONSISTENT | The **EaList** parameter isn't formatted correctly. This is an error code. |

## Remarks

The amount of information that **ZwQueryEaFile** returns is based on the size of the EAs and the size of the buffer that **Buffer** points to. That is, either all of the requested EAs are written to the buffer, or the buffer is filled with as many complete EAs if it's not large enough to contain all the EAs. Only complete EAs are written to the buffer; no partial EAs will ever be returned.

## See also

[**FILE_FULL_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)

[**FILE_GET_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_ea_information)

[**ZwSetEaFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwseteafile)