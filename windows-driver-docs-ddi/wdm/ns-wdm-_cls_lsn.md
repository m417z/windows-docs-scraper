# _CLS_LSN structure

## Description

The **CLFS_LSN** structure identifies an individual record in a Common Log File System (CLFS) stream.

## Members

### `Internal`

A 64-bit value that holds three pieces of information about a log record: container identifier, block offset, and record sequence number.

## Remarks

A container is a contiguous physical disk extent that serves as part of a CLFS log. A given CLFS log has several containers. Each container has several sector-aligned blocks, each of which holds a numbered sequence of records. A record can be identified by the triple (logical container identifier, block offset, record sequence number).

To obtain the container identifier, block offset, and record sequence number from a **CLFS_LSN** structure, call [ClfsLsnContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsncontainer), [ClfsLsnBlockOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnblockoffset), and [ClfsLsnRecordSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnrecordsequence).