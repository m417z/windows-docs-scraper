# ZwSetEaFile function

## Description

**ZwSetEaFile** replaces the extended attributes (EAs) associated with a file with the specified EAs.

## Parameters

### `FileHandle` [in]

The handle for the file on which the operation is to be performed.

### `IoStatusBlock` [out]

A pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and other information about the requested operation.

### `Buffer` [in]

A pointer to a caller-supplied [**FILE_FULL_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)-structured input buffer that contains the new EAs that will replace the EAs currently associated with the file.

### `Length` [in]

Length, in bytes, of the buffer that the **Buffer** parameter points to.

## Return value

**ZwSetEaFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return value | Description |
| ------------ | ----------- |
| STATUS_EA_LIST_INCONSISTENT | The EA list that **Buffer** points to isn't formatted correctly. This is an error code. |
| STATUS_INSUFFICIENT_RESOURCES | There isn't enough memory available to complete the operation. This is an error code. |

## Remarks

**ZwSetEaFile** replaces the EAs associated with **FileHandle** with the EAs in the buffer that **Buffer** points to. The EAs in the buffer must be formatted as a sequence of [**FILE_FULL_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information) structures. **ZwSetEaFile** first [checks that the buffer of EA values is valid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckeabuffervalidity) before replacing the existing EAs.

## See also

[**FILE_FULL_EA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_full_ea_information)

[**IoCheckEaBufferValidity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocheckeabuffervalidity)

[**ZwQueryEaFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryeafile)