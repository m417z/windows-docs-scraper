# TXF_LOG_RECORD_AFFECTED_FILE structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains information for a file that was affected by a transaction.

## Members

### `Version`

The version identifier for the replication record.

### `RecordLength`

The length of this record, in bytes.

### `Flags`

This member is reserved.

### `TxfFileId`

The TxF file identifier for the file associated with this record. For more information, see [TXF_ID](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_id).

### `KtmGuid`

The KTM transaction GUID for this update.

### `FileNameLength`

The length of the file name, in bytes.

### `FileNameByteOffsetInStructure`

The offset of the file name from the beginning of this record.

## See also

[TXF_ID](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_id)

[TXF_LOG_RECORD_BASE](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_log_record_base)