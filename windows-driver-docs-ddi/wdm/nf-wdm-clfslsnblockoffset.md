# ClfsLsnBlockOffset function

## Description

The **ClfsLsnBlockOffset** routine returns the sector-aligned block offset contained in a specified LSN.

## Parameters

### `plsn` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure from which the block offset is retrieved.

## Return value

**ClfsLsnBlockOffset** returns the block offset contained in the LSN that is supplied by the caller.

## Remarks

The block offset returned by this routine is a multiple of the sector size on the stable storage medium. For example, if the sector size is 1024 bytes, the block offset is a multiple of 1024.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsLsnContainer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsncontainer)

[ClfsLsnCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsncreate)

[ClfsLsnRecordSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnrecordsequence)