# PDH_RAW_LOG_RECORD structure

## Description

The
**PDH_RAW_LOG_RECORD** structure contains information about a binary trace log file record.

## Members

### `dwStructureSize`

Size of this structure, in bytes. The size includes this structure and the **RawBytes** appended to the end of this structure.

### `dwRecordType`

Type of record. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PDH_LOG_TYPE_BINARY** | A binary trace format record |
| **PDH_LOG_TYPE_CSV** | A comma-separated-value format record |
| **PDH_LOG_TYPE_PERFMON** | A Perfmon format record |
| **PDH_LOG_TYPE_SQL** | A SQL format record |
| **PDH_LOG_TYPE_TSV** | A tab-separated-value format record |

### `dwItems`

Size of the **RawBytes** data.

### `RawBytes`

Binary record.

## See also

[PdhReadRawLogRecord](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhreadrawlogrecord)