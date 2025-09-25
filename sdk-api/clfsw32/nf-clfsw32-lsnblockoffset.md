# LsnBlockOffset function

## Description

Returns the sector-aligned block offset that is contained in the specified LSN.

## Parameters

### `plsn` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_lsn) structure from which the block offset is to be retrieved.

## Return value

**LsnBlockOffset** returns the block offset that is contained in *plsn*.

## Remarks

The block offset that is returned by this function is a multiple of the sector size on the stable storage medium. For example, if the sector size is 1024 bytes, the block offset is a multiple of 1024.

#### Examples

For an example that uses this function, see [Enumerating Log Containers](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/enumerating-log-containers).

## See also

[LsnContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsncontainer)

[LsnCreate](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsncreate)

[LsnRecordSequence](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-lsnrecordsequence)