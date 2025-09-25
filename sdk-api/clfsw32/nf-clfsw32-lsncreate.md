# LsnCreate function

## Description

Creates a log sequence number (LSN), given a container ID, a block offset, and a record sequence number.

## Parameters

### `cidContainer` [in]

The container ID. This value must be an integer between 0x0 and 0xFFFFFFFF.

### `offBlock` [in]

The block offset. This value must be a multiple of 512.

### `cRecord` [in]

The record sequence number. This value must be an integer between 0 - 511.

## Return value

Returns a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure that represents the container ID, block offset, and record sequence number that is supplied by the caller.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn)

[LsnBlockOffset](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsnblockoffset)

[LsnContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsncontainer)

[LsnRecordSequence](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsnrecordsequence)