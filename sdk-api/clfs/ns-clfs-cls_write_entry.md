# CLS_WRITE_ENTRY structure

## Description

Contains a user buffer, which is to become part of a log record, and its length. The [ReserveAndAppendLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-reserveandappendlog) function uses **CLFS_WRITE_ENTRY** structures in the routine that appends log records to logs. This routine requires the client to specify a set of structures. **ReserveAndAppendLog** gathers these structures and formats them into a log record in a marshaling buffer, which is eventually flushed to the log.

## Members

### `Buffer`

The log record data buffer.

### `ByteLength`

The length of the log record data buffer, in bytes.

## See also

[ReserveAndAppendLog](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-reserveandappendlog)