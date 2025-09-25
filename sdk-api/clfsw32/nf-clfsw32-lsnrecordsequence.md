# LsnRecordSequence function

## Description

Retrieves the record sequence number that is contained in a specified LSN.

## Parameters

### `plsn` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure from which the record sequence number is to be retrieved.

## Return value

The record sequence number that is contained in *plsn*.

## See also

[LsnBlockOffset](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsnblockoffset)

[LsnContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsncontainer)

[LsnCreate](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsncreate)