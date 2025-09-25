# _CLS_WRITE_ENTRY structure

## Description

The **CLFS_WRITE_ENTRY** structure holds the address and size of a buffer that contains one unit of data to be written to a Common Log File System (CLFS) stream.

## Members

### `Buffer`

A pointer to the buffer that holds the data.

### `ByteLength`

The size, in bytes, of the buffer pointed to by **Buffer**.

## Remarks

CLFS collects the buffers pointed to by several **CLFS_WRITE_ENTRY** structures into a single log record. The log record is then placed in a log I/O block along with other log records. Eventually the log I/O block is flushed to disk.

## See also

[ClfsReserveAndAppendLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreserveandappendlog)

[ClfsReserveAndAppendLogAligned](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreserveandappendlogaligned)