# LsnContainer function

## Description

Retrieves the logical container ID that is contained in a specified LSN.

## Parameters

### `plsn` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure from which the container ID is to be retrieved.

## Return value

This function returns the logical container ID that is contained in *plsn*. The logical container ID is not necessarily the same as the ID of the physical container on stable storage.

## See also

[LsnBlockOffset](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsnblockoffset)

[LsnCreate](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsncreate)

[LsnRecordSequence](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsnrecordsequence)