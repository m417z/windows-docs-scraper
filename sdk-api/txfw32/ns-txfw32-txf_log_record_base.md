# TXF_LOG_RECORD_BASE structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains the basic record information.

## Members

### `Version`

The version identifier for the replication record.

### `RecordType`

The record type. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TXF_LOG_RECORD_TYPE_AFFECTED_FILE**<br><br>4 | The record is a [TXF_LOG_RECORD_AFFECTED_FILE](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_log_record_affected_file) structure. |
| **TXF_LOG_RECORD_TYPE_TRUNCATE**<br><br>2 | The record is a [TXF_LOG_RECORD_TRUNCATE](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_log_record_truncate) structure. |
| **TXF_LOG_RECORD_TYPE_WRITE**<br><br>1 | The record is a [TXF_LOG_RECORD_WRITE](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_log_record_write) structure. |

### `RecordLength`

The length of this record, in bytes.

## See also

[TXF_LOG_RECORD_AFFECTED_FILE](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_log_record_affected_file)

[TXF_LOG_RECORD_TRUNCATE](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_log_record_truncate)

[TXF_LOG_RECORD_WRITE](https://learn.microsoft.com/windows/desktop/api/txfw32/ns-txfw32-txf_log_record_write)

[TxfLogReadRecords](https://learn.microsoft.com/windows/desktop/api/txfw32/nf-txfw32-txflogreadrecords)