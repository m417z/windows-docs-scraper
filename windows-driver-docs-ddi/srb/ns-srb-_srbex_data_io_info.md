# _SRBEX_DATA_IO_INFO structure (srb.h)

## Description

The **SRBEX_DATA_IO_INFO** structure contains additional information related to a read or write request in an extended SRB.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Type`

Data type indicator for the bidirectional extended SRB data structure. Set to **SrbExDataTypeIoInfo**.

### `Length`

Length of the data in this structure, in bytes, starting with the **Flags** member. Set to SRBEX_DATA_IO_INFO_LENGTH.

### `Flags`

Flags set for handling the request. May be a combination of these values:

| Value | Meaning |
| --- | --- |
| **REQUEST_INFO_NO_CACHE_FLAG** | Non-cached writes are specified for this request. |
| **REQUEST_INFO_PAGING_IO_FLAG** | Paging IO is specified for this request. |
| **REQUEST_INFO_SEQUENTIAL_IO_FLAG** | Reads or writes are sequential. |
| **REQUEST_INFO_TEMPORARY_FLAG** | The file for this request is temporary. |
| **REQUEST_INFO_WRITE_THROUGH_FLAG** | No system buffering for the request. |
| **REQUEST_INFO_HYBRID_WRITE_THROUGH_FLAG** | Perform a hybrid cache write through to disk<br><br>This flag is available starting with Windows 8.1 Update. |
| **REQUEST_INFO_VALID_CACHEPRIORITY_FLAG** | The hybrid cache priority level is valid for this I/O.<br><br>This flag is available starting with Windows 8.1 Update. |

### `Key`

A tag value to identify a block of data transferred.

### `RWLength`

The length, in bytes of the data to transfer.

### `IsWriteRequest`

TRUE if the I/O operation in the SRB is a write request. Otherwise, FALSE; the I/O operation is a read request.

### `CachePriority`

Priority level for a hybrid cache read or write.

This member is valid starting with Windows 8.1 Update.

### `Reserved`

This member is reserved. Set to 0.

### `Reserved1`

This member is reserved. Set to 0.

This member is present starting with Windows 8.1 Update.

## See also

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)