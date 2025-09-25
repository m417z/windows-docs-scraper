# ClfsLsnContainer function

## Description

The **ClfsLsnContainer** routine returns the logical container identifier contained in a specified LSN.

## Parameters

### `plsn` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure from which the container identifier is retrieved.

## Return value

**ClfsLsnContainer** returns the logical container identifier contained in the LSN that is supplied by the caller. The logical container identifier is not necessarily the same as the identifier of the physical container on stable storage.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsLsnBlockOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnblockoffset)

[ClfsLsnCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsncreate)

[ClfsLsnRecordSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfslsnrecordsequence)